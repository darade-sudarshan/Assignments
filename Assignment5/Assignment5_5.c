//program which to create file which contains data of all files. we have to create all file again.
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf( "Invalid No of Arguments");
        return -1;
    }
    printf("Usage: OutputFile  InputFile1,InputFile2, ....N\n ");

    int fdOutput, fdInput;
    char buffer[BUFFER_SIZE] = {'\0'};

    int NoOfBytesRead, NoOfBytesWritten;

    fdOutput = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
    if (fdOutput == -1) 
    {
        printf("Error opening output file\n");
        return -1;
    }

    for (int iCnt = 1; iCnt < argc; iCnt++)
     {
        fdInput = open(argv[iCnt], O_RDONLY);
        if (fdInput == -1)
        {
            printf("Error opening input file\n");
            return -1;
        }
        while ((NoOfBytesRead = read(fdInput, buffer, BUFFER_SIZE)) != 0)
         {
            NoOfBytesWritten = write(fdOutput, buffer, NoOfBytesRead);
            if (NoOfBytesWritten == -1)
             {
                printf("Error writing to output file\n");
                return -1;
            }
        }

        if (NoOfBytesRead == -1)
        {
            printf("Error reading from input file\n");
            return -1;
        }

       
    close(fdInput);
    }

    close(fdOutput);

    printf("Files combined successfully.\n");
    return 0;
}