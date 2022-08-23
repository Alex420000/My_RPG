/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** display_game
*/

#include "my_rpg.h"

void handle_inventory(var_t *var)
{
    if (var->inventory->c == 1 && var->menu->pause != 1) {
        sfRenderWindow_drawSprite(var->window, var->back_blacksquare, NULL);
        sfRenderWindow_drawSprite(var->window, var->inventory->bg_sprite
        , NULL);
        sfRenderWindow_drawSprite(var->window, var->status_menu, NULL);
        sfRenderWindow_drawText(var->window, var->damages_txt, NULL);
        sfRenderWindow_drawText(var->window, var->defense_txt, NULL);
        sfRenderWindow_drawText(var->window, var->life_txt, NULL);
        if (var->inventory->item_sword == 1)
            sfRenderWindow_drawSprite(var->window, var->inventory->sword_sprite
            , NULL);
        sfRenderWindow_drawText(var->window, var->inventory->text, NULL);
    }
}

void display_game3_cond(var_t *var)
{
    if (var->edward->interact == 3 && var->edward->state == 0) {
        sfRenderWindow_drawText(var->window
        , var->speeches->edward_speech_first, NULL);
        var->inventory->item_sword = 1;
    } else if (var->edward->interact == 3 && var->edward->state == 1) {
        sfRenderWindow_drawText(var->window
        , var->speeches->edward_speech_second, NULL);
    }
}

void display_game3(var_t *var)
{
    if (var->menu->pause == 0 && var->charact->interact == 2) {
        sfRenderWindow_drawSprite(var->window, var->back_blacksquare, NULL);
        sfRenderWindow_drawSprite(var->window, var->blacksquare, NULL);
        sfRenderWindow_drawText(var->window, var->press_txt, NULL);
        display_game3_cond(var);
    }
    handle_inventory(var);
    handle_menu(var);
}

void display_game2(var_t *var)
{
    sfRenderWindow_drawSprite(var->window, var->edward->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->test->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->charact->lifebar->life_back_s
    , NULL);
    sfRenderWindow_drawSprite(var->window, var->charact->lifebar->life_s
    , NULL);
    display_ennemies(var);
    if (var->menu->pause == 0 && var->charact->interact == 1) {
        sfText_setPosition(var->interact_txt, (sfVector2f)
        {var->charact->pos.x - 45, var->charact->pos.y + 60});
        sfRenderWindow_drawText(var->window, var->interact_txt, NULL);
    }
    display_game3(var);
}

void display_game(var_t *var)
{
    sfSprite_setScale(var->charact->down_walk, (sfVector2f){1.75, 1.75});
    display_map(var);
    switch (var->charact->which) {
    case 2:
        sfRenderWindow_drawSprite(var->window, var->charact->side_walk, NULL);
        break;
    case 3:
        sfRenderWindow_drawSprite(var->window, var->charact->down_walk, NULL);
        break;
    case 4:
        sfRenderWindow_drawSprite(var->window, var->charact->side_walk, NULL);
        break;
    case 5:
        sfRenderWindow_drawSprite(var->window, var->charact->up_idle, NULL);
        break;
    default:
        switch_display_game(var);
        break;
    }
    display_game2(var);
}
