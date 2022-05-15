#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("Usage: %s <source> <destination>\n", argv[0]);
    return -1;
  }
  
  int fd_in = open(argv[1], O_RDONLY);
  if(fd_in == -1){
    perror("readwrite: open");
    return -1;
  }
  struct stat size;
  fstat(fd_in, &size);
  
  int fd_out = creat(argv[2], 0644);
  if(fd_out == -1){
    perror("readwrite: creat");
    return -1;
  }

  /*
  ssize_t bytes = splice(fd_in, NULL, fd_out, NULL, BUF_SIZE, 0);
  */

  ssize_t bytes = sendfile(fd_out, fd_in, NULL, size.st_size);

  if(bytes < 0){
    perror("readwrite: splice");
	return -1;
  }

  close(fd_in);
  close(fd_out);
  return 0;
}

