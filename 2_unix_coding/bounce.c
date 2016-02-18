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

#define H_KEY_UP    65
#define H_KEY_DOWN  66
#define H_KEY_RIGHT 67
#define H_KEY_LEFT  68

void set_up();
void wrap_up();

void refresh_draw(int signum);
void baffle_move(int signum);
void ball_move(int signum);
void draw_baffles();

struct ppball theball;
struct baffles thebaffles;
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
        } else if (c == H_KEY_UP) {
            if (thebaffles.y_baffle_pos > TOP_ROW) {
                thebaffles.y_baffle_pos--;
            }
        } else if (c == H_KEY_DOWN) {
            if (thebaffles.y_baffle_pos + thebaffles.length < BOTTOM_ROW + 1) {
                thebaffles.y_baffle_pos++;
            }
        } else if (c == H_KEY_LEFT) {
            if (thebaffles.x_baffle_pos > LEFT_EDGE) {
                thebaffles.x_baffle_pos--;
            }
        } else if (c == H_KEY_RIGHT) {
            if (thebaffles.x_baffle_pos + thebaffles.length < RIGHT_EDGE + 1) {
                thebaffles.x_baffle_pos++;
            }
        }

        c = getchar();
    }

    wrap_up();
}

void set_up()
{
    theball.y_pos = Y_INIT;
    theball.x_pos = X_INIT;

    theball.y_ttg = theball.y_ttm = Y_TTM;
    theball.x_ttg = theball.x_ttm = X_TTM;

    theball.y_dir = 1;
    theball.x_dir = 1;

    theball.symbol = DEL_SYMBOL;

    thebaffles.length = BAFFLE_LEN;
    thebaffles.x_baffle_pos = RIGHT_EDGE - (RIGHT_EDGE - LEFT_EDGE) / 2 - BAFFLE_LEN / 2;
    thebaffles.y_baffle_pos = BOTTOM_ROW - (BOTTOM_ROW - TOP_ROW) / 2 - BAFFLE_LEN / 2;

    initscr();
    noecho();
    crmode();

    signal(SIGINT, SIG_IGN);

    draw_baffles();

    mvaddch(theball.y_pos, theball.x_pos, theball.symbol);
    refresh();

    signal(SIGALRM, refresh_draw);

    set_ticker(1000 / TICKS_PER_SEC);
}

void draw_baffles()
{
    struct baffles *pbaffles = &thebaffles;
    int i;
    for (i = pbaffles->x_baffle_pos; i < pbaffles->x_baffle_pos + pbaffles->length; i++) {
        mvaddch(TOP_ROW - 1, i, '-');
        mvaddch(BOTTOM_ROW + 1, i, '-');
    }

    for (i = pbaffles->y_baffle_pos; i < pbaffles->y_baffle_pos + pbaffles->length; i++) {
        mvaddch(i, LEFT_EDGE - 1, '|');
        mvaddch(i, RIGHT_EDGE + 1, '|');
    }
}

void wrap_up()
{
    set_ticker(0);
    endwin();
}

void refresh_draw(int signum)
{
    signal(SIGALRM, SIG_IGN);
    baffle_move(signum);
    ball_move(signum);
    signal(SIGALRM, refresh_draw);
}

void baffle_move(int signum)
{
    int i;
    for (i = LEFT_EDGE - 1; i <= RIGHT_EDGE + 1; i++) {
        mvaddch(TOP_ROW - 1, i, BLANK);
        mvaddch(BOTTOM_ROW + 1, i, BLANK);
    }

    for (i = TOP_ROW - 1; i <= BOTTOM_ROW + 1; i++) {
        mvaddch(i, LEFT_EDGE - 1, BLANK);
        mvaddch(i, RIGHT_EDGE + 1, BLANK);
    }

    draw_baffles();
}

void ball_move(int signum)
{
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
