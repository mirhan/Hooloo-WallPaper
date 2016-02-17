#include <stdio.h>
#include <ctype.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>

#define QUESTION "Do you want another transaction"
#define MAX_TRIES (3)
#define SLEEP_TIME 2


void set_cr_noecho_mode();
void set_nodelay_mode();

int main (int argc, char *argv[]) {

    struct termios original_mod;
    tcgetattr(0, &original_mod);
    int original_flags = fcntl(0, F_GETFL);

    set_cr_noecho_mode();
    set_nodelay_mode();

    int response = get_response(QUESTION, MAX_TRIES);

    printf("response = %d\n", response);

    tcsetattr(0, TCSANOW, &original_mod);
    fcntl(0, F_SETFL, original_flags);
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

void set_nodelay_mode()
{
    int terflags = fcntl(0, F_GETFL);
    terflags = terflags | O_NDELAY;
    fcntl(0, F_SETFL, terflags);
}

int get_response(char* question, int max_tries)
{
    printf("%s (y/n)?\n", question);
    fflush(stdout);

    while (1) {

        sleep(SLEEP_TIME);

        switch (tolower(get_ok_char())) {
        case 'y':
            return 0;
        case 'n':
            return 1;
        default:
            max_tries--;
            break;
        }

        if (max_tries == 0) {
            return 2;
        }
    }
}

int get_ok_char()
{
    while (1) {
        int c = getchar();
        if (c == EOF || strchr("YyNn", c) != NULL) {
            return c;
        }
    }
}
