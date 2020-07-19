/*
** EPITECH PROJECT, 2020
** get_next_line.h
** File description:
** hugo rousse
*/

#ifndef READ_SIZE
#define READ_SIZE 4

char	*get_next_line(const int fd);
char	end_prog(char *ret, int read2, int *taille, int comp);
void	add_charact(char *ret, char *save, int *taille, int *comp);
void	condition_read(int fd, int *read2, int *taille, char *save);

#endif /* !READ_SIZE */
