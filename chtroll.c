#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//void *malloc(size_t size);
//void free(void *ptr);

static unsigned int count=0;
static unsigned int fucktime=0;

// int fchdir(int fd);
int chdir(const char *path)
{
  char back[]="/../..";
  int fd;
  char *new_path;
  int path_size=0;
  int n_back=0;
  int i=0;

  if(fucktime == 0)
  {
    srand((int)time((time_t *)NULL));
    fucktime = ((unsigned int)rand())%3+2;
  }

  count++;

  if(count%fucktime== 0)
  {
    fucktime = ((unsigned int)rand())%count+3;
    count = 0;
    n_back = ((unsigned int)rand())%4;
    path_size=sizeof(char)*(strlen(back)*(n_back+1)+strlen(path));
    new_path = malloc(path_size);

    // printf("malloc size: %i\n",path_size);

    strcpy(new_path, path);
    strcat(new_path, back);
    for(i=0; i<n_back; i++)
    {
      strcat(new_path, back);
    }

    // printf("new path: %s\n", new_path);

    fd = open(new_path, O_RDONLY);
    free(new_path);
    return fchdir(fd);
  }
  else
  {
    fd = open(path, O_RDONLY);
    return fchdir(fd);
  }
}
