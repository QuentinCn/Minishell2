/*
** EPITECH PROJECT, 2021
** array_len.c
** File description:
** gives the len of an array
*/

int array_len(char **array)
{
    int len = 0;

    while (array[++len]);
    return len;
}
