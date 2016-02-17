#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

#define BUFF_SIZE (2048)
#define COPYMODE (0644)

int is_directory(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

#define  PATH_NAME_MAX 255
void dir_combine(const char* dirname, const char* filename, char* fullname) // PATH_NAME_MAX
{
    memset(fullname, '\0', PATH_NAME_MAX);

    strcpy(fullname, dirname);

    int dirlen = strlen(dirname);
    if (fullname[dirlen - 1] != '/') {
        fullname[dirlen] = '/';
        fullname[dirlen + 1] = '\0';
    }

    strcat(fullname, filename);
}

void do_cp(const char *source,const char *target)
{
    char target_fullname[PATH_NAME_MAX];
    memset(target_fullname, '\0', sizeof target_fullname);

    struct stat target_path_stat;
    if (stat(target, &target_path_stat) == 0 && S_ISDIR(target_path_stat.st_mode)) {
        dir_combine(target, source, target_fullname);
        printf("combine new file: %s \n.", target_fullname);
    } else {
        strcpy(target_fullname, target);
    }

    int fd_s = open(source, O_RDONLY);
    if (fd_s == -1) {
        fprintf(stderr, "open err.\n");
        exit(1);
    }

    int fd_d = creat(target_fullname, COPYMODE);
    if (fd_d == -1) {
        fprintf(stderr, "create err: %s.\n", target_fullname);
        exit(1);
    }

    char buf[BUFF_SIZE];

    int r_char = read(fd_s, buf, sizeof(buf));
    while (r_char > 0) {
        int w_char = write(fd_d, buf, r_char);
        if (w_char == r_char) {
            r_char = read(fd_s, buf, sizeof(buf));
        } else {
            fprintf(stderr, "write err.\n");
            exit(1);
        }
    }

    if (close(fd_s) == -1|| close(fd_d) == -1) {
        fprintf(stderr, "close err.\n");
        exit(1);
    }

    struct stat src_path_stat;
    if (stat(source, &src_path_stat) == -1) {
        fprintf(stderr, "do_cp stat src err: %s\n", source);
        perror("");
        return;
    }

    struct utimbuf target_times;
    target_times.actime = src_path_stat.st_atime;
    target_times.modtime = src_path_stat.st_mtime;

    if (utime(target_fullname, &target_times) == -1) {
        perror("do_cp utime err:");
        return;
    }

    return;
}

void do_cp_dir(const char *source_dir,const char *target_dir)
{
    struct stat target_stat_info;
    if (stat(target_dir, &target_stat_info) == -1){
        struct stat source_stat_info;
        if (stat(source_dir, &source_stat_info) == -1) {
            fprintf(stderr, "do_cp_dir failed 1 '%s': ", source_dir);
            perror("");
            return;
        }

        if (mkdir(target_dir, source_stat_info.st_mode) == -1) {
            perror("mkdir failed.");
            exit(1);
        }
    }
//    printf("do_cp_dir path: %s -> %s \n.", source_dir, target_dir);
    DIR * src_dirp = opendir(source_dir);
    if (src_dirp == NULL) {
        fprintf(stderr, "ls1: cannot open %s.\n", source_dir);
        return;
    }

    struct dirent * src_direntp = readdir(src_dirp);
    while (src_direntp != NULL) {

        char new_dir[PATH_NAME_MAX];
        memset(new_dir, '\0', sizeof(new_dir));
        dir_combine(source_dir, src_direntp->d_name, new_dir);

        struct stat source_stat_info;
        if (stat(new_dir, &source_stat_info) == -1) {
            fprintf(stderr, "do_cp_dir failed '%s': ", new_dir);
            perror("");
            break;
        } else if (strcmp(src_direntp->d_name, ".") == 0 || strcmp(src_direntp->d_name, "..") == 0) {
            // do nothing
        } else {
            if (S_ISREG(source_stat_info.st_mode)) {
                do_cp(new_dir, target_dir);
            } else {
                do_cp_dir(new_dir, target_dir);
            }
        }

        src_direntp = readdir(src_dirp);
    }

    (void) closedir(src_dirp);
    return;
}

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usa:%s, source des.\n", *argv);
        exit(1);
    }

    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "cp: `%s' and `%s' are the same file\n", argv[1], argv[2]);
        exit(1);
    }

    struct stat src_path_stat;

    const char* source = argv[1];
    const char* target = argv[2];

    if (stat(source, &src_path_stat) == -1) {
        fprintf(stderr, "cp: cannot stat '%s': ", source);
        perror("");
        exit(1);
    }

    if (S_ISDIR(src_path_stat.st_mode)) {
        struct stat target_path_stat;
        if (stat(target, &target_path_stat) != -1 && S_ISREG(target_path_stat.st_mode)) {
            fprintf(stderr, "cp: omitting directory '%s'\n", source);
            exit(1);
        }

        do_cp_dir(source, target);
    } else {
        do_cp(source, target);
    }

    return 0;
}
