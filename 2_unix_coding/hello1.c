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
    move(10, 20);
    addstr("Hello, world.");
    move (LINES - 1, 0);
    refresh();
    getch();
    endwin();
}
