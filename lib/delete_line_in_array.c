/*
** EPITECH PROJECT, 2021
** delete_line_in_array.c
** File description:
** delete a line in an array
*/

#include "lib.h"
#include <stdlib.h>
#include <stddef.h>

char **delete_line_in_array(char **array, int pos)
{
    char **new = malloc(sizeof(char *) * array_len(array));
    int j = 0;

    for (int i = 0; array[i]; ++i, ++j) {
        if (i == pos && array[i + 1])
            i += 1;
        else if (i == pos && !array[i + 1])
            break;
        new[j] = array[i];
    }
    new[j] = NULL;
    return new;
}
