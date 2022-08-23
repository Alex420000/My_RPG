/*
** EPITECH PROJECT, 2021
** int to string
** File description:
** int to char *
*/

#include "my_rpg.h"

char *my_revstr(char *str)
{
    char *u = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;

    for (str += (my_strlen(str) - 1); *str; u[i++] = *str, str--);
    u[i] = '\0';
    return (u);
}

char *submit_string(char *result, int pos)
{
    if (pos == 1) {
        for (int j = my_strlen(result); j > 0; j--)
            result[j] = result[j - 1];
        result[0] = '-';
    }
    return (result);
}

char *int_to_string(int b)
{
    char *r_val = NULL;
    char *str = NULL;
    int len = 0;
    int i = 0;

    for (int tmp = b; tmp > 0; tmp /= 10, len++);
    if (b != 0) {
        str = malloc(sizeof(char) * (len + 1));
        for (; b > 0; b /= 10, i++)
            str[i] = (b % 10) + 48;
        str[i] = '\0';
        r_val = my_revstr(str);
        free(str);
    } else {
        r_val = malloc(2);
        r_val[0] = '0';
        r_val[1] = '\0';
    }
    return (r_val);
}
