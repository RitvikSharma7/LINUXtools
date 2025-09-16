/*touch command which creates a file of specified name when supplied filename parameter(s) 
*if file(s) exits it asks user if it wants to overwrite the file(s) (create file with same name but all data is erased.) 
*/

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename(s)\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        char ans;
        if (access(argv[i], F_OK) != -1) {
            printf("File exists, do you want to overwrite %s (Y/N)? ", argv[i]);
            do {
                scanf(" %c", &ans); 
            } while (ans != 'Y' && ans != 'N' && ans != 'y' && ans != 'n');

            if (ans != 'Y' && ans != 'y') {
                printf("Skipped %s\n", argv[i]);
                continue; 
            }
        }

        int fd = open(argv[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fd < 0) {
            perror(argv[i]);
            continue;
        }
        close(fd);
    }

    return EXIT_SUCCESS;
}
