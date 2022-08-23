/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** music
*/

#include "my_rpg.h"

void refresh_vol_music(var_t *var)
{
    char *str = malloc(sizeof(char) * 4);

    if (var->main_music->vol == 100) {
        str[0] = '1';
        str[1] = '0';
        str[2] = '0';
        str[3] = '\0';
    } else if (var->main_music->vol <= 99 && var->main_music->vol >= 10) {
        str[0] = '0';
        str[1] = (var->main_music->vol / 10) + 48;
        str[2] = (var->main_music->vol % 10) + 48;
        str[3] = '\0';
    } else {
        str[0] = '0';
        str[1] = '0';
        str[2] = var->main_music->vol + 48;
        str[3] = '\0';
    }
    sfText_setString(var->vol_txt, str);
}
