/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** create_things
*/

#include "my_rpg.h"

sfSprite *create_sprite(char *what, sfVector2f position, sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(what, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

btn_t *create_btn(char *what, sfVector2f position, sfVector2f scale)
{
    btn_t *btn = malloc(sizeof(btn_t));

    btn->position = position;
    btn->scale = scale;
    btn->sprite = create_sprite(what, btn->position, btn->scale);
    btn->color = (sfColor){255, 255, 255, 200};
    return btn;
}

void create_window(var_t *var, int x, int y)
{
    sfVideoMode mode = {x, y, 32};

    var->window = sfRenderWindow_create(mode, "My RPG", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(var->window, 144);
    var->win_size = sfRenderWindow_getSize(var->window);
}

int find_size(int x, int y)
{
    int size = 0;
    sfTexture *texture = sfTexture_createFromFile("./res/grd/grass1.png"
    , NULL);
    if (x == 1)
        size = sfTexture_getSize(texture).x * 0.15;
    else if (y == 1)
        size = sfTexture_getSize(texture).y * 0.15;
    return size;
}

lifebar_t *create_lifebar(sfVector2f position, sfVector2f scale)
{
    lifebar_t *lifebar = malloc(sizeof(lifebar_t));

    lifebar->life_s = create_sprite("./res/char/life.png"
    , position, scale);
    lifebar->life_back_s = create_sprite("./res/char/life_back.png"
    , position, scale);
    return lifebar;
}
