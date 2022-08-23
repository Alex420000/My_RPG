/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** character_animation
*/

#include "my_rpg.h"

void anim_walk(var_t *var)
{
    if (var->charact->rect_walk.top == 16) {
        if (var->charact->rect_walk.left < 200)
            var->charact->rect_walk.left += 64;
        else {
            var->charact->rect_walk.left = 24;
            var->charact->rect_walk.top = 80;
        }
    } else {
        if (var->charact->rect_walk.left < 20)
            var->charact->rect_walk.left += 64;
        else {
            var->charact->rect_walk.top = 16;
            var->charact->rect_walk.left = 24;
        }
    }
    set_rect_all(var);
}

void anim_atk_down(var_t *var)
{
    if (var->charact->rect_atk_down.left == 200) {
        var->charact->rect_atk_down.left = 16;
        var->charact->rect_atk_down.top = 20;
    } else if (var->charact->rect_atk_down.left == 16
    && var->charact->rect_atk_down.top == 20) {
        var->charact->rect_atk_down.left = 80;
        var->charact->rect_atk_down.top = 20;
    } else {
        var->charact->rect_atk_down.left = 16;
        var->charact->rect_atk_down.top = 80;
        anim_atk_down_branch(var);
    }
    sfSprite_setTextureRect(var->charact->down_atk
    , var->charact->rect_atk_down);
}

void anim_atk_up(var_t *var)
{
    if (var->charact->rect_atk_up.left == 200) {
        var->charact->rect_atk_up.left = 15;
        var->charact->rect_atk_up.top = 4;
    } else if (var->charact->rect_atk_up.left == 15
    && var->charact->rect_atk_up.top == 4) {
        var->charact->rect_atk_up.left = 79;
        var->charact->rect_atk_up.top = 4;
    } else {
        var->charact->rect_atk_up.left = 15;
        var->charact->rect_atk_up.top = 68;
        anim_atk_up_branch(var);
    }
    sfSprite_setTextureRect(var->charact->up_atk, var->charact->rect_atk_up);
}

void anim_atk_side(var_t *var)
{
    if (var->charact->rect_atk_side.left == 200) {
        var->charact->rect_atk_side.left = 3;
        var->charact->rect_atk_side.top = 15;
    } else if (var->charact->rect_atk_side.left == 3
    && var->charact->rect_atk_side.top == 15) {
        var->charact->rect_atk_side.left = 67;
        var->charact->rect_atk_side.top = 15;
    } else {
        var->charact->rect_atk_side.left = 3;
        var->charact->rect_atk_side.top = 79;
        anim_atk_side_branch(var);
    }
    sfSprite_setTextureRect(var->charact->side_atk
    , var->charact->rect_atk_side);
}
