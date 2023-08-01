// program which accepts file name from user and read whole file.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

# define BufferSize 1024

int main(int argc, char * argv[])
{
    char Fname[20];
    int fd = 0;
    int Ret = 0;
    char Buffer[] ={'\0'};
    
    printf("Enter FIle name to Open : \n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);
    if(fd ==-1)
    {
        printf("unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is Successfully opened File FD %d \n",fd);
        while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)   
        {
            write(1,Buffer,Ret);
            printf("%s",Buffer);
        } 
    close(fd);
    }
return 0;
}