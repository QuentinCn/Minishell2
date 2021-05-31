/*
** EPITECH PROJECT, 2020
** print_binary
** File description:
** print binary
*/

#include "my_printf.h"
#include <unistd.h>
#include <stdlib.h>

int binary_len(unsigned int nb)
{
    int i = 0;

    while (my_compute_power_rec(2, i) <= nb)
        i += 1;
    return (i);
}

void print_binary(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    char *nbr = malloc(sizeof(char) * (binary_len(nb) + 1));

    if (nb == 0)
        my_put_nbr(0);
    for (unsigned int i = 0; nb > 0; i += 1) {
        nbr[i] = nb % 2 + '0';
        nbr[i + 1] = '\0';
        nb /= 2;
    }
    nbr = my_revstr(nbr);
    my_putstr(nbr);
    free(nbr);
}
