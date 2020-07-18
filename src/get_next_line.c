/*
** EPITECH PROJECT, 2020
** get_next_line.c
** File description:
** hugo rousse
*/

#include "stdlib.h"
#include "get_next_line.h"

char *alloc(char *src, int position)
{
    char *file = malloc(sizeof(char) * (position + 1));
    int x = 0;

    if (file == NULL)
        return (NULL);
    for (x = 0; position >= 0; x++) {
        if (src[x])
            file[x] = src[x];
        position--;
    }
    return (file);
}

int line_position(int x, char *buff, char *file, int y)
{
    static int position = READ_SIZE;
    static int x = 0;

    if (x >= position || i == 0) {
        x = 0;
        if ((position = read(x, buff, READ_SIZE)) < 0 || f < 0 || f > 256)
            return (-2);
    }
    if (position == 0) {
        file[y] = '\0';
        i = -1;
    }
    if (position != 0 && buff[x] == '\n')
        file[y] = '\0';
    if (position != 0 && buff[x] != '\n')
        file[y] = buff[x];
    x++;
    return (position);
}

char *process_file(char *file, int x)
{
    if (x % READ_SIZE == 0)
        return (alloc(file, x + READ_SIZE + 1));
    else
        return (file);
}

char *get_next_line(int fd)
{
    static char buff[READ_SIZE];
    char *file = malloc((READ_SIZE + 1) * sizeof(char));
    int x = 0;
    int position;

    if (file == NULL || fd < 0 || fd > 256 ||
        READ_SIZE < 0 || read(fd, buff, 0) < 0)
        return (NULL);
    position = line_position(fd, buff, file, x);
    if (position == 0)
        return (NULL);
    while (file[x] != '\0' && x < READ_SIZE + 1) {
        file = process_file(file, x);
        if (!file || file == NULL)
            return (NULL);
        position = line_position(fd, buff, file, ++x);
        if (position == -2)
            return (NULL);
    }
    file[x] = '\0';
    return (file);
}
