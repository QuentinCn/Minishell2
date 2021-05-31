/*
** EPITECH PROJECT, 2020
** print_unsigned_int
** File description:
** display unsigned int
*/

#include "my_printf.h"

void print_unsigned_int(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    unsigned int mod;

    if (nb >= 10)
    {
        mod = (nb % 10);
        nb = (nb - mod) / 10;
        my_put_nbr(nb);
        my_putchar(48 + mod);
    } else
        my_putchar(48 + nb % 10);
}
