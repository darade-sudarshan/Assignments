//program which accept file name which contains data of all file. we have to print all file names whose size is greater that 10 bytes.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_CONTENT_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        printf("Usage: %s input_filename\n", argv[0]);
        return -1;
    }
    char cFname[MAX_FILENAME_LENGTH];
    char cContent[MAX_FILE_CONTENT_LENGTH];
    int BytesRead;
    int ContentLength;
    int FileSize;
    int InputFile = open(argv[1], O_RDONLY);

    if (InputFile == -1)
    {
        printf("Error: Unable to open input file %s\n", argv[1]);
        return 1;
    }

    
    while ((BytesRead = read(InputFile, cFname, MAX_FILENAME_LENGTH)) > 0)
    {
        cFname[BytesRead - 1] = '\0';

        ContentLength = read(InputFile, cContent, MAX_FILE_CONTENT_LENGTH);
        if (ContentLength <= 0)
        {
            printf("Error: Invalid format in input file.\n");
            close(InputFile);
            return 1;
        }


        FileSize = (int)ContentLength;
        if (FileSize > 10)
        {
            printf("Filename with size greater than 10 bytes: %s\n", cFname);
        }
    }

    close(InputFile);

    return 0;
}
