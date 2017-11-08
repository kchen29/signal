#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signum) {
  if (signum == SIGINT) {
    printf("SIGINT signal received\n");
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
