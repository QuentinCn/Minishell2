/*
** EPITECH PROJECT, 2021
** path
** File description:
** manage path
*/

#include "my_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <linux/limits.h>

char *find_act_dir(char *pathname)
{
    int last_parenthese = -1;

    pathname = getcwd(pathname, PATH_MAX);
    for (int i = 0; pathname[i] != '\0'; i += 1)
        if (pathname[i] == '/')
            last_parenthese = i;
    pathname = &pathname[last_parenthese + 1];
    return (pathname);
}

char *find_root(char **env)
{
    for (int i = 0; env[i]; ++i)
        if (my_strlen(env[i]) >= 5)
            if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M' &&
            env[i][3] == 'E' && env[i][4] == '=')
                return &env[i][5];
    return NULL;
}

char *find_old_pathname(char **env, char *pathname)
{
    char *old = "OLDPWD";

    for (int i = 0; env[i]; i += 1)
        for (int j = 0; env[i][j] != '\0' && old[j] != '\0'; j += 1) {
            if (env[i][j] != old[j])
                break;
            if (env[i][j + 1] == '=' && old[j + 1] == '\0')
                return (&env[i][j + 2]);
        }
    return (pathname);
}
