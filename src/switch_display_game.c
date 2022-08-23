/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** switch_display_game
*/

#include "my_rpg.h"

void switch_display_game_3(var_t *var)
{
    switch (var->charact->which) {
    case 11:
        sfSprite_setPosition(var->charact->down_atk
        , (sfVector2f){var->charact->pos.x - 13, var->charact->pos.y + 5});
        sfRenderWindow_drawSprite(var->window, var->charact->down_atk, NULL);
        break;
    case 12:
        sfSprite_setScale(var->charact->side_atk, (sfVector2f){1.75, 1.75});
        sfSprite_setPosition(var->charact->side_atk
        , (sfVector2f){var->charact->pos.x - 35, var->charact->pos.y});
        sfRenderWindow_drawSprite(var->window, var->charact->side_atk, NULL);
        break;
    case 1:
        sfRenderWindow_drawSprite(var->window, var->charact->up_walk, NULL);
        break;
    }
}

void switch_display_game2(var_t *var)
{
    switch (var->charact->which) {
    case 9:
        sfSprite_setPosition(var->charact->up_atk
        , (sfVector2f){var->charact->pos.x - 15, var->charact->pos.y - 20});
        sfRenderWindow_drawSprite(var->window, var->charact->up_atk, NULL);
        break;
    case 10:
        sfSprite_setScale(var->charact->side_atk, (sfVector2f){-1.75, 1.75});
        sfSprite_setPosition(var->charact->side_atk
        , (sfVector2f){var->charact->pos.x + 35, var->charact->pos.y});
        sfRenderWindow_drawSprite(var->window, var->charact->side_atk, NULL);
        break;
    default:
        switch_display_game_3(var);
        break;
    }
}

void switch_display_game(var_t *var)
{
    switch (var->charact->which) {
    case 6:
        sfSprite_setScale(var->charact->side_idle, (sfVector2f){-1.75, 1.75});
        sfRenderWindow_drawSprite(var->window, var->charact->side_idle, NULL);
        break;
    case 7:
        sfRenderWindow_drawSprite(var->window, var->charact->down_idle, NULL);
        break;
    case 8:
        sfSprite_setScale(var->charact->side_idle, (sfVector2f){1.75, 1.75});
        sfRenderWindow_drawSprite(var->window, var->charact->side_idle, NULL);
        break;
    default:
        switch_display_game2(var);
        break;
    }
}
