#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/sendfile.h>

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

  ssize_t bytes = sendfile(fd_out, fd_in, NULL, stats.st_size);

  if (bytes == -1)
  {
    perror("readwrite: splice");
    return -1;
  }

  close(fd_in);
  close(fd_out);
  return 0;
}
