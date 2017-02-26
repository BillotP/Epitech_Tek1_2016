##
## Makefile for Minishell1(bonus) in /home/bender/Repo/PSU_2016_minishell1/bonus/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Tue Jan 10 08:08:38 2017 John Doe
## Last update Tue Jan 10 08:08:51 2017 John Doe
##

CC		= clang

RM		= rm -rf

CFLAGS		+= -W -Werror -Wall -Wextra -std=gnu99 -D_POSIX_C_SOURCE=199309L
CFLAGS		+= -I./include/ -lreadline

SRCS		= srcs/base.c					\
		  		srcs/msg.c					\
		  		srcs/shortcuts.c		\
		  		srcs/strtowordtab.c	\
					srcs/built_in.c			\
		  		srcs/pshellv2.c			\
		  		srcs/main.c


OBJS		= $(SRCS:.c=.o)

NAME		= mysh

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

debug:
		$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME)
