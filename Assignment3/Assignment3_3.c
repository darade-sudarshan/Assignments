//program which accept two Directory names from user and move all files from source Directory to Destination Directory.
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

# define BufferSize 1024
# define FilePath 1000

void MoveFiles(char *SourceDir,char *DestDir)
{
    struct dirent *Entry;
    struct stat sobj;
    DIR *dir = NULL;
    char srcFilePath[FilePath]={'\0'};
    char destFilePath[FilePath]={'\0'};
    dir = opendir(SourceDir);
    if(dir==NULL)
    {
        printf("Error opening source directory");
        return;
    } 
     while ((Entry = readdir(dir)) != NULL)
     {
        if (strcmp(Entry->d_name, ".") != 0 && strcmp(Entry->d_name, "..") != 0)
        {
            snprintf(srcFilePath, sizeof(srcFilePath), "%s/%s", SourceDir, Entry->d_name);

            if (stat(srcFilePath, &sobj) == -1)
            {
                printf("Error getting file information");
                closedir(dir);
                return;
            }

            if (S_ISREG(sobj.st_mode))
            {
                
                snprintf(destFilePath, sizeof(destFilePath), "%s/%s", DestDir, Entry->d_name);

                rename(srcFilePath, destFilePath);                

                printf("Moved file: '%s' to '%s'\n", srcFilePath, destFilePath);
            }
        }
    }
    closedir(dir); 
}
int main(int argc, char * argv[])
{
    if(argc !=3)
    {
        printf("Invalid Arguments");
        printf("Usage : Source Directory Destination Directory");
        return -1;
    }
    char *SourceDir = argv[1];
    char *DestDir = argv[2];
    MoveFiles(SourceDir,DestDir);

    printf("Files moved successfully from '%s' to '%s'.\n", SourceDir, DestDir);


return 0;
}