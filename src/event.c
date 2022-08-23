/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** event
*/

#include "my_rpg.h"

void check_menu(var_t *var)
{
    if (var->menu->pause == 0 && sfKeyboard_isKeyPressed(sfKeyM)) {
        var->menu->pause++;
    } else if (var->menu->pause == 1 && sfKeyboard_isKeyPressed(sfKeyM)) {
        var->menu->pause--;
    }
}

void event_keypressed_next2_branch(var_t *var)
{
    var->screen == 1 ? var->screen = 0 : 0;
    if (var->screen == 2 && var->menu->pause)
        var->screen = 10;
    else if (var->screen == 2 || var->screen == 6 || var->screen == 7)
        var->screen = 0;
}

void event_keypressed_next2(var_t *var)
{
    if (var->inventory->c == 0 && sfKeyboard_isKeyPressed(sfKeyI)\
    && !var->menu->pause)
        var->inventory->c++;
    else if (var->inventory->c == 1 && sfKeyboard_isKeyPressed(sfKeyI)\
    && !var->menu->pause)
        var->inventory->c--;
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        save_game(var);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        event_keypressed_next2_branch(var);
    }
}

void event_keypressed_next(var_t *var)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && !var->menu->pause)
        var->charact->which = 3;
    else if (sfKeyboard_isKeyPressed(sfKeyUp) && !var->menu->pause)
        var->charact->which = 1;
    if (var->charact->interact == 1 && sfKeyboard_isKeyPressed(sfKeyE)\
    && !var->menu->pause) {
        sfMusic_stop(var->interact_sound);
        sfMusic_play(var->interact_sound);
        var->charact->interact = 2;
    } else if (var->charact->interact == 2 && sfKeyboard_isKeyPressed(sfKeyE)\
    && !var->menu->pause) {
        var->charact->interact = 0;
        var->edward->interact == 3
        ? var->edward->interact = 0, var->edward->state = 1 : 0;
    }
    event_keypressed_next2(var);
}

void event_keypressed(var_t *var)
{
    skill_tree_handling(var);
    check_menu(var);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && !var->menu->pause)
        var->charact->which = 4;
    else if (sfKeyboard_isKeyPressed(sfKeyRight) && !var->menu->pause)
        var->charact->which = 2;
    else
        event_keypressed_next(var);
    if (sfKeyboard_isKeyPressed(sfKeySpace) && !var->menu->pause) {
        sfMusic_stop(var->hit_sound);
        sfMusic_play(var->hit_sound);
        while (var->charact->which < 9)
            var->charact->which += 4;
        var->charact->rect_atk_down.left = 200;
        var->charact->rect_atk_up.left = 200;
        var->charact->rect_atk_side.left = 200;
    }
}
