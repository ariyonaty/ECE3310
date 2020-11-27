/* 
    Systems Programming
    File I/O Open and Close
 */

// For file control operations
#include <fcntl.h>
// For closeing file using file descriptor
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    // The kernel maintains a list of per-process open files in a
    // file tbale. Each entry is a non-negative integer called a file
    // descriptor. Table entries also contain information about the file (later).
    //
    // 3 standard file descriptors.:
    //     stdin:  0
    //     stdout: 1
    //     stderr: 2
    int fd;

    // "open" maps a path to a file descriptor
    // Takes a file path, falg (access mode + behavior), adn permission
    // if a file is created.
    // Requires an access mode:
    //      O_RDONLY
    //      O_WRONLY
    //      O_RDWR
    //
    // Open a file as write-only
    fd = open("./test.txt", O_WRONLY);

    // print out the flag and fd
    printf("Flag: 0x%X\n", O_WRONLY);
    printf("File descriptor fd = %d\n", fd);

    // close the file descriptor
    close(fd);

    // Open the file for write-only mode, and truncate the file
    fd = open("./test.txt", O_WRONLY | O_TRUNC);

    // print out the flag and fd
    printf("Flag: 0x%X\n", O_WRONLY | O_TRUNC);
    printf("File descriptor fd = %d\n", fd);

    return 0;
}
