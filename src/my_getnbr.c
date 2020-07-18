/*
** EPITECH PROJECT, 2020
** navy
** File description:
** getnbr
*/

#include <stdio.h>
#include <stdlib.h>

int my_getnbr(char const *str)
{
    int i;
    int	solution;
    int	nbr;
    
    solution = 1;
    i = 0;
    nbr = 0;
    while (str[i] && (str[i] == '+' || str[i] == '-'))
        if (str[i++] == '-')
            solution *= -1;
    while (str[i] >= '0' && str[i] <= '9')
        nbr = nbr * 10 + (str[i++] - '0');
    return (nbr * solution);
}
