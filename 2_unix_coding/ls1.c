#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define NAME_MAX    255
#define SORT_MAX    50

int should_be_list(char* d_name, int is_list_all)
{
    if (!is_list_all && (strcmp(d_name, ".") == 0 || strcmp(d_name, "..") == 0)) {
        return 0;
    }
    return 1;
}

void do_ls(char *dirname, int is_list_all)
{
    DIR * dirp = opendir(dirname);
    if (dirp == NULL) {
        fprintf(stderr, "ls1: cannot open %s.\n", dirname);
        return;
    }

    char filename_arr[SORT_MAX][NAME_MAX];
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
        if (i == cnt - 1) {
            printf("%s\n", filename_arr[i]);
        } else {
            printf("%s  ", filename_arr[i]);
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    int is_list_all = 0;
    int effective_cnt = argc;
    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            is_list_all = 1;
            effective_cnt--;
            break;
        }
    }

    if (effective_cnt == 1) {
        do_ls(".", is_list_all);
    } else {
        for (i = 1; i < argc; i++) {
            if (argv[i][0] != '-') {
                do_ls(argv[i], is_list_all);
            }
        }
    }
}
