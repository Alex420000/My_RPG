/*
** EPITECH PROJECT, 2022
** B-PSU-101-LYN-1-1-minishell1-valentin.woehrel
** File description:
** my_strcmp
*/

#include "my_rpg.h"

int my_strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; s1[i]; i++) {
        if (s1[i] != s2[i])
            return -1;
    }
    for (i = 0; s2[i]; i++) {
        if (s1[i] != s2[i])
            return -1;
    }
    return 0;
}
