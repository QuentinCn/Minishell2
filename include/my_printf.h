/*
** EPITECH PROJECT, 2020
** bsprintf
** File description:
** prototype for my_printf
*/

#ifndef MY_PRINTF
#define MY_PRINTF
#include <stdarg.h>

typedef struct tab
{
    char flag;
    void (*tab)(va_list arg);
}tab_t;

int my_getnbr(char *nbr);
int my_compute_power_rec(int n, int p);
void my_putchar(char c);
int my_putstr(char *str);
int my_put_nbr(int nb);
int my_strlen(char *str);
char *my_revstr(char *str);
int my_getnbr_from(char const *str, int x);
int my_printf(char const *str, ...);
unsigned int nbr_hexa_len(unsigned int nb);
void print_char(va_list arg);
void print_string(va_list arg);
void print_number(va_list arg);
void print_octal(va_list arg);
void print_hexa(va_list arg);
void print_big_hexa(va_list arg);
void print_ptr(va_list arg);
void print_unsigned_int(va_list arg);
void print_modulo(va_list arg);
void print_no_printable(va_list arg);
void showbits(va_list arg);
void my_putfloat(va_list arg);
#endif /* !MY_PRINTF */
