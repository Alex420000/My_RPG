/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau [WSL: Ubuntu]
** File description:
** buttons2
*/

#include "my_rpg.h"

void else_baction_branch_3(var_t *var, int screen)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && screen == 3000)
        var->editor = 0;
    else if (sfMouse_isButtonPressed(sfMouseLeft) && screen == 3001)
        var->editor = 1;
}

void else_baction_branch_creator2(var_t *var, int screen)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && screen == 2003) {
        creator_color(var, (sfColor){100, 255, 100, 255});
    } else if (sfMouse_isButtonPressed(sfMouseLeft) && screen == 2004) {
        creator_color(var, (sfColor){100, 100, 255, 255});
    } else {
        else_baction_branch_3(var, screen);
    }
}
