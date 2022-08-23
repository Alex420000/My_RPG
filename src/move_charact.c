/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** move_charact
*/

#include "my_rpg.h"

void move_charact4(var_t *var, linked_map_t *cursor)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (sfSprite_getScale(var->charact->side_walk).x == -1.75) {
            sfSprite_setScale(var->charact->side_walk
            , (sfVector2f){1.75, 1.75});
            sfSprite_setScale(var->charact->side_idle
            , (sfVector2f){1.75, 1.75});
            var->charact->pos.x -= 20;
            sfSprite_setPosition(var->charact->side_walk, var->charact->pos);
        }
        if (var->charact->pos.x >= 115)
            var->charact->pos.x -= 3;
        else
            move_charact4_branch(var, cursor);
    }
}

void move_charact3(var_t *var, linked_map_t *cursor, linked_map_t *cursor2)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (sfSprite_getScale(var->charact->side_walk).x == -1.75) {
            sfSprite_setScale(var->charact->side_walk
            , (sfVector2f){1.75, 1.75});
            var->charact->pos.x -= 20;
            sfSprite_setPosition(var->charact->down_walk, var->charact->pos);
        }
        if (var->charact->pos.y <= 390)
            var->charact->pos.y += 3;
        else
            move_charact3_branch(var, cursor2);
    }
    move_charact4(var, cursor);
}

void move_charact2(var_t *var, linked_map_t *cursor, linked_map_t *cursor2)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (sfSprite_getScale(var->charact->side_walk).x == 1.75) {
            sfSprite_setScale(var->charact->side_walk
            , (sfVector2f){-1.75, 1.75});
            sfSprite_setScale(var->charact->side_idle
            , (sfVector2f){-1.75, 1.75});
            var->charact->pos.x += 20;
            sfSprite_setPosition(var->charact->side_walk, var->charact->pos);
        }
        if (var->charact->pos.x <= 590)
            var->charact->pos.x += 3;
        else
            move_charact2_branch(var, cursor2);
    }
    move_charact3(var, cursor, cursor2);
}

void move_charact1(var_t *var, linked_map_t *cursor, linked_map_t *cursor2)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (sfSprite_getScale(var->charact->side_walk).x == -1.75) {
            sfSprite_setScale(var->charact->side_walk
            , (sfVector2f){1.75, 1.75});
            var->charact->pos.x -= 20;
            sfSprite_setPosition(var->charact->up_walk, var->charact->pos);
        }
        if (var->charact->pos.y >= 115)
            var->charact->pos.y -= 3;
        else
            move_charact1_branch(var, cursor);
    }
    move_charact2(var, cursor, cursor2);
}

void move_charact(var_t *var)
{
    linked_map_t *cursor = var->map;
    linked_map_t *cursor2 = var->map;

    while (cursor->next != NULL)
        cursor = cursor->next;
    move_charact1(var, cursor, cursor2);
    move_chara_set_pos(var);
}
