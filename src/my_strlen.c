/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** strlen
*/

#include "my_rpg.h"

int my_strlen(char *str)
{
    char const *tmp = str;

    while (*tmp++);
    return (tmp - str - 1);
}

int my_bi_strlen(char **str)
{
    int i = 0;

    for (; *str++; i++);
    return (i);
}
