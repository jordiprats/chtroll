#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>



int main(void)
{
  char path[80];
  int i=0;
  int fd=0;

  system("mkdir -p /tmp/testing/a/b/c/d/e/f/g");

  for(i=0; i<50; i++)
  {
    fd = open("/tmp/testing/a/b/c/d/e/f/g", O_RDONLY);
    fchdir(fd);
    close(fd);

    getcwd(path, 80);

    printf("%i - %s\n",i,path);
  }
}
