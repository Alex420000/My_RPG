/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** create_charact
*/

#include "my_rpg.h"

void create_charact_next2(var_t *var)
{
    sfSprite_setTextureRect(var->charact->side_atk
    , var->charact->rect_atk_side);
    var->charact->lifebar = create_lifebar((sfVector2f){20, 20}
    , (sfVector2f){0.2, 0.2});
    var->charact->interact = 0;
    var->charact->color = 0;
    var->charact->which = 3;
    var->charact->damages = 10;
    var->charact->defense = 20;
}

void create_charact_next(var_t *var)
{
    var->charact->life = 100;
    var->charact->side_walk = create_sprite("./res/char/side_walk.png"
    , var->charact->pos, (sfVector2f){1.75, 1.75});
    var->charact->down_walk = create_sprite("./res/char/down_walk.png"
    , var->charact->pos, (sfVector2f){1.75, 1.75});
    var->charact->up_walk = create_sprite("./res/char/up_walk.png"
    , var->charact->pos, (sfVector2f){1.75, 1.75});
    var->charact->down_idle = create_sprite("./res/char/down_idle.png"
    , var->charact->pos, (sfVector2f){1.75, 1.75});
    var->charact->up_idle = create_sprite("./res/char/up_idle.png"
    , var->charact->pos, (sfVector2f){1.75, 1.75});
    var->charact->side_idle = create_sprite("./res/char/side_idle.png"
    , var->charact->pos, (sfVector2f){1.75, 1.75});
    var->charact->down_atk = create_sprite("./res/char/down_attack.png"
    , var->charact->pos, (sfVector2f){1.75, 1.75});
    var->charact->up_atk = create_sprite("./res/char/up_attack.png"
    , var->charact->pos, (sfVector2f){1.75, 1.75});
    var->charact->side_atk = create_sprite("./res/char/side_attack.png"
    , var->charact->pos, (sfVector2f){1.75, 1.75});
    create_charact_next2(var);
}

void create_charact(var_t *var)
{
    var->charact = malloc(sizeof(charact_t));
    var->charact->pos = (sfVector2f){(find_size(1, 0) * 2) + 49
    , find_size(0, 1) * 2};
    var->charact->rect_walk.width = 15;
    var->charact->rect_walk.height = 35;
    var->charact->rect_walk.top = 16;
    var->charact->rect_walk.left = 24;
    var->charact->rect_atk_down.width = 32;
    var->charact->rect_atk_down.height = 40;
    var->charact->rect_atk_down.left = 16;
    var->charact->rect_atk_down.top = 20;
    var->charact->rect_atk_up.width = 34;
    var->charact->rect_atk_up.height = 46;
    var->charact->rect_atk_up.left = 15;
    var->charact->rect_atk_up.top = 4;
    var->charact->rect_atk_side.width = 46;
    var->charact->rect_atk_side.height = 35;
    var->charact->rect_atk_side.left = 3;
    var->charact->rect_atk_side.top = 15;
    create_charact_next(var);
}
