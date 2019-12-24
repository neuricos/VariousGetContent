#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

void usage(char *progname) {
    printf("Usage: %s <file name>\n", progname);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }
    char *inputfile = argv[1];

    // Try to open the file for reading
    int fd = open(inputfile, O_RDONLY);
    if (fd == -1) {
        // Open failed
        perror("Error");
        return 1;
    }

    char buf[BUF_SIZE];
    ssize_t bread;  // Number of bytes read from the file
    while ((bread = read(fd, buf, BUF_SIZE)) != 0) {
        buf[bread] = '\0';
        printf("%s", buf);
    }

    // Close the file descriptor
    close(fd);
    // Exit successfully
    return 0;
}
