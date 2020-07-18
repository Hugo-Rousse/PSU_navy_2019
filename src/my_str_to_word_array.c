/*
** EPITECH PROJECT, 2020
** navy
** File description:
** strwa
*/

#include "../include/navy.h"

int nb(char *str, char sep)
{
    int spaces = 1;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == sep)
            spaces++;
    }
    return (spaces);
}

int actual(char *str, char sep)
{
    int i = 1;

    for (; str[i] != sep && str[i] != 0; i++);
    return (i);
}

char **last_verif(char **tab, char sep, int nb_el)
{
    if (tab[nb_el - 1][0] == sep || tab[nb_el - 1][0] == 0)
        tab[nb_el - 1] = NULL;
    return (tab);
}

char **my_str_to_tab(char *str, char sep)
{
    char **tab = malloc(sizeof(char *) * (nb(str, sep) + nb(str, '\t')));
    int j = 0;

    for (int i = 0; i < my_strlen(str) + 1; i++, j++) {
        for (; str[i] == sep || str[i] == '\t'; i++);
        tab[j] = malloc(sizeof(char) * (actual(&str[i], sep) + 2));
        tab[j][0] = 0;
        for (int e = 0; str[i] != sep && str[i] != '\0'
        && str[i] != '\t'; i++, e++) {
            tab[j][e] = str[i];
            if (str[i + 1] == sep || str[i] == '\t' || str[i + 1] == 0)
                tab[j][e + 1] = 0;
        }
        if (str[i] != 0)
            for (; str[i + 1] == sep || str[i + 1] == '\t'; i++);
    }
    tab = last_verif(tab, sep, j);
    tab[j] = NULL;
    return (tab);
}
