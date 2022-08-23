/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** create_thing3
*/

#include "my_rpg.h"

void create_inventory_two(var_t *var, inventory_t *inv)
{
    inv->bg_sprite = sfSprite_create();
    inv->sword_sprite = sfSprite_create();
    inv->text = sfText_create();
    inv->bg_texture =\
    sfTexture_createFromFile("./res/inventory/INVENTORY.png", NULL);
    inv->sword_texture =\
    sfTexture_createFromFile("./res/inventory/diamond_sword.png", NULL);
    sfSprite_setTexture(inv->bg_sprite, inv->bg_texture, sfTrue);
    sfSprite_setTexture(inv->sword_sprite, inv->sword_texture, sfTrue);
    sfSprite_setScale(inv->sword_sprite, (sfVector2f){0.25, 0.25});
    sfSprite_setPosition(inv->bg_sprite, (sfVector2f){240, 75});
    sfSprite_setPosition(inv->sword_sprite, (sfVector2f){250, 459});
    sfText_setFont(inv->text, var->font);
    sfText_setString(inv->text, "Press [I]");
    sfText_setCharacterSize(inv->text, 20);
    sfText_setPosition(inv->text, (sfVector2f){680, 570});
}

inventory_t *create_inventory(var_t *var)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    inv->c = 0;
    inv->item_sword = 0;
    create_inventory_two(var, inv);
    return (inv);
}

menu_t *create_menu(var_t *var)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->pause = 0;
    menu->pause_sprite = sfSprite_create();
    menu->pause_texture =\
    sfTexture_createFromFile("./res/btn/btn_paused.png", NULL);
    menu->text = sfText_create();
    sfSprite_setTexture(menu->pause_sprite, menu->pause_texture, sfTrue);
    sfSprite_setScale(menu->pause_sprite, (sfVector2f){0.2, 0.2});
    sfSprite_setPosition(menu->pause_sprite, (sfVector2f){250, 100});
    sfText_setFont(menu->text, var->font);
    sfText_setString(menu->text, "Press [M]");
    sfText_setCharacterSize(menu->text, 20);
    sfText_setPosition(menu->text, (sfVector2f){680, 570});
    return (menu);
}

speeches_t *create_speeches(var_t *var)
{
    speeches_t *speeches = malloc(sizeof(speeches_t));

    speeches->edward_speech_first = sfText_create();
    speeches->edward_speech_second = sfText_create();
    sfText_setFont(speeches->edward_speech_first, var->font);
    sfText_setFont(speeches->edward_speech_second, var->font);
    sfText_setString(speeches->edward_speech_first
    , "[Edward] It's dangerous to go alone! Take this.");
    sfText_setString(speeches->edward_speech_second
    , "[Edward] Go and save the world !");
    sfText_setCharacterSize(speeches->edward_speech_first, 20);
    sfText_setCharacterSize(speeches->edward_speech_second, 20);
    sfText_setPosition(speeches->edward_speech_first, (sfVector2f){5, 415});
    sfText_setPosition(speeches->edward_speech_second, (sfVector2f){5, 415});
    return (speeches);
}

intro_t *create_intro(var_t *var)
{
    intro_t *intro = malloc(sizeof(intro_t));

    intro->clock = sfClock_create();
    intro->sprite = sfSprite_create();
    intro->texture = sfTexture_createFromFile("./res/btn/logo_rpg.png", NULL);
    return (intro);
}
