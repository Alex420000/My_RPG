/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** display
*/

#include "my_rpg.h"

void display_all(var_t *var)
{
    switch (var->screen) {
    case 0:
        display_menu(var);
        break;
    case 1:
        display_options(var);
        break;
    case 2:
        display_htp(var);
        break;
    case 3:
        sfRenderWindow_close(var->window);
        break;
    case 4:
        display_creator(var);
        break;
    default:
        display_all_bis(var);
    }
}

void display_options(var_t *var)
{
    sfRenderWindow_drawSprite(var->window, var->background, NULL);
    sfRenderWindow_drawSprite(var->window, var->res800_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->res1920_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->screen_size, NULL);
    sfRenderWindow_drawSprite(var->window, var->sounds, NULL);
    sfRenderWindow_drawSprite(var->window, var->cursor_more->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->cursor_less->sprite, NULL);
    sfRenderWindow_drawText(var->window, var->vol_txt, NULL);
    sfRenderWindow_drawSprite(var->window, var->mouse->sprite, NULL);
}

void display_menu(var_t *var)
{
    sfSprite_setPosition(var->htp_btn->sprite, (sfVector2f){408, 425});
    sfSprite_setPosition(var->quit_btn->sprite, (sfVector2f){408, 500});
    var->htp_btn->position = (sfVector2f){408, 425};
    var->quit_btn->position = (sfVector2f){408, 500};
    sfRenderWindow_drawSprite(var->window, var->background, NULL);
    sfRenderWindow_drawSprite(var->window, var->logo, NULL);
    sfRenderWindow_drawSprite(var->window, var->play_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->options_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->htp_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->quit_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->edit_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->mouse->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->save_btn->sprite, NULL);
}

void display_ennemies(var_t *var)
{
    ennemy_t *list[] = {var->ennemy1, NULL};

    for (int i = 0; list[i]; i++) {
        if (list[i]->dead == 0)
            display_ennemy(var, list[i]);
    }
}

void display_ennemy(var_t *var, ennemy_t *ennemy)
{
    sfRenderWindow_drawSprite(var->window, ennemy->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, ennemy->lifebar->life_back_s, NULL);
    sfRenderWindow_drawSprite(var->window, ennemy->lifebar->life_s, NULL);
}
