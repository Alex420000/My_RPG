/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-antoine.fillaudeau
** File description:
** file
*/

#include "my_rpg.h"

int read_map(var_t *var)
{
    if (open_file(var) == 84)
        return 84;
    return 0;
}

int open_file(var_t *var)
{
    var->filemap = malloc(sizeof(filemap_t));
    var->filemap->column = 0;
    var->filemap->line = 0;

    var->filemap->fd = open("map.txt", O_RDONLY);
    if (var->filemap->fd == -1) {
        my_putstr("Error to open file\n");
        return 84;
    }
    var->st = malloc(sizeof(struct stat));
    stat("map.txt", var->st);
    var->filemap->buffer = malloc(sizeof(char) * var->st->st_size);
    read(var->filemap->fd, var->filemap->buffer, var->st->st_size);
    for (int i = 0; var->filemap->buffer[i]; i++) {
        if (var->filemap->buffer[i] == '\n')
            var->filemap->line++;
        if (var->filemap->line == 0)
            var->filemap->column++;
    }
    return 0;
}
