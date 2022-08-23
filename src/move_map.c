/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** event_main_clock
*/

#include "my_rpg.h"

void move_elem(var_t *var, int x, int y)
{
    sfSprite *list[] = {var->edward->sprite, var->test->sprite
    , var->ennemy1->sprite, var->ennemy1->lifebar->life_back_s
    , var->ennemy1->lifebar->life_s, NULL};
    sfVector2f pos;

    for (int i = 0; list[i]; i++) {
        pos = sfSprite_getPosition(list[i]);
        pos.x += x;
        pos.y += y;
        sfSprite_setPosition(list[i], pos);
    }
}

void move_map_right(var_t *var)
{
    linked_map_t *cursor = var->map;

    while (cursor != NULL) {
        cursor->pos.x += 5;
        sfSprite_setPosition(cursor->sprite, cursor->pos);
        cursor = cursor->next;
    }
    move_elem(var, 5, 0);
}

void move_map_left(var_t *var)
{
    linked_map_t *cursor = var->map;

    while (cursor != NULL) {
        cursor->pos.x -= 5;
        sfSprite_setPosition(cursor->sprite, cursor->pos);
        cursor = cursor->next;
    }
    move_elem(var, -5, 0);
}

void move_map_up(var_t *var)
{
    linked_map_t *cursor = var->map;

    while (cursor != NULL) {
        cursor->pos.y -= 5;
        sfSprite_setPosition(cursor->sprite, cursor->pos);
        cursor = cursor->next;
    }
    move_elem(var, 0, -5);
}

void move_map_down(var_t *var)
{
    linked_map_t *cursor = var->map;

    while (cursor != NULL) {
        cursor->pos.y += 5;
        sfSprite_setPosition(cursor->sprite, cursor->pos);
        cursor = cursor->next;
    }
    move_elem(var, 0, 5);
}
