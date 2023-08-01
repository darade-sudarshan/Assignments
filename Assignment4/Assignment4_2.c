//program which accept Directory name from user and create new directory of that name.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int args, char *argv[])
{
    int Ret = 0;
    if(args != 2)
    {
        printf("Error: Invalid Arguments\n");
        return -1;
    }

Ret = mkdir(argv[1],S_ISVTX);
if(Ret == -1)
    {
        printf("Unable to create Directory\n");
        return -1;
    }

printf("Directory Created Successfully\n");

return 0;
}