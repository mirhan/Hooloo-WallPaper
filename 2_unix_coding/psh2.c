
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#define MAXARGS 20
#define ARGLEN 100

char* makestring(char* buf);
void execute(char *arglist[]);

int main()
{
    char argbuf[ARGLEN];
    char *arglist[MAXARGS + 1];

    int numargs = 0;
    while (numargs < MAXARGS) {
        printf("Arg[%d]?:", numargs);
        if (fgets(argbuf, ARGLEN, stdin) && *argbuf != '\n') {
            argbuf[strlen(argbuf) - 1] = '\0'; // trim newline
            arglist[numargs++] = makestring(argbuf); // TODO
        } else {
            if (numargs > 0) {
                arglist[numargs] = NULL;
                execute(arglist);
                numargs = 0;
            }
        }
    }

    return 0;
}

char* makestring(char* buf)
{
    char *cp = malloc(strlen(buf) + 1);
    if (cp == NULL) {
        fprintf(stderr, "no memory\n");
        exit(1);
    }

    strcpy(cp, buf);

    return cp;
}

void execute(char *arglist[])
{
    int pid = fork();
    if (pid == -1) {
        perror("fork failed.");
        exit(1);
    } else if (pid == 0) {
        execvp(arglist[0], arglist);
        perror("execvp failed."); // WHY?!
        exit(1);
    } else {
        int exitstatus;
        while(wait(&exitstatus) != pid); // try what you think

        printf("exitstatus %d, %d\n", exitstatus>>8, exitstatus&0377);
    }
}
