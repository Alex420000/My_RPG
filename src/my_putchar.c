/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** my_putchar
*/

#include "my_rpg.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
