##
## Makefile for CPE_2016_matchstick in /home/bender/Documents/CPE/CPE_2016_matchstick/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Tue Feb 21 09:13:29 2017 John Doe
##
##

CC		= gcc

RM		= @rm -rf

CFLAGS		+= -Wall -Wextra -Werror -pedantic
CFLAGS		+= -I./include/

OBJ1		= $(SRC1:.c=.o)
OBJ2		= $(SRC2:.c=.o)

NAME1		= my_archive
NAME2		= my_unarchive

SRCS		= src/utils.c 			\
		src/core/base.c 		\
		src/core/base2.c 		\
		src/core/flag_match.c 		\
		src/core/flgs.c 		\
		src/core/get_next_line.c 	\
		src/core/printf.c 		\
		src/core/putnbr.c 		\
		src/core/string.c 		\
		src/core/strtowordtab.c 	\
		src/get_header.c		\
		src/get_headerbis.c		\
		src/get_pax.c			\
		src/get_paxbis.c		\
		src/pax_hdr.c			\
		src/posix_hdr.c

SRC1		= $(SRCS) 		\
		src/my_archive.c	\
		src/main1.c

SRC2		= $(SRCS) 		\
		src/my_archive.c	\
		src/main1.c

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
		$(CC) $(OBJ1) -o $(NAME1)

$(NAME2):	$(OBJ2)
		$(CC) $(OBJ2) -o $(NAME2)

dbg:
		$(CC) $(CFLAGS)-g2 $(SRC1) -o dbug

one:		$(NAME1)

clean:
		$(RM) $(OBJ1) $(OBJ2)

fclean:		clean
		$(RM) $(NAME1)
		$(RM) $(NAME2)

re:		fclean all

.PHONY:	all clean fclean re
