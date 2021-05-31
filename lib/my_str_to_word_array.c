/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** transform a string into an array
*/

#include <stdlib.h>

static int count_separation(char *str, char separation)
{
    int nb_separation = 0;

    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] == separation)
            nb_separation += 1;
    return nb_separation;
}

static int len_until_separation(char *str, int k, char separation)
{
    int i = 0;

    for (; str[i + k] != '\0' && str[i + k] != separation; i += 1);

    return i;
}

char **my_str_to_word_array(char *str, char separation)
{
    char **array = malloc(sizeof(char *) * (count_separation(str, separation)
        + 2));
    int k = 0;
    int len = 0;

    for (int i = 0; i < count_separation(str, separation) + 1; i += 1) {
        len = len_until_separation(str, k, separation);
        array[i] = malloc(len + 1);
        for (int j = 0; j < len && str[k] != separation && str[k] != '\0'; j +=
                1, k += 1) {
            array[i][j] = str[k];
            array[i][j + 1] = '\0';
        }
        k += 1;
        array[i + 1] = NULL;
    }
    return array;
}
