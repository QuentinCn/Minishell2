/*
** EPITECH PROJECT, 2021
** interpreter.c
** File description:
** manage the interpreter of the minishell2
*/

#include "my_printf.h"
#include "minishell2.h"
#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <linux/limits.h>

void open_the_interpreter(char **env)
{
    char *input = NULL;
    char *pathname = NULL;
    command_list_t *command_list = NULL;

    my_printf("\033[1m[%s]\033[00m\033[1;96m§\033[00m ",
        find_act_dir(pathname));
    input = get_input();
    if (!input)
        return;
    command_list = create_command_list(input);
    for (command_list_t *tmp = command_list; tmp; tmp = tmp->next)
        env = execute_command(tmp, env);
    free(input);
    free(pathname);
    free_list(command_list);
    open_the_interpreter(env);
}
