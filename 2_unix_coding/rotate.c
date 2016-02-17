#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <termios.h>

void set_cr_noecho_mode();

#define BACKSPACE 8

int main (int argc, char *argv[]) {

    signal(SIGINT, SIG_IGN);

    struct termios original_mode;
    tcgetattr(0, &original_mode);

    set_cr_noecho_mode();

    int c;
    c = getchar();
    while (c != EOF) {
        if (c == 'Q') {
            break;
//        } else if (c == 'z') {
//            c = 'a';
        } else if (c == BACKSPACE) {
            printf("\b ");
        }
//        else if (islower(c)) {
//            c++;
//        }

        putchar(c);
        c = getchar();
    }

    tcsetattr(0, TCSANOW, &original_mode);
}



void set_cr_noecho_mode()
{
    struct termios ttystates;
    tcgetattr(0, &ttystates);

    ttystates.c_lflag &= ~ICANON;
    ttystates.c_lflag &= ~ECHO;
    ttystates.c_cc[VMIN] = 1;

    tcsetattr(0, TCSANOW, &ttystates);
}
