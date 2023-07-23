// program which accepts file name from user and write string in file.
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
    char Buffer[BufferSize] ={'\0'};

    
    printf("Enter File name to Open : \n");
    scanf("%s",Fname);
    
    printf("Enter the string to write in File: ");
    scanf(" %[^\n]s", Buffer);

    fd = open(Fname,O_RDWR | O_APPEND | O_CREAT);

    Ret = read(fd,Buffer,BufferSize);
    if(Ret == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    printf("Data from file is : %s\n",Buffer);

    return 0;
    }
