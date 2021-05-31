/*
** EPITECH PROJECT, 2021
** command_format.c
** File description:
** manage command format
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "my_printf.h"

static char *get_path_from_env(char **env)
{
    char *path = NULL;

    for (int i = 0; env[i]; i += 1) {
        if (my_strlen(env[i]) < 5)
            continue;
        else if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
                env[i][3] == 'H' && env[i][4] == '=') {
            path = my_strdup(env[i]);
            return path;
        }
    }
    return path;
}

char *add_command_prefix(char **command, char **env)
{
    char *path = get_path_from_env(env);
    char **prefix = NULL;
    char *result_prefix = NULL;

    if (access(command[0], F_OK) == 0)
        return command[0];
    if (path == NULL)
        return NULL;
    prefix = my_str_to_word_array(&path[5], ':');
    for (int i = 0; prefix[i]; i += 1) {
        if (access(concat_str(prefix[i], command[0], '/'), F_OK) == 0) {
            result_prefix = my_strdup(prefix[i]);
            free_array(prefix);
            return concat_str(result_prefix, command[0], '/');
        }
    }
    free_array(prefix);
    my_printf("%s: Command not found.\n", command[0]);
    return NULL;
}

static int len_until_delimiter(char *input)
{
    int i = 0;

    for (; input[i] != ';' && input[i] != '<' && input[i] != '>' &&
        input[i] != '|' && input[i] != '\0'; ++i);
    return i + 1;
}

static char *get_element_in_input(char *input)
{
    char *new = my_strdup(input);
    int i = 0;

    for (; input[i] != ';' && input[i] != '<' && input[i] != '>' &&
        input[i] != '|' && input[i] != '\0'; ++i);
    new[i] = '\0';
    return new;
}

command_list_t *create_command_list(char *input)
{
    command_list_t *command_list = NULL;
    char *new_element = NULL;
    char **command = NULL;
    char *delimiter = NULL;

    for (int i = 0; i < my_strlen(input); i += len_until_delimiter(&input[i])) {
        for (; (input[i] == ' ' || input[i] == '<' || input[i] == '>' ||
                input[i] == '|' || input[i] == ';') && input[i] != '\0'; ++i);
        new_element = get_element_in_input(&input[i]);
        command = my_str_to_word_array(new_element, ' ');
        delimiter = my_strdup(&input[i + my_strlen(new_element)]);
        if (my_strlen(delimiter) >= 2)
            delimiter[(delimiter[1] == '<' || delimiter[1] == '>') ? 2 : 1] =
                '\0';
        command_list = add_inlist(command_list, command, delimiter,
            len_list(command_list));
        free(new_element);
    }
    return command_list;
}
