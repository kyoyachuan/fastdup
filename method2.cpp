#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  struct stat stats;
  if (argc != 3)
  {
    printf("Usage: %s <source> <destination>\n", argv[0]);
    return -1;
  }

  int fd_in = open(argv[1], O_RDONLY);
  if (fd_in == -1)
  {
    perror("readwrite: open");
    return -1;
  }
  fstat(fd_in, &stats);

  int fd_out = creat(argv[2], 0644);
  if (fd_out == -1)
  {
    perror("readwrite: creat");
    return -1;
  }

  char *buf = new char[stats.st_mode];
  size_t readn;
  while (1)
  {
    readn = read(fd_in, buf, stats.st_mode);
    if (readn <= 0)
    {
      break;
    }

    while (readn)
    {
      size_t writen = write(fd_out, buf, readn);
      if (writen == -1)
      {
        perror("readwrite: write");
        return -1;
      }
      readn -= writen;
    }
  }

  if (readn == -1)
  {
    perror("readwrite: read");
    return -1;
  }

  close(fd_in);
  close(fd_out);
  return 0;
}
