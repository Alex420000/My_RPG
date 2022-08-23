/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** cursor
*/

#include "my_rpg.h"

void set_cursor(var_t *var)
{
    if (var->screen == 0 || var->screen == 1 || var->screen == 2
    || var->screen == 4 || (var->screen == 10 && var->menu->pause == 1)) {
        sfSprite_setPosition(var->mouse->sprite,
        (sfVector2f){var->mouse->pos.x, var->mouse->pos.y - 15});
    }
}
