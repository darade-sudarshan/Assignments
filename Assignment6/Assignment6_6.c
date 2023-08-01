//program which accept Directory name and create hole in file if size is less that 1 KB & if it is greater than 1 KB then truncate the remaining data.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILENAME_LENGTH 256
#define BufferSize 1024

void processFile(char *dirName,char *fileName)
 {
    char filePath[MAX_PATH_LENGTH];
    char hole_byte = {'\0'};
    int fd = 0,bytes_written;

    snprintf(filePath, sizeof(filePath), "%s/%s", dirName, fileName);

    struct stat fobj;
    if (stat(filePath, &fobj) == -1)
    {
        printf("Error getting file information");
        return;
    }

    if (S_ISREG(fobj.st_mode))
    {
        if (fobj.st_size < BufferSize)
        {
            fd = open(filePath, O_WRONLY | O_CREAT | O_APPEND);
            if (fd == -1)
            {
                printf("Error opening file");
                return;
            }
            bytes_written = write(fd, &hole_byte, 1);
            if (bytes_written == -1)
            {
                printf("Error writing hole to file");
                close(fd);
                return;
            }

           close(fd);
            printf("Hole created in file '%s'.\n", fileName);
        }
        else
        {
            fd = open(filePath, O_RDWR);
            if (fd == -1)
            {
                printf("Error opening file");
                return;
            }

            int newSize = BufferSize;
            if (ftruncate(fd, newSize) == -1)
            {
                printf("Error truncating file");
                close(fd);
                return;
            }

            close(fd);

            printf("File '%s' truncated to 1 KB.\n", fileName);
        }
    }
}

int main(int argc, char *argv[])
{   
    struct dirent *entry;
    DIR *dir = NULL;
    char *dirName = argv[1];
    char FilePath[MAX_PATH_LENGTH]={'\0'};
    if (argc != 2)
    {
        printf("Usage: directory_name\n");
        return -1;
    }
  
    dir = opendir(dirName);
    if (dir==-1)
    {
        printf("unable to open directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        if (entry->d_type == DT_REG)
        {
            snprintf(FilePath, sizeof(FilePath), "%s/%s", dirName, entry->d_name);
            processFile(dirName, entry->d_name);
        }
    }

   closedir(dir);

    printf("Files processed successfully.\n");
    return 0;
}
