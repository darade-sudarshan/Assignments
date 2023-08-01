//program which accept file and position from user and read 20 bytes from that position
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int args,char *argv[])
{ 
    int fd = 0;
    char buffer[20]={"\0"};
    int ret = 0;

    if(args!=3)
    {
        printf("Invalid No of Arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open %s",argv[1]);
        return -1;
    }

    lseek(fd,atoi(argv[2]),SEEK_CUR);
    ret = read(fd,buffer,20);
    write(1,buffer,ret);


    return 0;
}