#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char path[80];
  int i=0;

  system("mkdir -p /tmp/testing/a/b/c/d/e/f/g");

  for(i=0; i<50; i++)
  {
    chdir("/tmp/testing/a/b/c/d/e/f/g");

    getcwd(path, 80);

    printf("%i - %s\n",i,path);  
  }
}
