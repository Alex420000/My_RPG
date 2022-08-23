/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** move_charact_branch
*/

#include "my_rpg.h"

void move_chara_set_pos(var_t *var)
{
    if (var->screen != 4) {
        sfSprite_setPosition(var->charact->up_walk, var->charact->pos);
        sfSprite_setPosition(var->charact->down_walk, var->charact->pos);
        sfSprite_setPosition(var->charact->side_walk, var->charact->pos);
        sfSprite_setPosition(var->charact->down_idle, var->charact->pos);
        sfSprite_setPosition(var->charact->up_idle, var->charact->pos);
        sfSprite_setPosition(var->charact->side_idle, var->charact->pos);
        sfSprite_setPosition(var->charact->down_atk, var->charact->pos);
        sfSprite_setPosition(var->charact->up_atk, var->charact->pos);
    }
}

void move_charact1_branch(var_t *var, linked_map_t *cursor)
{
    if (cursor->pos.y < find_size(0, 1) * -1)
        move_map_down(var);
    else if (var->charact->pos.y > 5)
        var->charact->pos.y -= 3;
}

void move_charact2_branch(var_t *var, linked_map_t *cursor2)
{
    if (cursor2->pos.x > find_size(1, 0) * 14)
        move_map_left(var);
    else if (var->charact->pos.x < 790)
        var->charact->pos.x += 3;
}

void move_charact3_branch(var_t *var, linked_map_t *cursor2)
{
    if (cursor2->pos.y > find_size(0, 1) * 10)
        move_map_up(var);
    else if (var->charact->pos.y < 540)
        var->charact->pos.y += 3;
}

void move_charact4_branch(var_t *var, linked_map_t *cursor)
{
    if (cursor->pos.x < find_size(1, 0) * -1)
        move_map_right(var);
    else if (var->charact->pos.x > 10)
        var->charact->pos.x -= 3;
}
