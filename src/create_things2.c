/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** create_things2
*/

#include "my_rpg.h"

npc_t *create_npc(char *what, sfVector2f position, sfVector2f scale
, sfColor color)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->sprite = create_sprite(what, position, scale);
    sfSprite_setColor(npc->sprite, color);
    npc->pos = position;
    npc->interact = 0;
    return npc;
}

ennemy_t *create_ennemy(char *what, sfVector2f position, sfVector2f scale)
{
    ennemy_t *enmy = malloc(sizeof(ennemy_t));

    enmy->sprite = create_sprite(what, position, scale);
    enmy->life = 100;
    enmy->pos = position;
    enmy->dead = 0;
    enmy->lifebar = create_lifebar((sfVector2f){enmy->pos.x - 25
    , enmy->pos.y - 10}, (sfVector2f){0.05, 0.05});
    sfSprite_setColor(enmy->sprite, (sfColor){0, 0, 0, 255});
    return enmy;
}

mouse_t *create_mouse(var_t *var)
{
    mouse_t *m = malloc(sizeof(mouse_t));
    m->sprite = sfSprite_create();
    m->texture = sfTexture_createFromFile("./res/bg/cursor.png", NULL);
    sfRenderWindow_setMouseCursorVisible(var->window, sfTrue);
    sfSprite_setTexture(m->sprite, m->texture, sfTrue);
    sfSprite_setScale(m->sprite, (sfVector2f){0.2, 0.2});
    return m;
}

music_t *create_music(char *what, int vol)
{
    music_t *mu = malloc(sizeof(music_t));

    mu->music = sfMusic_createFromFile(what);
    mu->vol = vol;
    return mu;
}
