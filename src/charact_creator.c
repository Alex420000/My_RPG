/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau [WSL: Ubuntu]
** File description:
** charact_creator
*/

#include "my_rpg.h"

void creator_color(var_t *var, sfColor color)
{
    sfSprite_setColor(var->charact->down_atk, color);
    sfSprite_setColor(var->charact->down_idle, color);
    sfSprite_setColor(var->charact->down_walk, color);
    sfSprite_setColor(var->charact->up_atk, color);
    sfSprite_setColor(var->charact->up_idle, color);
    sfSprite_setColor(var->charact->up_walk, color);
    sfSprite_setColor(var->charact->side_atk, color);
    sfSprite_setColor(var->charact->side_idle, color);
    sfSprite_setColor(var->charact->side_walk, color);
}
