##
## EPITECH PROJECT, 2020
## navy
## File description:
## Makefile
##

SRC =	main.c\
		src/wincond.c\
		src/checkmap.c\
		src/printmap.c\
		src/playerone.c\
		src/playertwo.c\
		src/my_putstr_utils.c\
		src/my_strlen.c\
		src/my_getnbr.c\
		src/my_strcmp.c\
		src/modifmap.c\
		src/connect.c\
		src/my_str_isnum.c\
		src/get_next_line.c\
		src/my_putnbr_base.c\
		src/my_str_to_word_array.c\
		src/boat.c

CC =	gcc

CFLAGS =	-W -Wextra -Wall

OBJ =	$(SRC:.c=.o)

NAME =	navy

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -g3

clean:
	rm -f $(OBJ)
	rm -f src/$(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
