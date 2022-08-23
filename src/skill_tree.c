/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** skill_tree
*/

#include "my_rpg.h"

int vector_test(var_t *var, int i)
{
    int x = var->event.mouseButton.x;
    int y = var->event.mouseButton.y;
    sfVector2f new = {x, y};
    sfVector2f coord = sfSprite_getPosition(var->skill_tree->tree[i]);
    if ((new.x >= coord.x && new.y >= coord.y)
    && (new.x <= coord.x + 70 && new.y <= coord.y + 70))
        return 1;
    return 0;
}

void check_click_tree(var_t *var)
{
    for (int i = 0; i != 4; i++) {
        if (vector_test(var, i) == 1 && var->skill_tree->print == 1) {
            var->skill_tree->skill[i] = 2;
        }
    }
}

void skill_tree_handle(var_t *var)
{
    if (var->skill_tree->print == 1) {
            for (int i = 0; i != 4; i++) {
                sfRenderWindow_drawSprite(var->window, \
                var->skill_tree->tree_sprite[i], NULL);
                (var->skill_tree->skill[i] == 2) ? (sfRenderWindow_drawSprite\
                (var->window, var->skill_tree->tree[i], NULL)) : 0;
            }
    }
}
