/*
** EPITECH PROJECT, 2021
** showbits
** File description:
** show the bit of a number
*/

#include "my_printf.h"

void showbits(va_list arg)
{
    unsigned int x = va_arg(arg, unsigned int);
    int i = 0;

    for (i = (sizeof(int) * 8) - 1; i >= 0; i -= 1) {
        my_printf("%c", x & (1u << i) ? '1' : '0');
        if (i % 4 == 0)
            my_printf(" ");
    }
    my_printf("\n");
}
