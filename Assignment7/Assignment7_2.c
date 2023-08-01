/* program  which is used to create shared Library and that Library should be loaded at runtime by the other program.
that library should contain function which accepts 2 file names from user and it will compare the contents of that file. 

Author : Sudarshan darade
Date : 30/07/2023

*/
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc,char *argv[])
{
    void * ptr = NULL;
    int (*fptr)(char *,char *);
    int ret = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    ptr = dlopen("/mnt/d/Marvellous/LSP/Assignments/Assignment7_2FComp.so", RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"compareFile");

    if(fptr == NULL)
    {
        printf("Unable to locate function\n");
        return -1;
    }
    
    ret = fptr(argv[1],argv[2]);

    if(ret == 0)
    {
        printf("Both the file are identical\n");
    }
    else
    {
        printf("Files are different \n");
    }

    return 0;
}