/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau [WSL: Ubuntu]
** File description:
** status_menu
*/

#include "my_rpg.h"

char *convert_int_text(int value)
{
    char *str = malloc(sizeof(char) * 4);

    if (value == 100) {
        str[0] = '1';
        str[1] = '0';
        str[2] = '0';
        str[3] = '\0';
    } else if (value <= 99 && value >= 10) {
        str[0] = '0';
        str[1] = (value / 10) + 48;
        str[2] = (value % 10) + 48;
        str[3] = '\0';
    } else {
        str[0] = '0';
        str[1] = '0';
        str[2] = value + 48;
        str[3] = '\0';
    }
    return str;
}
