#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

void executeCommand(char *command, char **argv);

void searchAndExecute(char *command, char **argv, char *dir);

void tokenizeInput(char *lineptr, char ***argv, int *num_tokens);

int executeShell(char *prompt, char *lineptr);

#endif /* MAIN_H */
