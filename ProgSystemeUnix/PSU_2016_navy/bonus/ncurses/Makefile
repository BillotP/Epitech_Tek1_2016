##
## Makefile for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Mon Jan 30 14:05:14 2017 John Doe
## Last update Sun Feb 19 01:25:31 2017 clement cazaubon
##

CC				= gcc

CLG				= clang

RM				= @rm -rf

PRINT     = @echo -e "\n\e[1m****\n\t=>Building NAVY suceed\n\t\tEnjoy ;)\n\
						****\n\e[0m"

CFLAGS		= -Wall -Werror -Wpedantic -std=gnu99 -O2
CFLAGS		+= -I./include/
#############################################
## The following compilations flags are based
## on "Cinglis" "c style best practice" guide
##  => https://github.com/mcinglis/c-style <=
#############################################
DFLAGS		= -g2 -Wall -Wpedantic -std=gnu99 \
		-Wformat=2 -Wno-unused-parameter -Wshadow \
		-Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
		-Wredundant-decls -Wnested-externs \
						-Wmissing-include-dirs
DFLAGS    += -I./include/
############################################
OBJS			= $(SRCS:.c=.o)

NAME			= navy

SRCS			= srcs/core/base.c						  \
						srcs/core/base2.c						  \
						srcs/core/error.c						  \
						srcs/core/flag_match.c			  \
						srcs/core/flgs.c						  \
						srcs/core/get_next_line.c		  \
						srcs/core/printf.c					  \
						srcs/core/putnbr.c					  \
						srcs/core/string.c					  \
						srcs/core/strtowordtab.c		  \
						srcs/game/P1game.c					  \
						srcs/game/P2game.c						\
						srcs/game/pingpong.c          \
						srcs/game/M_loop.c						\
						srcs/map/char.c					      \
						srcs/map/check_fight.c	      \
						srcs/map/check_location.c		  \
						srcs/map/check_more.c		      \
						srcs/map/file_check.c		      \
						srcs/map/init.c					      \
						srcs/map/nb_ship.c			      \
						srcs/map/curse.c	\
						srcs/newcom/signauxbitwised.c \
						srcs/newcom/receiver.c				\
						srcs/newcom/sender.c
MAIN			=	srcs/main.c

all:				$(NAME)

$(NAME):		$(OBJS)
						$(CC) $(CFLAGS) $(OBJS) $(MAIN) -o $(NAME) -lncurses

clean:
						$(RM) $(OBJS)

fclean: 		clean
						$(RM) $(NAME)

re: 				fclean all

dbg:
						@echo -e "\n\nD_BUG mode ON (with gcc)\n\n"
						$(CC) $(DFLAGS) $(SRCS) $(MAIN) -o $(NAME)

dbc:
						@echo -e "\n\nD_BUG mode ON (with clang)\n\n"
						$(CLG) $(DFLAGS) $(SRCS) $(MAIN) -o $(NAME)

.PHONY: 		all clean fclean re
