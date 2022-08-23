/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** collision
*/

#include "my_rpg.h"

void collision(var_t *var)
{
    var->char_box = sfSprite_getGlobalBounds(var->charact->down_idle);
    ennemy_t *list[] = {var->ennemy1, NULL};

    if (var->skill_tree->skill[2] == 2)
        var->charact->damages = 20;
    (var->skill_tree->skill[1] == 2) ? (var->charact->defense = 40) : 0;
    for (int i = 0; list[i]; i++) {
        var->enmy_box = sfSprite_getGlobalBounds(list[i]->sprite);
        var->enmy_box.width += 40;
        var->enmy_box.height += 20;
        if (sfKeyboard_isKeyPressed(sfKeySpace)
        && sfFloatRect_intersects(&var->char_box, &var->enmy_box, NULL)
        && list[i]->life > 0 && !var->menu->pause) {
            list[i]->life -= var->charact->damages;
        }
        if (list[i]->life <= 0) {
            list[i]->dead = 1;
        }
    }
}
