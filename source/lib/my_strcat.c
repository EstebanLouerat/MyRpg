/*
** EPITECH PROJECT, 2020
** B-PSU-101-LYN-1-1-minishell1-thomas.gonzalez
** File description:
** my_strcat.c
*/

#include <stdlib.h>

static int my_strlen(char *str)
{
    int nb = 0;

    for (nb; str[nb]; nb++);
    return nb;
}

char *my_strcat_no_f(char *s1, char *s2)
{
    int s1_size = my_strlen(s1);
    int s2_size = my_strlen(s2);
    char *result = malloc(sizeof(char) * (s1_size + s2_size + 1));
    int loop = 0;

    while (s1[loop] != 0) {
        result[loop] = s1[loop];
        loop++;
    }
    for (int j = 0; s2[j] != 0; j++) {
        result[loop] = s2[j];
        loop++;
    }
    result[loop] = 0;
    return result;
}

char *my_strcat_f1(char *s1, char *s2)
{
    int s1_size = my_strlen(s1);
    int s2_size = my_strlen(s2);
    char *result = malloc(sizeof(char) * (s1_size + s2_size + 1));
    int loop = 0;

    while (s1[loop] != 0) {
        result[loop] = s1[loop];
        loop++;
    }
    for (int j = 0; s2[j] != 0; j++) {
        result[loop] = s2[j];
        loop++;
    }
    result[loop] = 0;
    free(s1);
    return result;
}

char *my_strcat_f2(char *s1, char *s2)
{
    int s1_size = my_strlen(s1);
    int s2_size = my_strlen(s2);
    char *result = malloc(sizeof(char) * (s1_size + s2_size + 1));
    int loop = 0;

    while (s1[loop] != 0) {
        result[loop] = s1[loop];
        loop++;
    }
    for (int j = 0; s2[j] != 0; j++) {
        result[loop] = s2[j];
        loop++;
    }
    result[loop] = 0;
    free(s2);
    return result;
}

char *my_strcat_f(char *s1, char *s2)
{
    int s1_size = my_strlen(s1);
    int s2_size = my_strlen(s2);
    char *result = malloc(sizeof(char) * (s1_size + s2_size + 1));
    int loop = 0;

    while (s1[loop] != 0) {
        result[loop] = s1[loop];
        loop++;
    }
    for (int j = 0; s2[j] != 0; j++) {
        result[loop] = s2[j];
        loop++;
    }
    result[loop] = 0;
    free(s1);
    free(s2);
    return result;
}