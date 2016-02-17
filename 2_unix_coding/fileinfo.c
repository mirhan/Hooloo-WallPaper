#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>


char *mode2str(int mode, char* str)
{
    strcpy(str, "----------");
    if (S_ISDIR(mode)) str[0] = 'd';
    if (S_ISCHR(mode)) str[0] = 'c';
    if (S_ISBLK(mode)) str[0] = 'b';
}

void show_stat_info(char* filename)
{
    struct stat the_buf;
    if ( stat (filename, &the_buf) == -1) {
        return;
    }

    printf("st_mode:  %o\n", the_buf.st_mode);
    printf("st_nlink: %d\n", the_buf.st_nlink);
    printf("st_uid:   %d\n", the_buf.st_uid);
    printf("st_uid:   %d\n", the_buf.st_gid);
    printf("st_size:  %d\n", the_buf.st_size);
    printf("st_mtime: %d\n", the_buf.st_mtime);
    printf("filename: %s\n", filename);
}


int main(int argc, char *argv[])
{
    if (argc != 1) {
        show_stat_info(argv[1]);
    }
    return 0;
}
