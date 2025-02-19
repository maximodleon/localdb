#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

struct s {
  int x;
  char str[100];
};

int main() {

  struct s a;
  strcpy(a.str, "aaaa");
  a.x = 1000000;

  int fd = open("myfile.db", O_WRONLY | O_CREAT | O_APPEND, 0644);
  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }


  ssize_t bytes_written = write(fd, &a, sizeof(a));
  close(fd);
  printf("here");
}
