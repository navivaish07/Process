#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pid;

    printf("Before fork\n");

    pid = fork();  // Create child process

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    } 
    else if (pid == 0) {
        // Child Process
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        printf("Executing 'ls' using exec...\n");
        execl("/bin/ls", "ls", NULL);

        // Runs only if exec fails
        printf("Exec failed\n");
        exit(0);
    } 
    else {
        // Parent Process
        printf("\n--- Parent Process ---\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        wait(NULL);  // Wait for child

        printf("Child process completed\n");
        printf("Parent exiting...\n");
        exit(0);
    }

    return 0;
}
