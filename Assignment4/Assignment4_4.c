//program which accept Directory name from user and copy first 10 bytes from all regular files into newly created Files as Demo.txt
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int args,char * argv[])
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    int fdSource = 0;
    int fdDest = 0;
    char SourcePath[30] = {"\0"};
    int ret = 0;
    char buffer[10]={"\0"};

    if(args !=3)
    {
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    dir = opendir(argv[1]);
    if(dir == NULL)
    {
        printf("Error: Unable to open %s directory\n",argv[1]);
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest == -1)
    {
        printf("Error: Unable to create file\n");
        return -1;
    }

    while((entry = readdir(dir))!= NULL)
    {
        sprintf(SourcePath,"%s/%s",argv[1],entry->d_name);
        fdSource=open(SourcePath,O_RDONLY);
        ret = read(fdSource,buffer,sizeof(buffer));
        write(fdDest,buffer,ret);
    }


    return 0;
}