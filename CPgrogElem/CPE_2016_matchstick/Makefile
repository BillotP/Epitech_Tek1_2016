##
## Makefile for CPE_2016_matchstick in /home/bender/Documents/CPE/CPE_2016_matchstick/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Tue Feb 21 09:13:29 2017 John Doe
## Last update Sun Feb 26 17:23:39 2017 John Doe
##

CC			= gcc

RM			= @rm -rf

CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -pedantic -ansi
CFLAGS	+= -I./include/

NAME		= matchstick

SRCS		= srcs/core/base.c					\
					srcs/core/base2.c					\
					srcs/core/flag_match.c		\
					srcs/core/flgs.c					\
					srcs/core/get_next_line.c	\
					srcs/core/printf.c				\
					srcs/core/putnbr.c				\
					srcs/core/string.c				\
					srcs/core/strtowordtab.c	\
					srcs/get_board.c					\
					srcs/print_stuff.c				\
					srcs/check.c							\
					srcs/get_args.c						\
					srcs/game.c								\
					srcs/ai.c									\
					srcs/main.c

OBJS		= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):	$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

dbg:
					$(CC) $(CFLAGS) -g2 $(SRCS) -o $(NAME)

clean:
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
