/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** linked_list
*/

#include "my_rpg.h"

void new_node_map(var_t *var, char *what, sfVector2f pos, int block)
{
    linked_map_t *new = malloc(sizeof(linked_map_t));

    new->sprite = create_sprite(what, pos, (sfVector2f){0.15, 0.15});
    new->pos = pos;
    new->next = var->map;
    new->block = block;
    var->map = new;
}

void cond_linked_list(var_t *var, char type, sfVector2f pos)
{
    switch (type) {
    case '0':
        new_node_map(var, "./res/grd/grass1.png", pos, type - 48);
        break;
    case '1':
        new_node_map(var, "./res/grd/sand.png", pos, type - 48);
        break;
    case '9':
        new_node_map(var, "./res/grd/block.png", pos, type - 48);
        break;
    }
}

void declare_linked_map(var_t *var)
{
    sfVector2f pos = (sfVector2f){find_size(1, 0) * -1, find_size(0, 1) * -1};

    var->map = NULL;
    for (int i = 0; var->filemap->buffer[i]; i++) {
        if (var->filemap->buffer[i] == '\n') {
            i++;
            pos.x = find_size(1, 0) * -1;
            pos.y += find_size(0, 1);
        }
        cond_linked_list(var, var->filemap->buffer[i], pos);
        pos.x += find_size(1, 0);
    }
}

void display_map(var_t *var)
{
    linked_map_t *cursor = var->map;

    while (cursor != NULL) {
        sfRenderWindow_drawSprite(var->window, cursor->sprite, NULL);
        cursor = cursor->next;
    }
}
