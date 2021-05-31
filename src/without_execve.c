/*
** EPITECH PROJECT, 2021
** without_execve.c
** File description:
** manage the command without execve
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minishell2.h"
#include "lib.h"
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

static char **execute_with_descending(char **(*function) (char **command, char
    **env), command_list_t *command_list, char **env, bool two_descending)
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
        return NULL;
    env = function(command_list->command, env);
    if (dup2(dup_stdout, STDOUT_FILENO) == -1)
        return NULL;
    if (close(dup_stdout) == -1)
        return NULL;
    if (close(file_fd) == -1)
        return NULL;
    command_list = command_list->next;
    return env;
}

char **execute_without_execve(char **(*function) (char **command, char
        **env), command_list_t *command_list, char **env)
{
    if (my_strcmp(command_list->delimiter, ">") == 0 && command_list->next)
        env = execute_with_descending(function, command_list, env, false);
    else if (my_strcmp(command_list->delimiter, ">>") == 0 &&
            command_list->next)
        env = execute_with_descending(function, command_list, env, true);
    else
        env = function(command_list->command, env);
    return env;
}
