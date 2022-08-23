/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** free
*/

#include "my_rpg.h"

void free_all(var_t *var)
{
    sfSprite *list[] = {var->charact->side_walk, var->charact->down_walk
    , var->charact->up_walk, var->charact->down_atk, var->charact->side_atk
    , var->charact->up_atk, var->charact->down_idle, var->charact->side_idle
    , var->charact->up_idle, var->mouse->sprite, NULL};
    sfText *list2[] = {var->life_txt, var->press_txt, var->vol_txt
    , var->damages_txt, var->defense_txt, var->interact_txt, NULL};
    sfMusic *list3[] = {var->main_music->music, var->hit_sound
    , var->interact_sound, NULL};

    for (int i = 0; list[i]; sfSprite_destroy(list[i]), i++);
    for (int i = 0; list2[i]; sfText_destroy(list2[i]), i++);
    for (int i = 0; list3[i]; sfMusic_destroy(list3[i]), i++);
    free(var->filemap->buffer);
    sfRenderWindow_destroy(var->window);
}
