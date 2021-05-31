/*
** EPITECH PROJECT, 2021
** cut_env_line.c
** File description:
** cut the env's line to get the name
*/

char *cut_env_line(char *env_line)
{
    int i = 0;

    while (env_line[i] != '=' && env_line[i] != '\0')
        ++i;
    env_line[i] = '\0';
    return env_line;
}
