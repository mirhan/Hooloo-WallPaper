/* hello_multi.c - a multi-threaded hello world program */

#include  <stdio.h>
#include  <pthread.h>

#define NUM 5

main()
{
    pthread_t t1, t2; /* two threads */

    void *print_msg(void *);

    pthread_create(&t1, NULL, print_msg, (void *) "hello");
    if (pthread_join(t1, NULL) == 0) {
        printf("pthread_join 1 end\n");
        fflush(stdout);
    }
    pthread_create(&t2, NULL, print_msg, (void *) "world\n");




    if (pthread_join(t2, NULL) == 0) {
        printf("pthread_join 1 end\n");
        fflush(stdout);
    }

    int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
        fflush(stdout);
    }
}
void *print_msg(void *m)
{
    char *cp = (char *) m;
    int i;
    for (i = 0; i < NUM; i++) {
        printf("%s", cp);
        fflush(stdout);
        sleep(1);
    }
    return NULL;
}
