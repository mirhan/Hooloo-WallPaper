/* webserv.c - a minimal web server (version 0.2)
 *      usage: ws portnumber
 *   features: supports the GET command only
 *             runs in the current directory
 *             forks a new child to handle each request
 *             has MAJOR security holes, for demo purposes only
 *             has many other weaknesses, but is a good start
 *      build: cc webserv.c socklib.c -o webserv
 */
#include    <stdio.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <string.h>

main(int ac, char *av[])
{
    int sock, fd;
    FILE *fpin;
    char request[BUFSIZ];

    if (ac != 3) {
        fprintf(stderr, "usage: wc hostname portnum\n");
        exit(1);
    }
    sock = connect_to_server(av[1], atoi(av[2]));
    if (sock == -1)
        exit(2);

    printf("1.\n");
    write(sock, "GET hello.cgi\r\n", sizeof("GET hello.cgi\r\n"));
//    FILE * ffile = fdopen(sock, "w+"); /* read stuff   */
//    fprintf(ffile, "GET hello.cgi");
//    fflush(ffile);

    printf("2.\n");
    write(sock, "\r\n", sizeof("\r\n"));
    printf("2.5\n");
//    int c;
//    while ((c = fgetc(ffile)) != EOF) { // standard C I/O file reading loop
//       printf("3.\n");
//       putchar(c);
//    }

//    fclose(ffile);
    char buf[BUFSIZ];
    read(sock, &buf, BUFSIZ);
    printf("3.\n");


    printf("buf = %s.\n", buf);

    printf("the end.\n");
}
