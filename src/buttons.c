/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** buttons
*/

#include "my_rpg.h"

void else_baction_branch_creator(var_t *var, int screen)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && screen == 2001) {
        creator_color(var, (sfColor){255, 255, 255, 255});
    } else if (sfMouse_isButtonPressed(sfMouseLeft) && screen == 2002) {
        creator_color(var, (sfColor){255, 100, 100, 255});
    } else {
        else_baction_branch_creator2(var, screen);
    }
}

void else_baction_branch(var_t *var, int screen)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && screen == 1920) {
        sfRenderWindow_setSize(var->window, (sfVector2u){1920, 1080});
    } else if (sfMouse_isButtonPressed(sfMouseLeft) && screen == 800) {
        sfRenderWindow_setSize(var->window, (sfVector2u){800, 600});
    } else {
        else_baction_branch_creator(var, screen);
    }
}

void elseif_baction_branch(var_t *var, int screen)
{
    if (screen == 1000 && var->main_music->vol < 100) {
        var->main_music->vol++;
        sfMusic_setVolume(var->main_music->music, var->main_music->vol);
    } else if (screen == 1001 && var->main_music->vol > 0) {
        var->main_music->vol--;
        sfMusic_setVolume(var->main_music->music, var->main_music->vol);
    }
}

void if_baction(var_t *var, btn_t *button, int screen)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(var->interact_sound);
        sfMusic_play(var->interact_sound);
    }
    sfSprite_setColor(button->sprite, (sfColor){255, 255, 255, 255});
    if (sfMouse_isButtonPressed(sfMouseLeft) && screen < 100)
        var->screen = screen;
    else if (sfMouse_isButtonPressed(sfMouseLeft) && screen >= 1000
    && screen <= 1001)
        elseif_baction_branch(var, screen);
    else
        else_baction_branch(var, screen);
}

void baction(var_t *var, btn_t *button, int screen, char *what)
{
    sfTexture *texture = sfTexture_createFromFile(what, NULL);
    int pos_x = sfTexture_getSize(texture).x * button->scale.x;
    int pos_y = sfTexture_getSize(texture).y * button->scale.y;

    if (var->mouse->pos.x >= button->position.x && var->mouse->pos.x
    <= button->position.x + pos_x && var->mouse->pos.y >= button->position.y
    && var->mouse->pos.y <= button->position.y + pos_y) {
        if_baction(var, button, screen);
    } else
        sfSprite_setColor(button->sprite, (sfColor){255, 255, 255, 150});
}
