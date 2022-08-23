/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** main
*/

#include "my_rpg.h"

void auto_resize(var_t *var)
{
    var->win_size = sfRenderWindow_getSize(var->window);

    if (var->win_size.x > 1920 || var->win_size.y > 1080) {
        sfRenderWindow_setSize(var->window, (sfVector2u){1920, 1080});
    } else if (var->win_size.x < 800 || var->win_size.y < 600)
        sfRenderWindow_setSize(var->window, (sfVector2u){800, 600});
}

void printd_expla(void)
{
    my_putstr("Welcome to World Of Warcraft Not Classic.\n");
    my_putstr("Let's save the world, beat the ennemies.");
    my_putstr(" and enhance your power.\n");
    my_putstr("Write './my_rpg' to lauch the game.\n");
    my_putstr("use the arrow to move, space to attack !\n");
    my_putstr("You will have more detail on how to play in the game.\n");
}

void infinite_loop(void)
{
    var_t *var = malloc(sizeof(var_t));

    create_all(var);
    sfMusic_play(var->main_music->music);
    while (sfRenderWindow_isOpen(var->window)) {
        var->mouse->pos = sfRenderWindow_mapPixelToCoords(var->window
        , sfMouse_getPositionRenderWindow(var->window), var->view);
        loop_all_clock(var);
        auto_resize(var);
        handle_event(var);
        sfRenderWindow_clear(var->window, sfBlack);
        display_all(var);
        skill_tree_handle(var);
        sfRenderWindow_display(var->window);
    }
    free_all(var);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp("-h", av[1]) == 0)
        printd_expla();
    else if (ac == 1 && my_strcmp("my_rpg", av[0]))
        infinite_loop();
    else {
        my_putstr("Try ./my_rpg -h\n");
        return -1;
    }
    return 0;
}
