/*
** EPITECH PROJECT, 2021
** input.c
** File description:
** manage the input
*/

#include <stdio.h>
#include "my_printf.h"

static char *sup_in_str(char *str, int pos)
{
    char *tmp = str;

    for (int i = pos; str[i] != '\0'; i += 1)
        str[i] = tmp[i + 1];
    return str;
}

static char *clean_input(char *input)
{
    for (int i = 0; input[i] != '\0'; i += 1) {
        if ((input[i] == ' ' || input[i] == '\t') && (i == 0 || input[i + 1] ==
        ' ' || input[i + 1] == '\t' || input[i + 1] == '\0' || input[i + 1] ==
        '\n' || input[i + 1] == ';' || input[i + 1] == '|' || input[i + 1] ==
        '<' || input[i + 1] == '>'))
            input = sup_in_str(input, i--);
        else if (input[i] == '\t')
            input[i] = ' ';
    }
    input[my_strlen(input) - 1] = '\0';
    return input;
}

char *get_input(void)
{
    size_t size = 0;
    char *input = NULL;

    if (getline(&input, &size, stdin) < 0) {
        my_printf("\nexit\n");
        return NULL;
    }
    return clean_input(input);
}
