/*
** EPITECH PROJECT, 2020
** putchar
** File description:
** affiche caractere
*/

#include "my_rpg.h"

void my_putchar(char c)
{
    write(1, &c , 1);

    return;
}
