/*
** EPITECH PROJECT, 2020
** get_next_line.h
** File description:
** hugo rousse
*/

#ifndef  READ_SIZE
#define  READ_SIZE (1)
#endif  /* !READ_SIZE  */

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char *alloc(char *src, int position);
int line_position(int x, char *buff, char *file, int y);
char *process_file(char *file, int x);
char *get_next_line(int fd);

#endif /* !GET_NEXT_LINE_H_ */
