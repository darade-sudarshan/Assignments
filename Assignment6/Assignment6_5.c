//program which accept file name from user and offset,remove all the data from that offset.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    if (argc != 3)
    {
        printf("Usage:<file_name> <offset>\n");
        return -1;
    }

    char *Fname = argv[1];
    int offset = atoi(argv[2]);

    int fd = open(Fname, O_RDWR);
    if (fd == -1) {
        printf("Error opening file");
        return -1;
    }

    // Set the file offset to the specified position
    if (lseek(fd, offset, SEEK_SET) == -1)
    {
        printf("Error setting file offset");
        close(fd);
        return -1;
    }

    // Truncate the file from the specified offset
    if (ftruncate(fd, offset) == -1) {
        printf("Error truncating file");
        close(fd);
        return -1;
    }

    close(fd);
    printf("Data removed from offset %d in file '%s'\n", offset, Fname);

    return 0;
}
