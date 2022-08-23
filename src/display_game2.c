/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau [WSL: Ubuntu]
** File description:
** display_game2
*/

#include "my_rpg.h"

void handle_menu(var_t *var)
{
    if (var->menu->pause) {
        sfSprite_setPosition(var->htp_btn->sprite, (sfVector2f){308, 350});
        sfSprite_setPosition(var->quit_btn->sprite, (sfVector2f){508, 350});
        var->htp_btn->position = (sfVector2f){308, 350};
        var->quit_btn->position = (sfVector2f){508, 350};
        sfRenderWindow_drawSprite(var->window, var->back_blacksquare, NULL);
        sfRenderWindow_drawSprite(var->window, var->menu->pause_sprite, NULL);
        sfRenderWindow_drawSprite(var->window, var->htp_btn->sprite, NULL);
        sfRenderWindow_drawSprite(var->window, var->quit_btn->sprite, NULL);
        sfRenderWindow_drawSprite(var->window, var->menu_btn->sprite, NULL);
        sfRenderWindow_drawText(var->window, var->menu->text, NULL);
        sfRenderWindow_drawSprite(var->window, var->mouse->sprite, NULL);
    }
}
