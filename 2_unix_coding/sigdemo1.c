#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define ENTER 10

void say_ouch(int signum);
void ask_if_exit(int signum);

static max_call_say_ouch_cnt = 0;

int main(int argc, char* argv[])
{
    if (argc > 2) {
        exit(1);
    } else if (argc == 2) {
        max_call_say_ouch_cnt = atoi(argv[1]);
    }

    signal(SIGINT, ask_if_exit);

    int i;
    for (i = 0; i < 5; i++) {
        printf("hello!\n");
        sleep(5);
    }
}

void ask_if_exit(int signum)
{
    printf("Interrupted! OK to quit (y/n)?\n");

    while (1) {
        int c = getchar();
//        printf("%d\n", c );
        if (c != ENTER) {
            if (tolower(c) == 'y') {
                exit(1);
            } else if (tolower(c) == 'n') {
                break;
            }
            printf("Interrupted! OK to quit (y/n)?\n");
        }
    }
}


void say_ouch(int signum)
{
    static call_cnt = 0;
    call_cnt++;
    printf("OUCH");

    int i;
    for (i = 0; i< call_cnt;i++) {
        printf("!");
    }

    printf("\n");

    if (max_call_say_ouch_cnt != 0) {
        if (call_cnt == max_call_say_ouch_cnt) {
            exit(1);
        }
    }
}
