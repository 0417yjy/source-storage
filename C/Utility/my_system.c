#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * system() is not recommended in coverity, so this function is the replacement of system().
 * Because calling exec family replaces the original process, it needs to do fork() first and wait for the return.
 * Written by chatGPT
 */
int my_system(const char *cmd) {
    pid_t pid;
    int status;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return -1;
    } else if (pid == 0) {
        // Child process
        execl("/bin/sh", "sh", "-c", cmd, NULL);

        // execl only returns if an error occurred
        fprintf(stderr, "Exec failed\n");
        return -1;
    } else {
        // Parent process
        // Wait for the child process to finish
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            // Child process exited normally
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            // Child process terminated by a signal
            return WTERMSIG(status);
        } else {
            // Something went wrong
            return -1;
        }
    }
}