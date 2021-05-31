/*
** EPITECH PROJECT, 2021
** do_cd.c
** File description:
** manage the cd command
*/

#include "minishell2.h"
#include "lib.h"
#include "my_printf.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

static char **do_cd_two_arg(char **command, char **env)
{
    char *pathname = NULL;
    char *last_dir = NULL;

    pathname = getcwd(pathname, PATH_MAX);
    if (my_strcmp(command[1], "-") == 0) {
        last_dir = find_old_pathname(env, getcwd(pathname, PATH_MAX));
        if (my_strcmp(last_dir, "") == 0)
            my_printf("%s: No such file or directory.\n", command[1]);
        chdir(last_dir);
        env = do_setenv((char *[]){"setenv", "OLDPWD", pathname, NULL},
                        env);
        env = do_setenv((char *[]){"setenv", "PWD", last_dir, NULL}, env);
    } else if (command[1][0] == '/') {
        if (chdir(command[1]) == -1) {
            if (access(command[1], X_OK) == 0)
                my_printf("%s: Not a directory.\n", command[1]);
            else
                my_printf("%s: No such file or directory.\n", command[1]);
        }
        env = do_setenv((char *[]){"setenv", "OLDPWD", pathname, NULL},
                        env);
        env = do_setenv((char *[]){"setenv", "PWD",
                getcwd(pathname, PATH_MAX), NULL}, env);
    } else if (chdir(concat_str(getcwd(pathname, PATH_MAX), command[1],
                                '/')) == -1) {
        if (access(concat_str(getcwd(pathname, PATH_MAX), command[1], '/'),
                X_OK) == 0)
            my_printf("%s: Not a directory.\n", command[1]);
        else
            my_printf("%s: No such file or directory.\n", command[1]);
    } else {
        env = do_setenv((char *[]){"setenv", "OLDPWD", pathname, NULL},
                        env);
        env = do_setenv((char *[]){"setenv", "PWD",
                getcwd(pathname, PATH_MAX), NULL}, env);
    }
    return env;
}

static char **do_cd_root(char **env)
{
    char *root = find_root(env);
    char *pathname = NULL;

    if (!root) {
        my_printf("cd: No home directory.\n");
        return env;
    }
    pathname = getcwd(pathname, PATH_MAX);
    if (chdir(root) != -1) {
        env = do_setenv((char *[]){"setenv", "PWD", root, NULL}, env);
        env = do_setenv((char *[]){"setenv", "OLDPWD", pathname, NULL}, env);
    }
    free(pathname);
    return env;
}

char **do_cd(char **command, char **env)
{

    if (array_len(command) == 1 || my_strcmp(command[1], "~") == 0) {
        env = do_cd_root(env);
    } else if (array_len(command) == 2) {
        env = do_cd_two_arg(command, env);
    } else
        my_printf("cd: Too many arguments.\n");
    return env;
}
