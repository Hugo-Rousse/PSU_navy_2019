/*
** EPITECH PROJECT, 2019
** playerone.c
** File description:
** P1 navy
*/

#include "../include/navy.h"

void handler(int i)
{
    if (i == 12)
        global.exit_cond++;
    if (i == 10 && global.exit_cond == 0)
        global.signal1++;
    if (i == 10 && global.exit_cond != 0)
        global.signal2++;
    if (i == 12 && global.exit_cond >= 3)
        global.win = 1;
}

void receivingsignal(void)
{
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    usleep(5000);
    if (global.exit_cond)
        global.hit = my_putstr("hit\n");
    else
        my_putstr("missed\n");
}

void sendsignal(char *entry, int pid2)
{
    global.signal1 = entry[0] - 64;
    global.signal2 = entry[1] - '0';
    global.exit_cond = 0;
    usleep(5000);
    for (int a = 0; a < global.signal1; a++) {
        usleep(1000);
        kill(pid2, SIGUSR1);
        usleep(1000);
    }
    kill(pid2, SIGUSR2);
    usleep(1000);
    for (int a = 0; a < global.signal2; a++) {
        kill(pid2, SIGUSR1);
        usleep(1000);
    }
    kill(pid2, SIGUSR2);
    usleep(100);
    my_putstr(entry);
    my_putstr(":  ");
    receivingsignal();
}

char *checkentry(void)
{
    char *entry = get_next_line(0);

    if ((entry[0] < 'A' || entry[0] > 'H') \
    || (entry[1] < '1' || entry[1] > '8') || entry[2] != '\0') {
        my_putstr("wrong position\nattack:  ");
        return (checkentry());
    }
    return (entry);
}

int playerone(char **my_map, char **enemy_map, int pid2)
{
    char *entry;

    my_putstr("my positions :\n");
    disp_map(my_map);
    my_putstr("\nenemy's position:\n");
    disp_map(enemy_map);
    my_putstr("attack:  ");
    entry = checkentry();
    sendsignal(entry, pid2);
    modify_enemymap(enemy_map);
    my_putchar('\n');
    usleep(100);
    if (global.win) {
        my_putstr("I won\n");
        return (0);
    }
    global = reset_gbl(global);
    return (playertwo(my_map, enemy_map, pid2));
}
