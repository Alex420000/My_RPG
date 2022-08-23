/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau [WSL: Ubuntu]
** File description:
** display3
*/

#include "my_rpg.h"

void handle_save(var_t *var)
{
    const sfTexture *texture = NULL;
    int pos_x = 0;
    int pos_y = 0;

    sfRenderWindow_drawSprite(var->window, var->background, NULL);
    sfRenderWindow_drawSprite(var->window, var->save_logo, NULL);
    texture = sfSprite_getTexture(var->save_logo);
    pos_x = sfTexture_getSize(texture).x * 0.15;
    pos_y = sfTexture_getSize(texture).y * 0.18;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (var->mouse->pos.x >= 275 && var->mouse->pos.x
        <= 275 + pos_x && var->mouse->pos.y >= 20
        && var->mouse->pos.y <= 20 + pos_y) {
            load_game(var);
        }
    }
}

void display_htp(var_t *var)
{
    sfRenderWindow_drawSprite(var->window, var->background, NULL);
    sfRenderWindow_drawSprite(var->window, var->explain, NULL);
    sfRenderWindow_drawSprite(var->window, var->htp_logo, NULL);
    sfRenderWindow_drawSprite(var->window, var->mouse->sprite, NULL);
}
