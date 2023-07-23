// program which accept file name from user and print all information about that file.
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    char Fname[30];
    int fd = 0;
    struct stat fobj;
        
    printf("Enter File name to Open : \n");
    scanf("%s",Fname);
    fd = open(Fname,O_RDONLY);
    fstat(fd,&fobj);
    printf("File name is : %s\n",Fname);
    printf("File size is : %ld\n",fobj.st_size);
    printf("Number of links : %ld\n",fobj.st_nlink);
    printf("File system Number : %ld\n",fobj.st_dev);
    printf("Number of Blocks : %ld\n",fobj.st_blocks);
    printf("File inode number is  : %ld\n",fobj.st_ino);
    
    return 0;
}