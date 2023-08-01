//program which accept two Directory names from user and delete all empty files from  Directory.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int args, char * argv[])
{
  DIR *dir = NULL;
  struct dirent *entry = NULL;
  struct stat sobj;
  char EmptyFile[50]={"\0"};

  if(args!=2){
      printf("Error: Invalid Arguments\n");
      return -1;
  }

  dir = opendir(argv[1]);
  if(dir == NULL ){
      printf("Error: Unable to open directory\n");
      return -1;
  }

  while((entry = readdir(dir))!=NULL)
  {

    sprintf(EmptyFile,"%s/%s",argv[1],entry->d_name);
    stat(EmptyFile,&sobj);
    if(S_ISREG(sobj.st_mode))
    {
      if(sobj.st_size == 0)
      {
        remove(EmptyFile);
      }
    }
  }


  closedir(dir);
  return 0;
}
