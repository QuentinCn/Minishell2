/*
** EPITECH PROJECT, 2021
** my_putfloat
** File description:
** display a float
*/

#include "my_printf.h"

void my_putfloat(va_list arg)
{
    double nb = va_arg(arg, double);
    long int u = nb;
    long int d = (nb * 100000000 - u * 100000000) * 100000000;

    if (d % 10 >= 5)
        d += 10;
    d /= 10;
    while (d % 10 == 0)
        d /= 10;
    my_printf("x = %d.%d", u, d);
}
