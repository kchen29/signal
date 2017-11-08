#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

static void sighandler(int signum) {
  if (signum == SIGINT) {
    int fd = open("text.txt", O_RDWR | O_CREAT, 0644);
    char text[] = "SIGINT signal received";
    write(fd, text, sizeof(text));
    close(fd);
    
    exit(1);
  } else if (signum == SIGUSR1) {
    printf("SIGUSR1 signal received; PID: %d\n", getpid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while (1) {
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  
  return 0;
}
