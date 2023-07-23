//program which accept file name and number of bytes from user and read that number of bytes from File.
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
    char Fname[20];
    int fd = 0;
    int Size = 0;
    int Ret = 0;
    char *Buffer=NULL;
    printf("Enter File name to Open : \n");
    scanf("%s",Fname);

    printf("Enter No of Bytes to Read from File : \n");
    scanf("%d",&Size);

    fd = open(Fname,O_RDONLY);
    if(fd ==-1)
    {
        printf("unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is Successfully opened File FD %d \n",fd);
    }

    Buffer = (char *) malloc(sizeof(Size));
   
    
    Ret = read(fd,Buffer,Size);

    if(Ret ==0)
    {
        printf("unable to read data from file");
    }
    else
    {
        printf("Data from File is : %s\n",Buffer);
        
    }
return 0;
}