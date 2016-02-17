#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void new_op(int, siginfo_t*, void*);
int main(int argc, char**argv)
{
    int fd1= open("han.log", O_WRONLY);
//    int fd2= open("han.log", O_WRONLY);
//    int fd3= open("han.log", O_RDWR);

    char buf1[20];
    lseek(fd1, 20000, SEEK_END);
//    int cnt1 = read(fd1, buf1, sizeof(buf1));
    int cnt1 = write(fd1, "hello", sizeof("hello"));
//    printf("%s", buf1);

//    int cnt2 = write(fd2, "testing 123...", sizeof("testing 123..."));
//
//    char buf3[20];
//    int cnt3 = read(fd3, buf3, sizeof(buf3));
//    printf("3: %s\n", buf3);

}
