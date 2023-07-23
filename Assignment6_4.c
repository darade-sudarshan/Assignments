//program which accept Directory name from user and delete all such files whose size is greater 100 bytes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    
    DIR *dir = NULL;
    struct dirent *entry;
    struct stat sobj;
    char FilePath[256]={'\0'};
    

    if (argc != 2)
    {
        printf("Usage: %s <directory_name>\n", argv[0]);
        return -1;
    }
    dir= opendir(argv[1]);
    if (dir == NULL)
    {
        printf("Error opening directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue; // Skip current directory and parent directory
        }

        snprintf(FilePath, sizeof(FilePath), "%s/%s", argv[1], entry->d_name);

        if (stat(FilePath, &sobj) == -1)
        {
            printf("Error getting file information");
            continue;
        }

        if (S_ISREG(sobj.st_mode) && sobj.st_size > 100)
        {
            if (unlink(FilePath) == -1)
            {
                printf("Error deleting file");
                continue;
            }
            printf("File '%s' deleted successfully.\n", FilePath);
        }
    }

    closedir(dir);
    return 0;
}
