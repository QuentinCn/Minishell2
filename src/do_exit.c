/*
** EPITECH PROJECT, 2021
** do_exit.c
** File description:
** do the exit command
*/

#include "lib.h"
#include "my_printf.h"
#include <stdlib.h>

char **do_exit(char **command, char **env)
{
    (void)env;
    if (array_len(command) != 1)
        my_printf("exit: Expression Syntax.\n");
    else {
        free_array(command);
        my_printf("exit\n");
        exit(0);
    }
    return env;
}
