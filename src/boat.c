/*
** EPITECH PROJECT, 2020
** navy
** File description:
** boat
*/

#include "../include/navy.h"

char **column(char **map, char **position, int i) //On verifie que les bateaux soient à la même place
{
    int distance;

    if (position[i][5] - position[i][2] < 0)
        position[i] = swap(position[i], 5, 2);
    distance = (position[i][5] - position[i][2]);
    for (int y = 2, a = 0; a <= distance; a++, y += 2) {
        if (is_num(map[position[i][3] - '0' + 1][y + (position[i][2] - 'A') * 2]))
            return (NULL);
        map[position[i][3] - '0' + 1][y + (position[i][2] - 'A') * 2] = position[i][0];
    }
    return (map);
}

char **line(char **map, char **position, int i)
{
    int distance;

    if (position[i][6] - position[i][3] < 0)
        position[i] = swap(position[i], 3, 6);
    distance = (position[i][6] - position[i][3]);
    for (int y = 2, a = 0; a <= distance; a++, y++){
        if (is_num(map[y + position[i][3] - '1']\
        [(position[i][2] - 'A' + 1) * 2]))
            return (NULL);
        map[y + position[i][3] - '1'][(position[i][2] - 'A' + 1) * 2] = pos[i][0];
    }
    return (map);
}

int number(char **map)
{
    for (int x = 0; map[x]; x++) {
        for (int y = x + 1; map[y]; y++) {
            if (map[x][0] == map[y][0])
                return (1);
        }
    }
    return (0);
}
