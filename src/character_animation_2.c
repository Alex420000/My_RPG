/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** character_animation_2
*/

#include "my_rpg.h"

void set_rect_all(var_t *var)
{
    sfSprite_setTextureRect(var->charact->side_walk, var->charact->rect_walk);
    sfSprite_setTextureRect(var->charact->down_walk, var->charact->rect_walk);
    sfSprite_setTextureRect(var->charact->up_walk, var->charact->rect_walk);
    sfSprite_setTextureRect(var->charact->down_idle, var->charact->rect_walk);
    sfSprite_setTextureRect(var->charact->up_idle, var->charact->rect_walk);
    sfSprite_setTextureRect(var->charact->side_idle, var->charact->rect_walk);
    sfSprite_setTextureRect(var->edward->sprite, var->charact->rect_walk);
    sfSprite_setTextureRect(var->test->sprite, var->charact->rect_walk);
    sfSprite_setTextureRect(var->ennemy1->sprite, var->charact->rect_walk);
}

void set_pos_all(var_t *var)
{
    sfSprite_setPosition(var->charact->up_atk, var->charact->pos);
    sfSprite_setPosition(var->charact->down_atk, var->charact->pos);
}

void anim_atk_down_branch(var_t *var)
{
    if (var->charact->which == 11) {
        sfSprite_setTextureRect(var->charact->down_atk
        , var->charact->rect_atk_down);
        var->charact->which = 7;
    }
}

void anim_atk_up_branch(var_t *var)
{
    if (var->charact->which == 9) {
        sfSprite_setTextureRect(var->charact->up_atk
        , var->charact->rect_atk_up);
        var->charact->which = 5;
    }
}

void anim_atk_side_branch(var_t *var)
{
    if (var->charact->which == 10 || var->charact->which == 12) {
        sfSprite_setTextureRect(var->charact->side_atk
        , var->charact->rect_atk_side);
        var->charact->which -= 4;
    }
}
