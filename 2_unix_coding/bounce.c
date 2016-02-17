/*
 * bounce.c
 *
 *  Created on: 2016?2?16?
 *      Author: chanhan
 */

#include <curses.h>
#include <signal.h>
#include <sys/time.h>
#include "bounce.h"

void set_up();
void wrap_up();
void ball_move(int signum);

struct ppball theball;
int main()
{
    set_up();

    int c = getchar();
    while (c != 'Q') {
        if (c == 'f') {
            theball.x_ttm--;
        } else if (c == 's') {
            theball.x_ttm++;
        } else if (c == 'F') {
            theball.y_ttm--;
        } else if (c == 'S') {
            theball.y_ttm++;
        }

        c = getchar();
    }

    wrap_up();
}

void set_up()
{
    void draw_frame();
    theball.y_pos = Y_INIT;
    theball.x_pos = X_INIT;

    theball.y_ttg = theball.y_ttm = Y_TTM;
    theball.x_ttg = theball.x_ttm = X_TTM;

    theball.y_dir = 1;
    theball.x_dir = 1;

    theball.symbol = DEL_SYMBOL;

    initscr();
    noecho();
    crmode();

    draw_frame();

    signal(SIGINT, SIG_IGN);
    mvaddch(theball.y_pos, theball.x_pos, theball.symbol);
    refresh();

    signal(SIGALRM, ball_move);

    set_ticker(1000 / TICKS_PER_SEC);
}

void draw_frame()
{
    int i;
    for (i = LEFT_EDGE - 1; i < RIGHT_EDGE + 1; i++) {
        mvaddch(TOP_ROW - 1, i, '-');
        mvaddch(BOTTOM_ROW + 1, i, '-');
    }

    for (i = TOP_ROW - 1; i < BOTTOM_ROW + 1; i++) {
        mvaddch(i, LEFT_EDGE - 1, '|');
        mvaddch(i, RIGHT_EDGE + 1, '|');
    }
}

void wrap_up()
{
    set_ticker(0);
    endwin();
}

void ball_move(int signum)
{
    signal(SIGALRM, SIG_IGN);

    int y_cur = theball.y_pos;
    int x_cur = theball.x_pos;
    int is_moved = 0;

    if (theball.y_ttm > 0 && theball.y_ttg == 1) {
        theball.y_pos += theball.y_dir;
        theball.y_ttg = theball.y_ttm;
        is_moved = 1;
    }
    theball.y_ttg--;

    if (theball.x_ttm > 0 && theball.x_ttg == 1) {
        theball.x_pos += theball.x_dir;
        theball.x_ttg = theball.x_ttm;
        is_moved = 1;
    }
    theball.x_ttg--;

    if (is_moved) {
        mvaddch(y_cur, x_cur, BLANK);
//        mvaddch(y_cur, x_cur, BLANK);
        mvaddch(theball.y_pos, theball.x_pos, theball.symbol);
        bounch_or_lose(&theball);
        move(LINES - 1, COLS - 1);
        refresh();
    }

    signal(SIGALRM, ball_move);
}

int bounch_or_lose(struct ppball *bp)
{
    int ret = 0;
    if (bp->y_pos == TOP_ROW) {
        bp->y_dir = 1;
        ret = 1;
    } else if (bp->y_pos == BOTTOM_ROW) {
        bp->y_dir = -1;
        ret = 1;
    }

    if (bp->x_pos == LEFT_EDGE) {
        bp->x_dir = 1;
        ret = 1;
    } else if (bp->x_pos == RIGHT_EDGE) {
        bp->x_dir = -1;
        ret = 1;
    }

    return ret;
}

int set_ticker(long n_msecs)
{
    long n_sec = n_msecs / 1000;
    long n_usecs = (n_msecs % 1000) * 1000L;

    struct itimerval new_timeset;
    new_timeset.it_interval.tv_sec = n_sec;
    new_timeset.it_interval.tv_usec = n_usecs;
    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec = n_usecs;

    return setitimer(ITIMER_REAL, &new_timeset, NULL);
}
