/*
** EPITECH PROJECT, 2020
** navy
** File description:
** str_isnum
*/

#include <stdio.h>

int my_str_isnum(char *str)
{
    int i = 0;
    if (str[i] == '-')
            i++;
    while (str[i] != '\0') {
        if (!((str[i] >= '0') && (str[i] <= '9')))
            return (0);
        i++;
    }
    return (1);
}
