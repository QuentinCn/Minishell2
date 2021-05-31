/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** duplicate a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    char *dest = malloc(my_strlen(str) + 1);
    int i = 0;

    for (; str[i] != '\0'; i += 1)
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}
