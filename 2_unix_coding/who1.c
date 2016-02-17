#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>


void show_info(struct utmp *utbufp)
{
    printf("%-8.8s", utbufp->ut_name);
    printf(" ");

    printf("%-8.8s", utbufp->ut_line);
    printf(" ");

    printf("%10ld", utbufp->ut_time);
    printf(" ");

    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct utmp current_record;
    int utmpfd;

    int reclen = sizeof(current_record);

    // printf("ha? \n");
    utmpfd = open(UTMP_FILE, O_RDONLY);
    // printf("open \n");
    if (utmpfd == -1)
    {
        // printf("perror \n");
        perror(UTMP_FILE);
        exit(1);
    }


    int ret = read(utmpfd, &current_record, reclen);
    // printf("read1 \n");
    while (ret == reclen)
    {
        // printf("show_info \n");
        show_info(&current_record);
        ret = read(utmpfd, &current_record, reclen);
    }

    close(utmpfd);

    return 0;
}
