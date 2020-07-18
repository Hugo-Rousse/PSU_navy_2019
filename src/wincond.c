/*
** EPITECH PROJECT, 2020
** navy
** File description:
** wincond
*/

#include "../include/navy.h"

int wincond(char **my_map)
{
    for (int x = 2; x <= 8; x++) {
        for (int y = 2; y <= 16; y += 2) {
            if (is_num(my_map[x][y]))
                return (0);
        }
    }
    return (1);
}
