#include <stdio.h>
#include <ctype.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"


void set_cr_noecho_mode();

int main (int argc, char *argv[]) {

    struct termios original_mod;
    tcgetattr(0, &original_mod);

    set_cr_noecho_mode();

    int response = get_response(QUESTION);

    printf("response = %d\n", response);

    tcsetattr(0, TCSANOW, &original_mod);
    return 0;
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

int get_response(char* question)
{
    printf("%s (y/n)?\n", question);

    int c;
    c = getchar();

    while (1) {
        switch (c) {
        case 'y':
        case 'Y':
            return 0;
        case 'n':
        case 'N':
        case EOF:
            return 1;
        default:
            break;
        }

        c = getchar();
    }
}
