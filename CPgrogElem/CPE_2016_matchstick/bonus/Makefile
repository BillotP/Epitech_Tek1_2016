##
## Makefile for CPE_2016_matchstick in /home/bender/Documents/CPE/CPE_2016_matchstick/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Tue Feb 21 09:13:29 2017 John Doe
## Last update Fri Feb 24 00:43:50 2017 John Doe
##

CC			= gcc

RM			= @rm -rf

CFLAGS	= -Wall -Werror
CFLAGS	+= -I./include/
NCURSES	+= -lncurses
##
## debugs flags
##
DFLAGS		= -g2 -Wall -std=gnu99 -Wfatal-errors \
          	-Wformat=2 -Wno-unused-parameter -Wshadow \
          	-Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          	-Wredundant-decls -Wnested-externs \
						-Wmissing-include-dirs
DFLAGS    += -I./include/
##
OBJS		= $(SRCS:.c=.o)

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
					srcs/graph.c							\
					srcs/main.c

all:			$(NAME)

$(NAME):	$(OBJS)
					$(CC) $(CFLAGS) $(NCURSES) $(OBJS) -o $(NAME)

debug:
					$(CC) $(DFLAGS) -g $(SRCS) -o $(NAME)

bonus:
					$(CC) $(CFLAGS) $(NCURSES) $(SRCS) -o $(NAME)

clean:
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
