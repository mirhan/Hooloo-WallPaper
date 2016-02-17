#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>


#define NAME_MAX    255 // TODO
#define PATH_NAME_MAX    255 // TODO
#define SORT_MAX    1000

int should_be_list(char* d_name, int is_list_all)
{
    if (!is_list_all && (strcmp(d_name, ".") == 0 || strcmp(d_name, "..") == 0)) {
        return 0;
    }
    return 1;
}


char *mode_to_str(int mode)
{
    static char mode_str[sizeof("----------")];
    strcpy(mode_str, "----------");

    if (S_ISDIR(mode)) mode_str[0] = 'd'; // dircectory
    if (S_ISCHR(mode)) mode_str[0] = 'c'; // char device
    if (S_ISBLK(mode)) mode_str[0] = 'b'; // block device

    if(mode & S_IRUSR) mode_str[1] = 'r';
    if(mode & S_IWUSR) mode_str[2] = 'w';
    if(mode & S_IXUSR) mode_str[3] = 'x';

    if(mode & S_IRGRP) mode_str[4] = 'r';
    if(mode & S_IWGRP) mode_str[5] = 'w';
    if(mode & S_IXGRP) mode_str[6] = 'x';

    if(mode & S_IROTH) mode_str[7] = 'r';
    if(mode & S_IWOTH) mode_str[8] = 'w';
    if(mode & S_IXOTH) mode_str[9] = 'x';

    return mode_str;
}


char* uid_to_name(uid_t uid) // 10
{
    struct passwd *pw_ptr = getpwuid(uid);
    static char uid_name[10];
    if (pw_ptr == NULL) {
        sprintf(uid_name, "%d", uid);
        return uid_name;
    } else {
//        strncpy(uid_name, pw_ptr->pw_name, sizeof(uid_name));
        return pw_ptr->pw_name;
    }
}

char* gid_to_name(gid_t gid) // 10
{
    struct group *group_p = getgrgid(gid);
    static char gid_name[10];
    if (group_p == NULL) {
        sprintf(gid_name, "%d", gid);
        return gid_name;
    } else {
//        strncpy(gid_name, group_p->gr_name, sizeof(gid_name));
        return group_p->gr_name;
    }
}

void dir_combine(char* dirname, char* filename, char* fullname) // PATH_NAME_MAX
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

void show_stat_info(char* dirname, char* filename)
{
    char fullname[PATH_NAME_MAX];
    dir_combine(dirname, filename, fullname);

    struct stat stat_info;
    if (stat(fullname, &stat_info) == -1) {
        perror("show_stat_info failed");
        fprintf(stderr, "filename = %s\n", fullname);
        return;
    }

    printf("%s", mode_to_str(stat_info.st_mode));
    printf("%2d", stat_info.st_nlink);
    printf(" %s", uid_to_name(stat_info.st_uid));
    printf(" %s", gid_to_name(stat_info.st_gid));
    printf("%7ld", stat_info.st_size);
    printf(" %.12s", ctime(&stat_info.st_mtime) + 4);
    printf(" %s\n", filename);
}

void do_ls(char *dirname, int is_list_all, int is_long_list, int is_recursive)
{
    DIR * dirp = opendir(dirname);
    if (dirp == NULL) {
        fprintf(stderr, "ls1: cannot open %s.\n", dirname);
        return;
    }

    char filename_arr[SORT_MAX][NAME_MAX];
    memset(filename_arr, '\0', sizeof(filename_arr));
    int cnt = 0;

    struct dirent * direntp = readdir(dirp);
    while (direntp != NULL) {
        if (should_be_list(direntp->d_name, is_list_all)) {
            strncpy(filename_arr[cnt], direntp->d_name, NAME_MAX);
            cnt++;
        }
        direntp = readdir(dirp);
    }

    (void) closedir(dirp);


    qsort(filename_arr, cnt, sizeof(filename_arr[SORT_MAX]), strcmp);
    int i;
    for (i = 0; i < cnt; i++) {
        struct stat stat_info;
        char fullname[PATH_NAME_MAX];
        dir_combine(dirname, filename_arr[i], fullname);
        if (stat(fullname, &stat_info) == -1) {
            fprintf(stderr, "stat file error: %s\n", fullname);
            continue;
        }

        if (is_long_list) {
            show_stat_info(dirname, filename_arr[i]);
        } else {
            printf("%s", filename_arr[i]);

            if (i == cnt - 1) {
                printf("\n");
            } else {
                printf("  ");
            }
        }

        if (is_recursive) {
            if (S_ISDIR(stat_info.st_mode)) {
                do_ls(fullname, is_list_all, is_long_list, is_recursive);
            }
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    int is_list_all = 0;
    int is_long_list = 0;
    int is_recursive = 0;
    int effective_cnt = argc;
    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            is_list_all = 1;
            effective_cnt--;
        } else if (strcmp(argv[i], "-l") == 0) {
            is_long_list = 1;
            effective_cnt--;
        } else if (strcmp(argv[i], "-R") == 0) {
            is_recursive = 1;
            effective_cnt--;
        }
    }

    if (effective_cnt == 1) {
        do_ls(".", is_list_all, is_long_list, is_recursive);
    } else {
        for (i = 1; i < argc; i++) {
            if (argv[i][0] != '-') {
                do_ls(argv[i], is_list_all, is_long_list, is_recursive);
            }
        }
    }
}
