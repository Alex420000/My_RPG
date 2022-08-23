/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** save
*/

#include "my_rpg.h"

int save_charact(var_t *var, FILE *fd)
{
    fwrite(int_to_string(var->charact->color), 1, 1, fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->charact->damages), 1, 2, fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->charact->defense), 1, 2, fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->charact->life), 1
    , my_strlen(int_to_string(var->charact->life)), fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->charact->pos.x), 1
    , my_strlen(int_to_string(var->charact->pos.x)), fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->charact->pos.y), 1
    , my_strlen(int_to_string(var->charact->pos.y)), fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->charact->which), 1, 1, fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->charact->interact), 1, 1, fd);
    return (0);
}

int save_enemy(var_t *var, FILE *fd)
{
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->ennemy1->dead), 1, 1, fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->ennemy1->life), 1
    , my_strlen(int_to_string(var->ennemy1->life)), fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->ennemy1->pos.x), 1
    , my_strlen(int_to_string(var->ennemy1->pos.x)), fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->ennemy1->pos.y), 1
    , my_strlen(int_to_string(var->ennemy1->pos.y)), fd);
    return (0);
}

int save_misc(var_t *var, FILE *fd)
{
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->edward->interact), 1, 1, fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->edward->state), 1, 1, fd);
    fwrite(":", 1, 1, fd);
    fwrite(int_to_string(var->inventory->item_sword), 1, 1, fd);
    fwrite(":", 1, 1, fd);
    for (int i = 0; i < 4; i++) {
        fwrite(int_to_string(var->skill_tree->skill[i]), 1, 1, fd);
        fwrite(":", 1, 1, fd);
    }
    return (0);
}

int save_map(var_t *var, FILE *fd)
{
    int len = 0;

    for (linked_map_t *tmp = var->map; tmp; tmp = tmp->next, len++);
    fwrite("/", 1, 1, fd);
    fwrite(int_to_string(len), 1, my_strlen(int_to_string(len)), fd);
    for (linked_map_t *tmp = var->map; tmp; tmp = tmp->next) {
        fwrite("\n", 1, 1, fd);
        fwrite(int_to_string(tmp->block), 1, 1, fd);
        fwrite(",", 1, 1, fd);
        fwrite(int_to_string(tmp->pos.x), 1
        , my_strlen(int_to_string(tmp->pos.x)), fd);
        fwrite(",", 1, 1, fd);
        fwrite(int_to_string(tmp->pos.y), 1
        , my_strlen(int_to_string(tmp->pos.y)), fd);
    }
    return (0);
}

int save_game(var_t *var)
{
    char *file = "last_save.txt";
    FILE *fd = fopen(file, "w");

    save_charact(var, fd);
    save_enemy(var, fd);
    save_misc(var, fd);
    save_map(var, fd);
    fclose(fd);
    return (0);
}
