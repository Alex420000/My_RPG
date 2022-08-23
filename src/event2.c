/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau [WSL: Ubuntu]
** File description:
** event2
*/

#include "my_rpg.h"

void handle_event_branch(var_t *var)
{
    if (var->event.type == sfEvtKeyPressed)
        event_keypressed(var);
    if (sfMouse_isButtonPressed(sfMouseLeft) && var->screen == 6) {
        var->coos_testa[0] = sfMouse_getPositionRenderWindow(var->window).x;
        var->coos_testa[1] = sfMouse_getPositionRenderWindow(var->window).y;
        var->coos_testa[2]++;
    }
    if (var->event.type == sfEvtMouseButtonPressed)
        check_click_tree(var);
    else if (var->charact->which < 5)
        var->charact->which += 4;
}

void handle_event(var_t *var)
{
    while (sfRenderWindow_pollEvent(var->window, &var->event)) {
        if (var->event.type == sfEvtClosed\
        || sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(var->window);
        else
            handle_event_branch(var);
    }
}

void skill_tree_handling(var_t *var)
{
    if (sfKeyboard_isKeyPressed(sfKeyK)
    && var->skill_tree->print == 0)
        var->skill_tree->print = 1;
    else if (sfKeyboard_isKeyPressed(sfKeyK)
    && var->skill_tree->print == 1)
        var->skill_tree->print = 0;
}
