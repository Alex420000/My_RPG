/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau [WSL: Ubuntu]
** File description:
** display2
*/

#include "my_rpg.h"

int contains_coos(const sfTexture *texture, sfVector2f pos, int *coos)
{
    int pos_x = sfTexture_getSize(texture).x * 0.15;
    int pos_y = sfTexture_getSize(texture).y * 0.15;

    if (coos[0] >= pos.x && coos[0] <= pos.x + pos_x && coos[1] >= pos.y
    && coos[1] <= pos.y + pos_y) {
        return (1);
    }
    return (0);
}

void display_edit_map_branch(var_t *var, linked_map_t *tmp)
{
        if (var->editor == 0) {
            tmp->sprite = create_sprite("./res/grd/grass1.png"
            , tmp->pos, (sfVector2f){0.15, 0.15});
        }
        if (var->editor == 1) {
            tmp->sprite = create_sprite("./res/grd/sand.png"
            , tmp->pos, (sfVector2f){0.15, 0.15});
        }
}

void display_edit_map(var_t *var)
{
    for (linked_map_t *tmp = var->map; tmp; tmp = tmp->next) {
        sfRenderWindow_drawSprite(var->window, tmp->sprite, NULL);
        if (contains_coos(sfSprite_getTexture(tmp->sprite), tmp->pos,\
        var->coos_testa) != 0 && var->coos_testa[2] > 1) {
            display_edit_map_branch(var, tmp);
            tmp->block = 9 - 48;
        }
    }
    sfRenderWindow_drawSprite(var->window, var->ground1_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->ground2_btn->sprite, NULL);
}

void display_creator(var_t *var)
{
    sfSprite_setScale(var->charact->down_walk, (sfVector2f){5, 5});
    sfSprite_setPosition(var->charact->down_walk, (sfVector2f){350, 200});
    sfRenderWindow_drawSprite(var->window, var->background, NULL);
    sfRenderWindow_drawSprite(var->window, var->charact->down_walk, NULL);
    sfRenderWindow_drawSprite(var->window, var->next_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->one_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->two_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->three_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->four_btn->sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->mouse->sprite, NULL);
}

void display_all_bis(var_t *var)
{
    switch (var->screen) {
        case 6:
            display_edit_map(var);
         break;
        case 7:
            handle_save(var);
            break;
        case 10:
            display_game(var);
            break;
        case 5:
            sfRenderWindow_drawSprite(var->window, var->intro->sprite, NULL);
            sfRenderWindow_drawSprite(var->window, var->skip_btn->sprite, NULL);
            break;
    }
}
