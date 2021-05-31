/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main of the minishell project
*/

#include "minishell2.h"
#include <stddef.h>

int main(int ac, char const * const av[], char **env)
{
    (void) av;
    if (ac != 1)
        return 84;
    env = do_setenv((char *[]){"setenv", "OLDPWD", NULL, NULL}, env);
    open_the_interpreter(env);
    return 0;
}
