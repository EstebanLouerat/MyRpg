/*
** EPITECH PROJECT, 2020
** azerty
** File description:
** azerty
*/

#include "my_rpg.h"

int my_atoi(char const *str)
{
    int res;
    int i;

    for (i = 0; str[i] != '\0'; i++)
        res = res * 10 + str[i] - 48;

    return (res);
}
