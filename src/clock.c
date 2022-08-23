/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** clock
*/

#include "my_rpg.h"

void loop_all_clock(var_t *var)
{
    loop_clock_anim_player(var);
    loop_clock_mov_player(var);
    loop_clock_ennemy(var);
}

void is_inside(var_t *var)
{
    npc_t *list[] = {var->edward, var->test, NULL};

    for (int i = 0; list[i] && var->charact->interact != 2; i++) {
        sfFloatRect npc_box = sfSprite_getGlobalBounds(list[i]->sprite);
        if (sfFloatRect_intersects(&npc_box, &var->char_box, NULL)) {
            var->charact->interact = 1;
            (i == 0) ? var->edward->interact = 3 : 0;
            return;
        } else {
            var->charact->interact = 0;
            var->edward->interact = (i == 0) ? 0 : 0;
        }
    }
}

void loop_clock_anim_player(var_t *var)
{
    var->clock_anim_player->seconds =
    var->clock_anim_player->time.microseconds / 1000000.0;
    var->clock_anim_player->time =
    sfClock_getElapsedTime(var->clock_anim_player->clock);
    if (var->clock_anim_player->seconds > 0.07) {
        anim_walk(var);
        anim_atk_down(var);
        anim_atk_up(var);
        anim_atk_side(var);
        is_inside(var);
        collision(var);
        loop_clock_anim_player_next(var);
    }
}

void which_baction(var_t *var)
{
    if (var->screen == 0) {
        baction(var, var->play_btn, 4, "./res/btn/800.png");
        baction(var, var->save_btn, 7, "./res/btn/btn_save.png");
        baction(var, var->options_btn, 1, "./res/btn/800.png");
        baction(var, var->htp_btn, 2, "./res/btn/800.png");
        baction(var, var->quit_btn, 3, "./res/btn/800.png");
        baction(var, var->edit_btn, 6, "./res/btn/800.png");
    }
    if (var->screen == 4) {
        baction(var, var->next_btn, 10, "./res/btn/800.png");
        baction(var, var->one_btn, 2001, "./res/btn/cursor_less.png");
        baction(var, var->two_btn, 2002, "./res/btn/cursor_less.png");
        baction(var, var->three_btn, 2003, "./res/btn/cursor_less.png");
        baction(var, var->four_btn, 2004, "./res/btn/cursor_less.png");
    }
    if (var->screen == 6) {
        baction(var, var->ground1_btn, 3000, "./res/grd/grass1.png");
        baction(var, var->ground2_btn, 3001, "./res/grd/grass1.png");
    }
    which_baction_next(var);
}

void loop_clock_mov_player(var_t *var)
{
    var->clock_mov_player->seconds =
    var->clock_mov_player->time.microseconds / 1000000.0;
    var->clock_mov_player->time =
    sfClock_getElapsedTime(var->clock_mov_player->clock);
    if (var->clock_mov_player->seconds > 0.01) {
        which_baction(var);
        set_cursor(var);
        if (var->screen == 1)
            refresh_vol_music(var);
        if (var->screen == 10 && var->menu->pause != 1)
            move_charact(var);
        sfClock_restart(var->clock_mov_player->clock);
    }
}
