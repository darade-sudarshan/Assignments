// program which accept file name and mode from user and then open that file in specific mode.
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char * argv[])
{
    char Fname[30];
    int fd = 0;
    int mode = 0;
    if (argc != 3)
    {
        printf("invalid no of arguments");
        return -1;
    }
    
    printf("Enter File name to Open : \n");
    scanf("%s",Fname);
    
    printf("enter Mode in which you want to Open the File");
    scanf("%d",&mode);

    if(strcmp(argv[2],"Read")==0)
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write")==0)
    {
        mode = O_WRONLY;
    }
    else if (strcmp(argv[2],"ReadWrite")==0)
    {
        mode = O_RDWR;
    }
    else
    {
        mode = O_RDONLY;
    }
    fd = open(Fname,mode);

    if(fd ==-1)
    {
        printf("unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is Successfully opened File FD %d \n",fd);
    }
return 0;
}