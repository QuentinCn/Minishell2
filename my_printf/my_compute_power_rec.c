/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** put a number to a power
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        nb = 1;
        return (nb);
    } else if (p < 0) {
        nb = 0;
        return (nb);
    } else {
        nb *= my_compute_power_rec(nb, p-1);
    }
    return (nb);
}
