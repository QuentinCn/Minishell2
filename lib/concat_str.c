/*
** EPITECH PROJECT, 2021
** concat_str.c
** File description:
** concact 2 string
*/

#include "lib.h"
#include "my_printf.h"
#include <stdlib.h>

char *concat_str(char *str1, char *str2, char concat)
{
    char *new = malloc(my_strlen(str1) + my_strlen(str2) + 2);
    int i = 0;

    for (; str1[i] != '\0'; ++i)
        new[i] = str1[i];
    if (concat != '\0')
        new[i++] = concat;
    for (int j = 0; str2[j] != '\0'; ++i, ++j)
        new[i] = str2[j];
    new[i] = '\0';
    return new;
}
