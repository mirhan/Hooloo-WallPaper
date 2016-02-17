#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <termio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <curses.h>

#define ENTER 10

//void say_ouch(int signum);
//void ask_if_exit(int signum);

//void draw_rectangle(char c, int col, int row);
//void draw_next(int signum);


//static char g_c = 'A';

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

//    struct termios original_mode, new_mode;
//    tcgetattr(STDIN_FILENO, &original_mode); // get original mode
//    memcpy(&new_mode, &original_mode, sizeof(original_mode));
//
//    new_mode.c_lflag &= ~ECHO;
//    new_mode.c_lflag &= ~ICANON;
//    new_mode.c_cc[VMIN] = 1;
//    tcsetattr(STDIN_FILENO, TCSANOW, &new_mode); // set no echo
//
//    signal(SIGWINCH, draw_next); // signal
//
//    struct winsize w_size;
//    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w_size);
//    draw_rectangle(g_c, w_size.ws_col, w_size.ws_row);
//
//    while (1) {
//        int c = getchar();
//        if (c == 'Q') {
//            break;
//        } else {
//            g_c = 'A';
//            ioctl(STDOUT_FILENO, TIOCGWINSZ, &w_size);
//            draw_rectangle(g_c, w_size.ws_col, w_size.ws_row);
//        }
//    }
//
//
//    tcsetattr(STDIN_FILENO, TCSANOW, &original_mode); // set original mode
//    if (argc > 2) {
//        exit(1);
//    } else if (argc == 2) {
//        max_call_say_ouch_cnt = atoi(argv[1]);
//    }
//
//    struct termios original_mode;
//    tcgetattr(0, &original_mode);
//    struct termios new_mode;
//    memcpy(&new_mode, &original_mode, sizeof (original_mode));
//
//    new_mode.c_lflag &= ~ISIG;
//    tcsetattr(0, TCSANOW, &new_mode);
//
////    signal(SIGINT, ask_if_exit);
//
//    int i;
//    for (i = 0; i < 5; i++) {
//        printf("hello!\n");
//        sleep(5);
//    }
//
//    tcsetattr(0, TCSANOW, &original_mode);
}

//void draw_rectangle(char c, int col, int row)
//{
//    int x, y;
//    for (y = 0; y < row; y++) {
//        for (x = 0; x < col; x++) {
//            putchar(c);
//        }
//        printf("\n");
//    }
//}
//
//void draw_next(int signum)
//{
//    g_c++;
//    struct winsize w_size;
//    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w_size);
//    draw_rectangle(g_c, w_size.ws_col, w_size.ws_row);
//}



//void ask_if_exit(int signum)
//{
//    printf("Interrupted! OK to quit (y/n)?\n");
//
//    while (1) {
//        int c = getchar();
////        printf("%d\n", c );
//        if (c != ENTER) {
//            if (tolower(c) == 'y') {
//                exit(1);
//            } else if (tolower(c) == 'n') {
//                break;
//            }
//            printf("Interrupted! OK to quit (y/n)?\n");
//        }
//    }
//}
//
//
//void say_ouch(int signum)
//{
//    static call_cnt = 0;
//    call_cnt++;
//    printf("OUCH");
//
//    int i;
//    for (i = 0; i< call_cnt;i++) {
//        printf("!");
//    }
//
//    printf("\n");
//
//    if (max_call_say_ouch_cnt != 0) {
//        if (call_cnt == max_call_say_ouch_cnt) {
//            exit(1);
//        }
//    }
//}
