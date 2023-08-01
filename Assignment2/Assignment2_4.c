//program which accept directory name from user and print all file names and it's types from that Directory.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char fileType[20]={"\0"};
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    printf("----------------------------------------------------------\n");
    printf("Entries from the directory file are : \n");
    printf("----------------------------------------------------------\n");
    printf("Inode Number \t\t File Name \t\t File Type\n");

    while((entry = readdir(dp)) != NULL)
    {
       if(entry->d_type == 4){
            strcpy(fileType,"Directory");
        }else if(entry->d_type == 8){
            strcpy(fileType,"Regular File");
        }
        else{
             strcpy(fileType,"Special File");

        }
        printf("%s\t\t%s\n",entry->d_name,fileType);   

        
        
    }
    printf("----------------------------------------------------------\n");

    closedir(dp);
    return 0;
}