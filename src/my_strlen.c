/*
** EPITECH PROJECT, 2020
** navy
** File description:
** strlen
*/

#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
