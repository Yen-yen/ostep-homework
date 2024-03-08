#include <unistd.h>
#include <stdio.h>  // perror()
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main(int argc, char *argv[])
{
  printf("hello (pid:%d)\n", (int)getpid());
  int rc = fork();
  if (rc < 0)
  {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    // child (new process)
    printf("child (pid:%d)\n", (int)getpid());
    execl("/bin/ls", "ls", "-l", NULL);

    // execlp("ls", "ls", "-l", NULL);
    // execle("/bin/ls", "ls", "-l", NULL, NULL);
    // execv("/bin/ls", (char *[]){"ls", "-l", NULL});
    // execvp("ls", (char *[]){"ls", "-l", NULL});
    // execvpe("ls", (char *[]){"ls", "-l", NULL}, environ);
    perror("Return from exec not expected");
    exit(EXIT_FAILURE);
  }
  else
  {
    // parent goes down this path (main)
    printf("parent of %d (pid:%d)\n", rc, (int)getpid());
  }
  return 0;
}
