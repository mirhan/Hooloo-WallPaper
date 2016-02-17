#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <termio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <curses.h>

#define LEFTEDGE 10
#define RIGHTEDGE 30
#define ROW 10

int main(int argc, char* argv[])
{
    char* message = "hello";
    char* blank = "     ";
    int dir = 1;
    int pos = LEFTEDGE;
    initscr();
    clear();

    int i;
    for (i = 0; i < 0xfffff; i++) {
        move(ROW, pos);
        addstr(message);
        move(LINES - 1, COLS - 1);
        refresh();

//        sleep(1);
        move(ROW, pos);
        addstr(blank);
        pos = pos + dir;
        if (pos >= RIGHTEDGE)
            dir = -1;
        else if (pos <= LEFTEDGE)
            dir = 1;

//        move (i, i + i);
//        addstr("Hello, world.");
//        addstr("             ");
    }
//    getch();
    endwin();
}
