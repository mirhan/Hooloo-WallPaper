
#include <stdio.h>
#include <signal.h>

#define MAXARGS 20
#define ARGLEN 100

int main()
{
    char argbuf[ARGLEN];
    int numargs = 0;
    while (numargs < MAXARGS) {
        printf("Arg[%d]?:", numargs);
        if (fgets(argbuf, ARGLEN, stdin) && *argbuf != '\n') {
            arglist[numargs++] = makestring(argbuf);
        }
    }
}
