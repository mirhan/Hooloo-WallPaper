#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <termio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <curses.h>

int main(int argc, char* argv[])
{
    initscr();
    clear();

    int i;
    for (i = 0; i < LINES; i++) {
        move (i, i + i);

        if (i % 2 == 1) {
            standout();
        }

        addstr("Hello, world.");

        if (i % 2 == 1) {
            standend();
        }
    }
//    refresh();
    getch();
    endwin();
}
