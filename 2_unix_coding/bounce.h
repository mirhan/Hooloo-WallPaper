/*
 * bounce.h
 *
 *  Created on: 2016?2?16?
 *      Author: chanhan
 */

#ifndef BOUNCE_H_
#define BOUNCE_H_

#define BLANK ' '
#define DEL_SYMBOL 'O'
#define TOP_ROW 5
#define BOTTOM_ROW 20
#define LEFT_EDGE 10
#define RIGHT_EDGE 70
#define X_INIT 10
#define Y_INIT 10
#define TICKS_PER_SEC 50

#define X_TTM 5
#define Y_TTM 8

#define BAFFLE_LEN 5

struct ppball
{
    int y_pos;
    int x_pos;
    int x_ttm;
    int y_ttm;
    int x_ttg;
    int y_ttg;
    int x_dir;
    int y_dir;
    char symbol;
};

struct baffles
{
    int length;
    int x_baffle_pos;
    int y_baffle_pos;
};


#endif /* BOUNCE_H_ */
