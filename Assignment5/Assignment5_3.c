//program which accept directory name from user and write information of all regular file from the Directory and read contents from that file.
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#pragma pack(1)

struct FileInfo
{
    char cFileName[256];
    int iFileSize;
    int iNodeNumber;
};

int main(int argc, char *argv[])
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    struct FileInfo fobj;
    struct stat sobj;
    char FilePath[256] = {0};
    int fd = 0;
    int ret = 0;

    if (argc != 2) {
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error: Unable to open Directory\n");
        return -1;
    }

    fd = open("FileInfo.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (fd == -1)
    {
        printf("Error: Unable to create File\n");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        sprintf(FilePath, "%s/%s", argv[1], entry->d_name);
        if (stat(FilePath, &sobj) == -1)
        {
            printf("Error: Unable to get file information for %s\n", entry->d_name);
            continue;
        }

        memset(&fobj, 0, sizeof(fobj));

        if (S_ISREG(sobj.st_mode))
         {
            strncpy(fobj.cFileName, entry->d_name, sizeof(fobj.cFileName) - 1);
            fobj.iFileSize = sobj.st_size;
            fobj.iNodeNumber = sobj.st_ino;
            write(fd, &fobj, sizeof(fobj));
        }
    }

    close(fd);
    closedir(dir);
    

    // Read and display the contents of "fileinfo.txt"
    fd = open("fileinfo.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error: Unable to open File\n");
        return -1;
    }

    printf("Reading data.....\n");

    while ((ret = read(fd, &fobj, sizeof(fobj))) != 0) {
        printf("FileName: %s\n", fobj.cFileName);
        printf("FileSize: %d\n", fobj.iFileSize);
        printf("File Inode: %d\n", fobj.iNodeNumber);
        printf("\n");
    }

    if (ret == -1) {
        printf("Error: Unable to read File\n");
    }

    close(fd);

    return 0;
}
