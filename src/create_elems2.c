/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau [WSL: Ubuntu]
** File description:
** create_elems2
*/

#include "my_rpg.h"

void create_buttons_menu(var_t *var)
{
    var->play_btn = create_btn("./res/btn/btn_play.png"
    , (sfVector2f){208, 350}, (sfVector2f){0.12, 0.15});
    var->save_btn = create_btn("./res/btn/btn_save.png"
    , (sfVector2f){408, 350}, (sfVector2f){0.12, 0.15});
    var->options_btn = create_btn("./res/btn/btn_options.png"
    , (sfVector2f){208, 425}, (sfVector2f){0.12, 0.15});
    var->htp_btn = create_btn("./res/btn/btn_htp.png"
    , (sfVector2f){408, 425}, (sfVector2f){0.12, 0.15});
    var->edit_btn = create_btn("./res/btn/btn_editor.png"
    , (sfVector2f){208, 500}, (sfVector2f){0.12, 0.15});
    var->quit_btn = create_btn("./res/btn/btn_quit.png"
    , (sfVector2f){408, 500}, (sfVector2f){0.12, 0.15});
    var->menu_btn = create_btn("./res/btn/btn_menu.png"
    , (sfVector2f){108, 350}, (sfVector2f){0.12, 0.15});
    var->ground1_btn = create_btn("./res/grd/grass1.png"
    , (sfVector2f){250, 500}, (sfVector2f){0.15, 0.15});
    var->ground2_btn = create_btn("./res/grd/sand.png"
    , (sfVector2f){450, 500}, (sfVector2f){0.15, 0.15});
    var->skip_btn = create_btn("./res/btn/btn_skip.png"
    , (sfVector2f){600, 540}, (sfVector2f){0.12, 0.15});
}

void create_status_menu(var_t *var)
{
    var->damages_txt = sfText_create();
    sfText_setFont(var->damages_txt, var->font);
    sfText_setString(var->damages_txt, convert_int_text(10));
    sfText_setPosition(var->damages_txt, (sfVector2f){125, 248});
    sfText_setCharacterSize(var->damages_txt, 20);
    var->defense_txt = sfText_create();
    sfText_setFont(var->defense_txt, var->font);
    sfText_setString(var->defense_txt, convert_int_text(20));
    sfText_setPosition(var->defense_txt, (sfVector2f){125, 269});
    sfText_setCharacterSize(var->defense_txt, 20);
    var->life_txt = sfText_create();
    sfText_setFont(var->life_txt, var->font);
    sfText_setString(var->life_txt, convert_int_text(100));
    sfText_setPosition(var->life_txt, (sfVector2f){125, 290});
    sfText_setCharacterSize(var->life_txt, 20);
}
