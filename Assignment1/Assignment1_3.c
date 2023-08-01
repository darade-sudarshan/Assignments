// program which accept file name from user and on mode and that program check whether our process can access that file in accepted mode or not.
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
        printf("invalid no of arguments\n");
        return -1;
    }
    
    printf("Enter File name to Open : \n");
    scanf("%s",Fname);
    
    printf("enter Mode in which you want to Open the File\n");
    scanf("%d",&mode);

    if(strcmp(argv[2],"Read")==0)
    {
        mode = O_RDONLY;
        printf("File is opened in Read only Mode\n");
    }
    else if(strcmp(argv[2],"Write")==0)
    {
        mode = O_WRONLY;
        printf("File is opened in Write only Mode\n");
    }
    else if (strcmp(argv[2],"ReadWrite")==0)
    {
        mode = O_RDWR;
        printf("File is opened in Read Write Mode\n");
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
        printf("File is Successfully opened with File FD %d \n",fd);
    }
return 0;
}