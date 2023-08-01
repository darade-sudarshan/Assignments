//program which writes structure in file. Structure should contains information of student.
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

    sobj.RollNo = 11;
    sobj.Age = 25;
    sobj.marks = 81.44f;
    strcpy(sobj.Sname,"Sudarshan");

    printf("enter the File Name");
    scanf("%s",Fname);

    fd = creat(Fname,0777);

    write(fd,&sobj,sizeof(sobj));

return 0;
}