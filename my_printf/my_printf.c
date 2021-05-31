/*
** EPITECH PROJECT, 2020
** my_prinf
** File description:
** display
*/

#include "my_printf.h"
#include <unistd.h>

static const tab_t FUNCTIONS[] = {
    (tab_t) {'c', print_char},
    (tab_t) {'s', print_string},
    (tab_t) {'i', print_number},
    (tab_t) {'d', print_number},
    (tab_t) {'o', print_octal},
    (tab_t) {'b', showbits},
    (tab_t) {'u', print_unsigned_int},
    (tab_t) {'%', print_modulo},
    (tab_t) {'S', print_no_printable},
    (tab_t) {'f', my_putfloat},
};

int do_loop_for_printf(va_list arg, char const *str, int i)
{
    int space = 0;

    for (int j = 0; j < sizeof(FUNCTIONS) / sizeof(tab_t); j += 1) {
        if (str[i + 1] == ' ') {
            while (str[i + 1] == ' ' && str[i] != '\0')
                i += 1;
            space = 1;
        }
        if (str[i + 1] == FUNCTIONS[j].flag) {
            if (space == 1) {
                my_putstr(" ");
                space = 0;
            }
            FUNCTIONS[j].tab(arg);
            i += 1;
            break;
        } else if (j + 1 == sizeof(FUNCTIONS) / sizeof(tab_t))
            write(1, &str[i], 1);
    }
    return (i);
}

int my_printf(char const *str, ...)
{
    va_list arg;

    va_start(arg, str);
        for (int i = 0; str[i] != '\0'; i += 1) {
            if (str[i] == '%') {
                i = do_loop_for_printf(arg, str, i);
            } else
                write(1, &str[i], 1);
        }
    va_end(arg);
    return (0);
}
