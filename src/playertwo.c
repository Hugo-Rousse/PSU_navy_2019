/*
** EPITECH PROJECT, 2020
** navy
** File description:
** playertwo
*/

#include "../include/navy.h"

void takingsignals(void) // On met en place les signaux sigusr1 et sigusr2
{
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (!global.exit_cond);
    while (global.exit_cond != 2);
    my_putstr("\n");
    my_putnbr_base(global.sign1, "AABCDEFGH");
    my_putnbr_base(global.sign2, "012345678");
    my_putstr(":  ");
}

int playertwo(char **my_map, char **enemy_map, int pid2)
{
    my_putstr("waiting for enemy's attack...");
    global = reset_gbl(global);
    takingsignals();
    modify_mymap(my_map);
    if (wincond(my_map)) {
        my_putstr("Enemy won\n");
        for (int i = 0; i < 100; i++)
            kill(pid2, SIGUSR2);
        return (1);
    }
    return (playerone(my_map, enemy_map, pid2));
}
