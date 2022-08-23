/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** create_elems
*/

#include "my_rpg.h"

void create_elem5(var_t *var)
{
    var->coos_testa = malloc(sizeof(int) * 3);
    var->coos_testa[0] = 0;
    var->coos_testa[1] = 0;
    var->coos_testa[2] = 0;
    var->skill_tree = malloc(sizeof(tree_t));
    var->skill_tree->print = 0;
    var->skill_tree->tree_sprite = malloc(sizeof(sfSprite *) * 5);
    var->skill_tree->tree_sprite[0] = create_sprite("./res/tree/skill1.png"
    , (sfVector2f){200, 100}, (sfVector2f){1, 1});
    var->skill_tree->tree_sprite[1] = create_sprite("./res/tree/skill2.png"
    , (sfVector2f){100, 200}, (sfVector2f){1, 1});
    var->skill_tree->tree_sprite[2] = create_sprite("./res/tree/skill3.png"
    , (sfVector2f){200, 200}, (sfVector2f){1, 1});
    var->skill_tree->tree_sprite[3] = create_sprite("./res/tree/skill4.png"
    , (sfVector2f){300, 200}, (sfVector2f){1, 1});
    var->save_logo = create_sprite("res/btn/btn_save.png"
    , (sfVector2f){275, 20}, (sfVector2f){0.15, 0.18});
    var->intro = create_intro(var);
    create_status_menu(var);
}

void create_elem4(var_t *var)
{
    sfText_setFont(var->vol_txt, var->font);
    sfText_setString(var->vol_txt, "100");
    sfText_setCharacterSize(var->vol_txt, 40);
    sfText_setPosition(var->vol_txt, (sfVector2f){360, 440});
    var->main_music = create_music("./res/music/music.wav", 100);
    sfMusic_setLoop(var->main_music->music, sfTrue);
    var->menu = create_menu(var);
    var->speeches = create_speeches(var);
    var->next_btn = create_btn("./res/btn/btn_next.png"
    , (sfVector2f){308, 500}, (sfVector2f){0.12, 0.15});
    var->one_btn = create_btn("./res/btn/cursor_1.png"
    , (sfVector2f){310, 425}, (sfVector2f){0.25, 0.25});
    var->two_btn = create_btn("./res/btn/cursor_2.png"
    , (sfVector2f){360, 425}, (sfVector2f){0.25, 0.25});
    var->three_btn = create_btn("./res/btn/cursor_3.png"
    , (sfVector2f){410, 425}, (sfVector2f){0.25, 0.25});
    var->four_btn = create_btn("./res/btn/cursor_4.png"
    , (sfVector2f){460, 425}, (sfVector2f){0.25, 0.25});
    create_elem5(var);
}

void create_elem3(var_t *var)
{
    var->screen_size = create_sprite("./res/btn/screen_size.png"
    , (sfVector2f){270, 75}, (sfVector2f){0.16, 0.19});
    var->sounds = create_sprite("./res/btn/sounds.png"
    , (sfVector2f){270, 325}, (sfVector2f){0.16, 0.19});
    var->cursor_more = create_btn("./res/btn/cursor_more.png"
    , (sfVector2f){460, 450}, (sfVector2f){0.25, 0.25});
    var->cursor_less = create_btn("./res/btn/cursor_less.png"
    , (sfVector2f){300, 450}, (sfVector2f){0.25, 0.25});
    var->mouse = create_mouse(var);
    var->inventory = create_inventory(var);
    var->explain = create_sprite("res/bg/explain.png"
    , (sfVector2f){75, 100}, (sfVector2f){0.8, 0.8});
    var->htp_logo = create_sprite("res/btn/btn_htp.png"
    , (sfVector2f){275, 20}, (sfVector2f){0.15, 0.18});
    var->vol_txt = sfText_create();
    var->editor = 0;
    create_elem4(var);
}

void create_elems2(var_t *var)
{
    var->font = sfFont_createFromFile("./res/font/font.ttf");
    var->interact_txt = sfText_create();
    sfText_setFont(var->interact_txt, var->font);
    sfText_setString(var->interact_txt, "Interact [E]");
    sfText_setCharacterSize(var->interact_txt, 15);
    var->press_txt = sfText_create();
    sfText_setFont(var->press_txt, var->font);
    sfText_setString(var->press_txt, "Press [E]");
    sfText_setCharacterSize(var->press_txt, 20);
    sfText_setPosition(var->press_txt, (sfVector2f){680, 570});
    var->blacksquare = create_sprite("./res/blacksquare.png",
    (sfVector2f){-100, 350}, (sfVector2f){4, 4});
    sfSprite_setColor(var->blacksquare, (sfColor){255, 255, 255, 250});
    var->back_blacksquare = create_sprite("./res/blacksquare.png",
    (sfVector2f){-100, -100}, (sfVector2f){4, 4});
    sfSprite_setColor(var->back_blacksquare, (sfColor){255, 255, 255, 200});
    var->ennemy1 = create_ennemy("./res/char/down_walk.png"
    , (sfVector2f){find_size(1, 0) * 3, find_size(0, 1) * 5}
    , (sfVector2f){1.75, 1.75});
    create_elem3(var);
}

void create_elems(var_t *var)
{
    create_charact(var);
    create_clock(var);
    create_npcs(var);
    create_buttons_menu(var);
    var->background = create_sprite("./res/bg/game_mountains.jpg"
    , (sfVector2f){0, -210}, (sfVector2f){0.75, 0.75});
    var->logo = create_sprite("./res/bg/logo.png"
    , (sfVector2f){225, 50}, (sfVector2f){0.30, 0.30});
    var->res800_btn = create_btn("./res/btn/800.png"
    , (sfVector2f){150, 200}, (sfVector2f){0.12, 0.15});
    var->res1920_btn = create_btn("./res/btn/1920.png"
    , (sfVector2f){450, 200}, (sfVector2f){0.12, 0.15});
    var->hit_sound = sfMusic_createFromFile("./res/music/hit_sound.wav");
    var->interact_sound =
    sfMusic_createFromFile("./res/music/interact_sound.wav");
    var->status_menu = create_sprite("./res/char/status_menu.png"
    , (sfVector2f){0, 250}, (sfVector2f){0.15, 0.15});
    create_elems2(var);
}
