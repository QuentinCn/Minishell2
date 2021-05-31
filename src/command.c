/*
** EPITECH PROJECT, 2021
** command.c
** File description:
** manage the command execution
*/

#include "minishell2.h"
#include "lib.h"

static const tab_on_fct_t TAB[] = {
    (tab_on_fct_t) {"cd", do_cd},
    (tab_on_fct_t) {"env", do_env},
    (tab_on_fct_t) {"setenv", do_setenv},
    (tab_on_fct_t) {"unsetenv", do_unsetenv},
    (tab_on_fct_t) {"exit", do_exit},
};

char **execute_command(command_list_t *command_list, char **env)
{
    for (int i = 0; i < (int)sizeof(TAB) / (int)sizeof(tab_on_fct_t); ++i)
        if (my_strcmp(TAB[i].arg, command_list->command[0]) == 0) {
            env = execute_without_execve(TAB[i].function, command_list,
                            env);
            return env;
        }
    execute_with_execve(command_list, env);
    return env;
}
