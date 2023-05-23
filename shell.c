#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define BUFFER_SIZE 1024
#define PROMPT "$"
/* 
 * print_environment - prints the current environment
 */
void print_environment(char **env)
{
while (*env)
{
printf("%s\n", *env);
env++;
}
}
/**
 * execute_command - executes command using execvp
 * @command: command to be executed
 * @args: arguments for the command
 */
void execute_command(char *command, char **args)
{
if(execvyp(command, args) == -1)
{
perror(command);
exit(EXIT_FAILURE);
}
}
/**
 * main - entry point of the shell program
 * Return: Always 0
 */
int main(void)
{
char command[BUFFER_SIZE];
char *args[BUFFER_SIZE];
pid_t pid;
int status;
while (1)
{
printf(PROMPT);
if (fgets(command, BUFFER_SIZE, stdin) == NULL)
{
printf("\n");
break;
}
/* remove new line character from the command */
command[strcspn(command, "\n")] = '\0';
/* tokenize command into arguments */
char *token = strtok(command, " ");
int i = 0;
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;
/* handle built-in commands */
if (strcmp(args[0], "exit") == 0)
{
break;
}
else if (strcmp(args[0], "env") == 0)
{
extern char **environ;
char **env = environ;
while (*env)
{
printf("%s\n", *env);
env++;
}
}
else
{
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror(args[0]);
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
}
return (0);
}
