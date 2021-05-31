/*
** EPITECH PROJECT, 2021
** concat_array.c
** File description:
** concat 2 array
*/

#include "lib.h"
#include <stdlib.h>

char **concat_array(char **array1, char **array2)
{
    char **new = malloc(sizeof(char *) * (array_len(array1) + array_len(array2)
                                        + 1));
    int i = 0;

    for (; array1[i]; ++i)
        new[i] = my_strdup(array1[i]);
    for (int j = 0; array2[j]; ++i, ++j)
        new[i] = my_strdup(array2[j]);
    new[i] = NULL;
    return new;
}
