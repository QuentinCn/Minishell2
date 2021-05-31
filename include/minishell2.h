/*
** EPITECH PROJECT, 2021
** minishell2.h
** File description:
** .h of the minishell2 project
*/

#ifndef MINISHELL2
#define MINISHELL2

#include "structure.h"

void open_the_interpreter(char **env);
char *find_act_dir(char *pathname);
char *find_root(char **env);
char *find_old_pathname(char **env, char *pathname);
char *get_input(void);
char **execute_command(command_list_t *command_list, char **env);
char *add_command_prefix(char **command, char **env);
char **do_exit(char **command, char **env);
char **do_cd(char **command, char **env);
char **do_env(char **command, char **env);
char **do_setenv(char **command, char **env);
char **do_unsetenv(char **command, char **env);
command_list_t *create_command_list(char *input);
void free_list(command_list_t *list);
char **execute_without_execve(char **(*function) (char **command, char
    **env), command_list_t *command_list, char **env);
void execute_with_execve(command_list_t *command_list, char **env);

#endif /* !MINISHELL2 */
