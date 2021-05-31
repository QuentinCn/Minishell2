/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** display
*/

#include <unistd.h>

int my_strlen(char *str);

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
