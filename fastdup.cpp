#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sendfile.h>

#define BUF_SIZE 1024

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
  
  int fd_out = creat(argv[2], 0644);
  if(fd_out == -1){
    perror("readwrite: creat");
    return -1;
  }

  ssize_t bytes = 1;
  while(bytes > 0) {
    bytes = sendfile(fd_out, fd_in, 0, BUF_SIZE);
  }

  if(bytes == -1){
    perror("readwrite: splice");
	return -1;
  }

  close(fd_in);
  close(fd_out);
  return 0;
}

