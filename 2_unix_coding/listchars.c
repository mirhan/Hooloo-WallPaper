#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>


int main (int argc, char* agrv[]){
    int c;
    int n = 0;
    while((c = getchar()) != 'Q') {
        printf("%3d: is %c, code %d \n", n++, c, c);
    }

    return 0;
}
