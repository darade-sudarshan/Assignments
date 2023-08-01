//program which create hole of size 1 KB at the end of File.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() 
{
    char cFName = {'\0'};
    char *data = "This is some data.";
    char ByteHole = '\0';
    int fd = 0,offset = 0;
    printf("enter the file name in which hole needs to be created");
    scanf("%s",cFName);
   
    fd = open(cFName, O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return -1;
    }
   
    int bytes_written = write(fd, data, strlen(data));

    if (bytes_written == -1)
    {
        printf("Error writing to file\n");
        close(fd);
        return -1;
    }

    offset = lseek(fd, 1024, SEEK_CUR);
    if (offset == -1) {
        printf("Error seeking in file");
        close(fd);
        return -1;
    }
    
    bytes_written = write(fd, &ByteHole, 1);
    if (bytes_written == -1) 
    {
        printf("Error writing hole to file");
        close(fd);
        return -1;
    }

    // Close the file.
    if (close(fd) == -1) 
    {
        printf("Error closing file");
        return -1;
    }

    printf("File with a hole of size 1 KB created successfully.\n");
    return 0;
}