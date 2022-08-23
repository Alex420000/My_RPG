/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** ennemy_2
*/

#include "my_rpg.h"

sfVector2f ennemy_mov_cond1(var_t *var, sfVector2f pos, int i
, ennemy_t *list[])
{
    if (pos.x > var->charact->pos.x && pos.x > 100
    && var->charact->pos.x >= pos.x - find_size(1, 0) * 5) {
        pos.x -= 1;
        list[i]->pos.x = pos.x;
    } else if (pos.x < var->charact->pos.x
    && pos.x < 700
    && var->charact->pos.x <= pos.x + find_size(1, 0) * 5) {
        pos.x += 1;
        list[i]->pos.x = pos.x;
    }
    return pos;
}

sfVector2f ennemy_mov_cond2(var_t *var, sfVector2f pos, int i
, ennemy_t *list[])
{
    if (pos.y > var->charact->pos.y && pos.y > 100
    && var->charact->pos.y >= pos.y - find_size(0, 1) * 5) {
        pos.y -= 1;
        list[i]->pos.y = pos.y;
    } else if (pos.y < var->charact->pos.y
    && pos.y < 500
    && var->charact->pos.y <= pos.y + find_size(0, 1) * 5) {
        pos.y += 1;
        list[i]->pos.y = pos.y;
    }
    return pos;
}
