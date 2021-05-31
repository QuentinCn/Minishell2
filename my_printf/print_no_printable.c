/*
** EPITECH PROJECT, 2020
** print_no_printable
** File description:
** display no printable char
*/

#include "my_printf.h"

int nbr_len(int nb)
{
    int i = 0;

    while (nb > 0) {
        nb /= 10;
        i += 1;
    }
    return (i);
}

void print_octal_with_nb(unsigned int nb)
{
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

void print_no_printable(va_list arg)
{
    char *str = va_arg(arg, char *);
    int nbr;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] == 127) {
            my_putstr("\\");
            for (int x = nbr_len(str[i]); x < 3; x += 1)
                my_putstr("0");
            print_octal_with_nb(str[i]);
        } else {
            my_putchar(str[i]);
        }
        i += 1;
    }
}
