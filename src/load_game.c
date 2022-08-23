/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** load_game
*/

#include "my_rpg.h"

int load_charact(var_t *var, char *buf)
{
    char **split = my_str_to_word_array(buf, ':');

    var->charact->color = my_getnbr(split[0]);
    var->charact->damages = my_getnbr(split[1]);
    var->charact->defense = my_getnbr(split[2]);
    var->charact->life = my_getnbr(split[3]);
    var->charact->pos.x = my_getnbr(split[4]);
    var->charact->pos.y = my_getnbr(split[5]);
    var->charact->which = my_getnbr(split[6]);
    var->charact->interact = my_getnbr(split[7]);
    my_str_to_word_array_free(split);
    return (0);
}

int load_ennemy(var_t *var, char *buf)
{
    char **split = my_str_to_word_array(buf, ':');

    var->ennemy1->dead = my_getnbr(split[8]);
    var->ennemy1->life = my_getnbr(split[9]);
    var->ennemy1->pos.x = my_getnbr(split[10]);
    var->ennemy1->pos.y = my_getnbr(split[11]);
    my_str_to_word_array_free(split);
    return (0);
}

int load_misc(var_t *var, char *buf)
{
    char **split = my_str_to_word_array(buf, ':');

    var->edward->interact = my_getnbr(split[12]);
    var->edward->state = my_getnbr(split[13]);
    var->inventory->item_sword = my_getnbr(split[14]);
    for (int i = 0, k = 15; i < 4; i++, k++)
        var->skill_tree->skill[i] = my_getnbr(split[k]);
    my_str_to_word_array_free(split);
    return (0);
}

int load_map(var_t *var, char *buf)
{
    char **split = my_str_to_word_array(buf, '\n');

    for (int i = 1; var->map; var->map = var->map->next, i++) {
        char **tmp = my_str_to_word_array(split[i], '\n');

        var->map->block = my_getnbr(split[0]);
        var->map->pos.x = my_getnbr(split[1]);
        var->map->pos.y = my_getnbr(split[2]);
        my_str_to_word_array_free(tmp);
    }
    my_str_to_word_array_free(split);
    return (0);
}

int load_game(var_t *var)
{
    char *file = "last_save.txt";
    FILE *fd = fopen(file, "r");
    struct stat sb;
    char **split;

    lstat(file, &sb);

    char buf[sb.st_size];

    if (fread(&buf, 1, sb.st_size, fd) != 0) { 
        split = my_str_to_word_array(buf, '/');
        load_charact(var, split[0]);
        load_ennemy(var, split[0]);
        load_misc(var, split[0]);
        my_str_to_word_array_free(split);
    }   
    fclose(fd);
    return (0);
}
