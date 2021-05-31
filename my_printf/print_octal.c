/*
** EPITECH PROJECT, 2020
** print_octal
** File description:
** print octal
*/

#include "my_printf.h"

void print_octal(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    int octal = 0;
    int i = 10;

    octal += (nb % 8);
    nb /= 8;
    while (nb % 8 != 0) {
        octal += (nb % 8) * i;
        nb /= 8;
        i *= 10;
    }
    my_put_nbr(octal);
}
