/*
** EPITECH PROJECT, 2021
** env.c
** File description:
** manage the env
*/

#include "my_printf.h"
#include "lib.h"
#include <stdlib.h>

char **do_env(char **command, char **env)
{
    if (array_len(command) > 1)
        my_printf("env: '%s': No such file or directory\n", command[1]);
    else
        for (int i = 0; env[i]; ++i)
            my_printf("%s\n", env[i]);
    return env;
}

static char **add_in_env(char **command, char **env)
{
    char *line_name = NULL;

    for (int i = 0; env[i]; ++i) {
        line_name = cut_env_line(my_strdup(env[i]));
        if (my_strcmp(line_name, command[1]) == 0) {
            env[i] = concat_str(command[1], (command[2]) ? command[2] : "",
                            '=');
            free(line_name);
            return env;
        }
        free(line_name);
    }
    env = concat_array(env, (char *[]){concat_str(command[1], (command[2]) ?
                                                command[2] : "", '='), NULL});
    return env;
}

static char **remove_in_env(char **command, char **env)
{
    char *line_name = NULL;

    for (int j = 1; command[j]; ++j)
        for (int i = 0; env[i]; ++i) {
            line_name = cut_env_line(my_strdup(env[i]));
            if (my_strcmp(line_name, command[j]) == 0)
                env = delete_line_in_array(env, i--);
            free(line_name);
        }
    return env;
}

char **do_setenv(char **command, char **env)
{
    if (array_len(command) == 1)
        do_env(command, env);
    else if (array_len(command) > 3)
        my_printf("setenv: Too many arguments.\n");
    else
        env = add_in_env(command, env);
    return env;
}

char **do_unsetenv(char **command, char **env)
{
    if (array_len(command) == 1)
        my_printf("unsetenv: Too few arguments.\n");
    else
        env = remove_in_env(command, env);
    return env;
}
