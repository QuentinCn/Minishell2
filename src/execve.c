/*
** EPITECH PROJECT, 2021
** execve.c
** File description:
** manage execve
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minishell2.h"
#include "lib.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>

static void execve_with_descending(char *complete_command, command_list_t
    *command_list, char **env, bool two_descending)
{
    int file_fd;
    int dup_stdout = dup(STDOUT_FILENO);

    if (!two_descending)
        file_fd = open(command_list->next->command[0], O_RDWR | O_TRUNC |
            O_CREAT, 0755);
    else
        file_fd = open(command_list->next->command[0], O_RDWR | O_APPEND |
            O_CREAT, 0755);
    if (dup2 (file_fd, STDOUT_FILENO) == -1)
        return;
    execve(complete_command, command_list->command, env);
    if (dup2(dup_stdout, STDOUT_FILENO) == -1)
        return;
    if (close(dup_stdout) == -1)
        return;
    if (close(file_fd) == -1)
        return;
    command_list = command_list->next;
}

static void handle_execve_macro(int status)
{
    if (status == 0)
        return;
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV) {
            write(2, "Segmentation fault", 18);
            if (WCOREDUMP(status))
                write(2, " (core dumped)", 14);
            write(2, "\n", 1);
            if (isatty(STDIN_FILENO) != 1)
                exit(139);
        } else if (WTERMSIG(status) == SIGABRT) {
            write(2, "Abort", 5);
            if (WCOREDUMP(status))
                write(2, " (core dumped)", 14);
            write(2, "\n", 1);
        }
        if (status == 136) {
            write(2, "Floating exception (core dumped)\n", 33);
            if (isatty(STDIN_FILENO) != 1)
                exit(136);
        }
    }
}

void execute_with_execve(command_list_t *command_list, char **env)
{
    int f_pid = 0;
    char *complete_command = add_command_prefix(command_list->command, env);
    int status = 0;

    if (complete_command == NULL)
        return;
    f_pid = fork();
    if (f_pid == 0) {
        if (my_strcmp(command_list->delimiter, ">") == 0 && command_list->next)
            execve_with_descending(complete_command, command_list, env, false);
        else if (my_strcmp(command_list->delimiter, ">>") == 0 &&
                command_list->next)
            execve_with_descending(complete_command, command_list, env, true);
        else
            execve(complete_command, command_list->command, env);
        exit(84);
    }
    wait(&status);
    handle_execve_macro(status);
}
