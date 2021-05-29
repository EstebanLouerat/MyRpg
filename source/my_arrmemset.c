/*
** EPITECH PROJECT, 2021
** arrmemeset
** File description:
** .c
*/

#include <stdlib.h>
#include <stdio.h>

char **my_arrmemset(int y, int x)
{
    char **tab = (char **) malloc((sizeof(char *) * (y + 1)));

    for (int i = 0; i < y; i++) {
        tab[i] = (char *) malloc((sizeof(char) * (x + 1)));
    }

    return tab;
}