/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** ennemy
*/

#include "my_rpg.h"

void ennemy_follow(var_t *var, sfVector2f pos, int i
, ennemy_t *list[])
{
    sfSprite_setColor(list[i]->sprite, (sfColor){0, 0, 0, 255});
    pos = ennemy_mov_cond1(var, pos, i, list);
    pos = ennemy_mov_cond2(var, pos, i, list);
    sfSprite_setPosition(list[i]->sprite, pos);
    sfSprite_setPosition(list[i]->lifebar->life_back_s
    , (sfVector2f){pos.x - 25, pos.y - 10});
    sfSprite_setPosition(list[i]->lifebar->life_s
    , (sfVector2f){pos.x - 25, pos.y - 10});
}

void ennemy_mov_if(var_t *var, sfVector2f pos, int i
, ennemy_t *list[])
{
    if (var->charact->pos.x <= pos.x + find_size(1, 0)
    && var->charact->pos.x >= pos.x - find_size(1, 0)
    && var->charact->pos.y <= pos.y + find_size(0, 1)
    && var->charact->pos.y >= pos.y - find_size(0, 1)) {
        if (sfKeyboard_isKeyPressed(sfKeySpace) && !var->menu->pause) {
            sfSprite_setColor(list[i]->sprite, (sfColor){255, 0, 0, 255});
        } else {
            sfSprite_setColor(list[i]->sprite, (sfColor){0, 0, 0, 255});
        }
        ennemy_atck(var, list[i]);
    } else
        ennemy_follow(var, pos, i, list);
}

void ennemy_mov_branch(var_t *var, sfVector2f pos, int i
, ennemy_t *list[i])
{
    pos = sfSprite_getPosition(list[i]->sprite);
    if (var->screen >= 10
    && var->charact->pos.x >= pos.x - find_size(1, 0) * 5
    && var->charact->pos.x <= pos.x + find_size(1, 0) * 5
    && var->charact->pos.y >= pos.y - find_size(0, 1) * 5
    && var->charact->pos.y <= pos.y + find_size(0, 1) * 5)
        ennemy_mov_if(var, pos, i, list);
}

void ennemy_mov(var_t *var)
{
    ennemy_t *list[] = {var->ennemy1, NULL};
    sfVector2f pos;

    for (int i = 0; list[i]; i++)
        if (list[i]->dead == 0)
            ennemy_mov_branch(var, pos, i, list);
}

void ennemy_atck(var_t *var, ennemy_t *enmy)
{
    var->clock_enmy_atck->seconds =
    var->clock_enmy_atck->time.microseconds / 1000000.0;
    var->clock_enmy_atck->time =
    sfClock_getElapsedTime(var->clock_enmy_atck->clock);
    if (var->clock_enmy_atck->seconds > 1.0) {
        var->charact->life -= 4;
        sfClock_restart(var->clock_enmy_atck->clock);
    }
}
