/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** clock_2
*/

#include "my_rpg.h"

void loop_clock_ennemy(var_t *var)
{
    var->clock_ennemy->seconds =
    var->clock_ennemy->time.microseconds / 1000000.0;
    var->clock_ennemy->time =
    sfClock_getElapsedTime(var->clock_ennemy->clock);
    if (var->clock_ennemy->seconds > 0.05 && var->menu->pause != 1) {
        ennemy_mov(var);
        sfClock_restart(var->clock_ennemy->clock);
    }
}

void loop_clock_anim_player_next(var_t *var)
{
    sfSprite_setScale(var->charact->lifebar->life_s
    , (sfVector2f){0.002 * var->charact->life, 0.2});
    sfSprite_setScale(var->ennemy1->lifebar->life_s
    , (sfVector2f){0.0005 * var->ennemy1->life, 0.05});
    sfClock_restart(var->clock_anim_player->clock);
    if (var->screen >= 10) {
        sfText_setString(var->damages_txt
        , convert_int_text(var->charact->damages));
        sfText_setString(var->defense_txt
        , convert_int_text(var->charact->defense));
        sfText_setString(var->life_txt
        , convert_int_text(var->charact->life));
    }
}

void which_baction_next(var_t *var)
{
    if (var->screen == 1) {
        baction(var, var->res800_btn, 800, "./res/btn/800.png");
        baction(var, var->res1920_btn, 1920, "./res/btn/800.png");
        baction(var, var->cursor_more, 1000, "./res/btn/cursor_more.png");
        baction(var, var->cursor_less, 1001, "./res/btn/cursor_more.png");
    }
    if (var->screen == 10 && var->menu->pause == 1) {
        baction(var, var->menu_btn, 0, "./res/btn/btn_menu.png");
        baction(var, var->htp_btn, 2, "./res/btn/800.png");
        baction(var, var->quit_btn, 3, "./res/btn/btn_menu.png");
    }
    if (var->screen == 5) {
        if (sfClock_getElapsedTime(var->intro->clock).microseconds
        > (sfInt64)(1000)) {
            var->intro->time++;
            sfClock_restart(var->intro->clock);
        }
        sfSprite_setTexture(var->intro->sprite, var->intro->texture, sfTrue);
        sfSprite_setScale(var->intro->sprite, (sfVector2f){0.8, 0.8});
        sfSprite_setPosition(var->intro->sprite, (sfVector2f){225, 170});
        sfSprite_setColor(var->intro->sprite
        , (sfColor){255, 255, 255, var->intro->time});
        sfSprite_setPosition(var->intro->sprite, (sfVector2f){80, 125});
        baction(var, var->skip_btn, 0, "./res/btn/800.png");
    }
}
