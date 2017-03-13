#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close

// SOURCE: http://stackoverflow.com/questions/19472546/implicit-declaration-of-function-closes

void copy(const char* src_path, char* dst_path)
{
	int src_fd, dst_fd, n, err;
   unsigned char buffer[4096];
   

    

    src_fd = open(src_path, O_RDONLY);
    dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC,0777);
   

    while (1) {
        err = read(src_fd, buffer, 4096);
        if (err == -1) {
            printf("Error reading file.\n");
            exit(1);
        }
        n = err;

        if (n == 0) break;

        err = write(dst_fd, buffer, n);
        if (err == -1) {
            printf("Error writing to file.\n");
            perror("ERROR:");
            exit(1);
        }
    }
 
   
}