#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>


void show_info(struct utmp *utbufp)
{
    printf("%-8.8s", utbufp->ut_name);
    printf(" ");

    printf("%-8.8s", utbufp->ut_line);
    printf(" ");

    printf("%12.12s", ctime((const time_t *)&utbufp->ut_time) + 4);
    printf(" ");

    printf("\n");
}

#define UTSIZE (sizeof(struct utmp))
#define NRECS (16)

char utmpbuf[UTSIZE * NRECS];
int cur_rec;
int total_rec;
int fd_utmp = -1;

int utmp_open(const char *filename)
{
    cur_rec = 0;
    total_rec = 0;
    fd_utmp = open(filename, O_RDONLY);
    return fd_utmp;
}

struct utmp* utmp_next()
{
    if (fd_utmp == -1) {
        return NULL;
    }

    if (cur_rec == total_rec) {
        int amt = read(fd_utmp, utmpbuf, sizeof(utmpbuf));
        if (amt == 0) {
            return NULL;
        }

        total_rec = amt / UTSIZE;
        cur_rec = 0;
    }

    if (cur_rec < total_rec) {
        struct utmp* recp = (struct utmp*) &utmpbuf[cur_rec * UTSIZE];
        cur_rec++;
        return recp;
    }

    return NULL;
}

int utmp_close()
{
    if (fd_utmp != -1) {
        return close(fd_utmp);
    }
}

int main(int argc, char const *argv[])
{
    struct utmp current_record;
    int utmpfd;

    int reclen = sizeof(current_record);

    utmpfd = utmp_open(UTMP_FILE);
    if (utmpfd == -1)
    {
        perror(UTMP_FILE);
        exit(1);
    }

    struct utmp* ret = utmp_next();
    while (ret != NULL)
    {
        if (ret->ut_type == USER_PROCESS) {
            show_info(ret);
        }
        ret = utmp_next();
    }

    utmp_close(utmpfd);

    return 0;
}
