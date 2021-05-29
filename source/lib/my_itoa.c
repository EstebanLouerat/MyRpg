/*
** EPITECH PROJECT, 2020
** azerty
** File description:
** azerty
*/
#include "my_rpg.h"

char *my_itoa(int nb)
{
    int count = 0;
    char *str;
    int buffer;

    if (nb < 0) {
        nb = 1 * (-nb);
        my_putchar('-');
    }
    buffer = nb;
    for (; buffer > 0; count++)
        buffer = buffer / 10;
    str = malloc(sizeof(char) * (count + 1));
    str[count] = '\0';

    for (; count > 0; count--) {
        str[count - 1] = nb % 10 + 48;
        nb = nb / 10;
    }
    return (str);
}
