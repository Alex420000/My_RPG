/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** create
*/

#include "my_rpg.h"

void create_skill_tree(var_t *var)
{
    var->skill_tree->skill = malloc(sizeof(int) * 10);
    for (int i = 0; i != 10; i++)
        var->skill_tree->skill[i] = 1;
    var->skill_tree->tree = malloc(sizeof(sfSprite *) * 10);
    var->skill_tree->tree[0] = create_sprite("./res/tree/used.png",
    (sfVector2f){200, 100}, (sfVector2f){1, 1});
    var->skill_tree->tree[1] = create_sprite("./res/tree/used.png",
    (sfVector2f){100, 200}, (sfVector2f){1, 1});
    var->skill_tree->tree[2] = create_sprite("./res/tree/used.png",
    (sfVector2f){200, 200}, (sfVector2f){1, 1});
    var->skill_tree->tree[3] = create_sprite("./res/tree/used.png",
    (sfVector2f){300, 200}, (sfVector2f){1, 1});
}

void create_all(var_t *var)
{
    create_start(var);
    create_elems(var);
    create_skill_tree(var);
    read_map(var);
    declare_linked_map(var);
}

void create_start(var_t *var)
{
    create_window(var, 800, 600);
    var->screen = 5;
}

void create_clock(var_t *var)
{
    var->clock_anim_player = malloc(sizeof(myclock_t));
    var->clock_anim_player->clock = sfClock_create();
    var->clock_mov_player = malloc(sizeof(myclock_t));
    var->clock_mov_player->clock = sfClock_create();
    var->clock_ennemy = malloc(sizeof(myclock_t));
    var->clock_ennemy->clock = sfClock_create();
    var->clock_enmy_atck = malloc(sizeof(myclock_t));
    var->clock_enmy_atck->clock = sfClock_create();
}

void create_npcs(var_t *var)
{
    var->edward = create_npc("./res/char/down_idle.png"
    , (sfVector2f){find_size(1, 0) * 9, find_size(0, 1) * 5}
    , (sfVector2f){1.75, 1.75}, (sfColor){50, 50, 255, 255});
    var->edward->interact = 0;
    var->edward->state = 0;
    var->test = create_npc("./res/char/side_idle.png"
    , (sfVector2f){find_size(1, 0) * 2, find_size(0, 1) * 8}
    , (sfVector2f){1.75, 1.75}, (sfColor){255, 50, 50, 255});
}
