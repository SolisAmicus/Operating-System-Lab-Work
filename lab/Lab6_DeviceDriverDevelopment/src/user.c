#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SECRET "\x01\x14\x05\x14"

int main()
{
  int fd = open("/dev/nuke0", O_WRONLY);
  if (fd > 0)
  {
    write(fd, SECRET, sizeof(SECRET) - 1);
    close(fd);
  }
  else
  {
    perror("launcher");
  }
}
