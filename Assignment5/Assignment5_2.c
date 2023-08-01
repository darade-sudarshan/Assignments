//program which accept file name from user which contains information of Student, we have to read all contains from that File.  
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
# pragma pack(1)   //used for memory padding 

struct Student
{
    int RollNo;
    char Sname[30];
    float marks;
    int Age;
};

int main(int argc, char * argv[])
{
    struct Student sobj;
    char Fname[30];
    int fd =0;

    printf("enter the File Name");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);

    read(fd,&sobj,sizeof(sobj));
    printf("Roll Number : %d :\n",sobj.RollNo);
    printf("Name : %s :\n",sobj.Sname);
    printf("Marks : %f :\n",sobj.marks);
    printf("Age : %d :\n",sobj.Age);

return 0;
}