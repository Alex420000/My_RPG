/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <time.h>
    #include <math.h>
    #include <sys/stat.h>
    #include "my_split.h"

    typedef struct {
        sfSprite **tree_sprite;
        int *skill;
        sfSprite **tree;
        int print;
    } tree_t;

    typedef struct {
        sfMusic *music;
        int vol;
    } music_t;

    typedef struct {
        sfVector2f pos;
        int mouse_x;
        int mouse_y;
        sfSprite *sprite;
        sfTexture *texture;
    } mouse_t;

    typedef struct {
        sfSprite *sprite;
        sfVector2f position;
        sfVector2f scale;
        sfColor color;
    } btn_t;

    typedef struct {
        int fd;
        char *buffer;
        int column;
        int line;
    } filemap_t;

    typedef struct {
        sfSprite *sprite;
        sfVector2f pos;
        int block;
        void *next;
    } linked_map_t;

    typedef struct {
        sfSprite *life_s;
        sfSprite *life_back_s;
    } lifebar_t;

    typedef struct {
        sfSprite *side_walk;
        sfSprite *down_walk;
        sfSprite *up_walk;
        sfSprite *down_idle;
        sfSprite *up_idle;
        sfSprite *side_idle;
        sfSprite *down_atk;
        sfSprite *up_atk;
        sfSprite *side_atk;
        sfVector2f pos;
        sfIntRect rect_walk;
        sfIntRect rect_atk_down;
        sfIntRect rect_atk_up;
        sfIntRect rect_atk_side;
        int which;
        int life;
        lifebar_t *lifebar;
        int interact;
        int color;
        int damages;
        int defense;
    } charact_t;

    typedef struct {
        sfSprite *sprite;
        sfVector2f pos;
        lifebar_t *lifebar;
        int life;
        int dead;
    } ennemy_t;

    typedef struct {
        sfClock *clock;
        sfTime time;
        float seconds;
    } myclock_t;

    typedef struct {
        sfSprite *sprite;
        sfVector2f pos;
        int interact;
        int state;
    } npc_t;

    typedef struct {
        sfSprite *bg_sprite;
        sfSprite *sword_sprite;
        sfTexture *bg_texture;
        sfTexture *sword_texture;
        sfText *text;
        int item_sword;
        int c;
    } inventory_t;

    typedef struct {
        sfSprite *pause_sprite;
        sfTexture *pause_texture;
        sfText *text;
        int pause;
    } menu_t;

    typedef struct {
        sfText *edward_speech_first;
        sfText *edward_speech_second;
    } speeches_t;

    typedef struct intro_s {
        sfRenderWindow *window;
        sfEvent event;
        sfSprite *sprite;
        sfTexture *texture;
        sfClock *clock;
        int time;
    } intro_t;

    typedef struct {
        struct stat *st;
        int screen;
        sfRenderWindow *window;
        sfVector2u win_size;
        sfEvent event;
        filemap_t *filemap;
        linked_map_t *map;
        charact_t *charact;
        myclock_t *clock_anim_player;
        myclock_t *clock_mov_player;
        btn_t *play_btn;
        btn_t *options_btn;
        btn_t *quit_btn;
        btn_t *htp_btn;
        btn_t *res800_btn;
        btn_t *res1920_btn;
        tree_t *skill_tree;
        sfSprite *background;
        sfSprite *logo;
        sfView *view;
        npc_t *edward;
        npc_t *test;
        sfFont *font;
        sfText *interact_txt;
        sfText *press_txt;
        sfText *vol_txt;
        sfSprite *blacksquare;
        sfSprite *back_blacksquare;
        ennemy_t *ennemy1;
        sfFloatRect char_box;
        sfFloatRect enmy_box;
        sfSprite *screen_size;
        sfSprite *sounds;
        btn_t *cursor_more;
        btn_t *cursor_less;
        mouse_t *mouse;
        myclock_t *clock_ennemy;
        myclock_t *clock_enmy_atck;
        inventory_t *inventory;
        sfSprite *explain;
        sfSprite *htp_logo;
        music_t *main_music;
        menu_t *menu;
        speeches_t *speeches;
        btn_t *next_btn;
        btn_t *one_btn;
        btn_t *two_btn;
        btn_t *three_btn;
        btn_t *four_btn;
        btn_t *edit_btn;
        int *coos_testa;
        sfMusic *hit_sound;
        sfMusic *interact_sound;
        sfSprite *status_menu;
        sfText *damages_txt;
        sfText *defense_txt;
        sfText *life_txt;
        btn_t *menu_btn;
        btn_t *ground1_btn;
        btn_t *ground2_btn;
        int editor;
        btn_t *skip_btn;
        btn_t *save_btn;
        sfSprite *save_logo;
        intro_t *intro;
    } var_t;

    // lib
    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_strcmp(char *s1, char *s2);
    int my_getnbr(char const *str);
    char *int_to_string(int nb);
    int my_strlen(char *str);
    char **my_str_to_word_array(char *src, int occ);
    my_split_t *my_split(char *str, char d);
    void my_str_to_word_array_free(char **str);
    void my_split_free(my_split_t *s);
    char *my_strcpy(char *str);
    int my_bi_strlen(char **str);
    int my_strlen(char *str);

    // main.c
    int main(int ac, char **av);
    void infinite_loop(void);
    void handle_event(var_t *var);
    void auto_resize(var_t *var);

    // create_things.c
    sfSprite *create_sprite(char *what, sfVector2f position, sfVector2f scale);
    btn_t *create_btn(char *what, sfVector2f position, sfVector2f scale);
    void create_window(var_t *var, int x, int y);
    int find_size (int x, int y);
    lifebar_t *create_lifebar(sfVector2f position, sfVector2f scale);

    // create_things2.c
    npc_t *create_npc(char *what, sfVector2f position, sfVector2f scale
    , sfColor color);
    ennemy_t *create_ennemy(char *what, sfVector2f position, sfVector2f scale);
    mouse_t *create_mouse(var_t *var);
    music_t *create_music(char *what, int vol);

    // create_things3.c
    inventory_t *create_inventory(var_t *var);
    menu_t *create_menu(var_t *var);
    speeches_t *create_speeches(var_t *var);
    intro_t *create_intro(var_t *var);

    //skill_tree.c
    void skill_tree_handle(var_t *var);
    void check_click_tree(var_t *var);

    // create.c
    void create_start(var_t *var);
    void create_all(var_t *var);
    void create_clock(var_t *var);
    void create_npcs(var_t *var);

    // create_charact.c
    void create_charact(var_t *var);

    // create_elems.c
    void create_elems(var_t *var);

    // create_elems2.c
    void create_buttons_menu(var_t *var);
    void create_status_menu(var_t *var);

    // display.c
    void display_all(var_t *var);
    void display_menu(var_t *var);
    void display_ennemy(var_t *var, ennemy_t *ennemy);
    void display_ennemies(var_t *var);
    void display_options(var_t *var);

    // display2.c
    void display_creator(var_t *var);
    void display_htp(var_t *var);
    void display_all_bis(var_t *var);
    void handle_save(var_t *var);

    // display_game.c
    void display_game(var_t *var);

    // display_game2.c
    void handle_menu(var_t *var);

    // switch_display_game.c
    void switch_display_game(var_t *var);

    // file.c
    int read_map(var_t *var);
    int open_file(var_t *var);

    // free.c
    void free_all(var_t *var);

    // map_linked_list.c
    void declare_linked_map(var_t *var);
    void new_node_map(var_t *var, char *what, sfVector2f pos, int block);
    void display_map(var_t *var);

    // move_map.c
    void move_map_right(var_t *var);
    void move_map_left(var_t *var);
    void move_map_up(var_t *var);
    void move_map_down(var_t *var);

    // event.c
    void event_keypressed(var_t *var);

    // event2.c
    void handle_event(var_t *var);

    // move_charact.c
    void move_charact(var_t *var);
    void skill_tree_handling(var_t *var);

    // move_charact_branch.c
    void move_chara_set_pos(var_t *var);
    void move_charact1_branch(var_t *var, linked_map_t *cursor);
    void move_charact2_branch(var_t *var, linked_map_t *cursor2);
    void move_charact3_branch(var_t *var, linked_map_t *cursor2);
    void move_charact4_branch(var_t *var, linked_map_t *cursor);

    // character_animation.c
    void anim_walk(var_t *var);
    void anim_atk_down(var_t *var);
    void anim_atk_up(var_t *var);
    void anim_atk_side(var_t *var);

    // character_animation_2.c
    void anim_atk_down_branch(var_t *var);
    void anim_atk_up_branch(var_t *var);
    void anim_atk_side_branch(var_t *var);
    void set_rect_all(var_t *var);
    void set_pos_all(var_t *var);

    // clock.c
    void loop_all_clock(var_t *var);
    void loop_clock_anim_player(var_t *var);
    void loop_clock_mov_player (var_t *var);

    // clock_2.c
    void loop_clock_ennemy(var_t *var);
    void loop_clock_anim_player_next(var_t *var);
    void which_baction_next(var_t *var);

    // buttons.c
    void baction(var_t *var, btn_t *button, int screen, char *what);

    // buttons2.c
    void else_baction_branch_creator2(var_t *var, int screen);

    // collision.c
    void collision(var_t *var);

    // cursor.c
    void set_cursor(var_t *var);

    // ennemy.c
    void ennemy_mov(var_t *var);
    void ennemy_atck(var_t *var, ennemy_t *enmy);
    void ennemy_mov_branch(var_t *var, sfVector2f pos, int i
    , ennemy_t *list[i]);
    void ennemy_mov_if(var_t *var, sfVector2f pos, int i
    , ennemy_t *list[]);
    void ennemy_follow(var_t *var, sfVector2f pos, int i
    , ennemy_t *list[]);

    // ennemy_2.c
    sfVector2f ennemy_mov_cond1(var_t *var, sfVector2f pos, int i
    , ennemy_t *list[]);
    sfVector2f ennemy_mov_cond2(var_t *var, sfVector2f pos, int i
    , ennemy_t *list[]);

    // music.c
    void refresh_vol_music(var_t *var);

    // charact_creator.c
    void creator_color(var_t *var, sfColor color);

    // status_menu.c
    char *convert_int_text(int value);

    // save.c
    int save_game(var_t *var);
    int load_game(var_t *var);

#endif
