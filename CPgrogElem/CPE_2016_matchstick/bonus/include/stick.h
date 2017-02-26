/*
** stick.h for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/include/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Feb 23 17:45:49 2017 John Doe
** Last update Fri Feb 24 00:46:20 2017 John Doe
*/

#ifndef STICK_H_
# define STICK_H_

/*
** Core function
** headers file
*/
#include "base.h"
#include "get_next_line.h"
#include "printf.h"
#include "strtowordtab.h"

/*
** Bonus messages and
** headers
*/
#include "graph.h"

#define INTRO						"Welcome to the game"
#define	ENTER						"Please press a key to enter the game\n\n"
/*
** error messages
*/
#define		BADARG				"\nError: invalid input (positive number expected)"
#define		ZERO					"\nError: you have to remove at least one match"
#define		MORESTICK			"\nError: you cannot remove more than"
#define 	OUTOFRANGE 		"\nError: this line is out of range"
#define 	NOSTICK				"\nError: not enough matches on this line"
#define		EMPTYLINE			"\nError: this line is empty"
/*
** ending game
*/
#define		AILOOSE 			"I lost...  snif...  but I'll get you next time!!"
#define		ULOOSE				"You lost, too bad..."

/*
**********************
** 		Functions 		 *
**********************
*/

/*
** Game data
*/
typedef struct s_board {
   int		*stickonline;
   int		width;
   int		pos;
   int		printedchar;
}							t_board;

/*
** get_board.c
*/
int		*get_stick_online( int line);
int		get_width( int line);

/*
** print_stuff.c
*/
int		print_begspaces(int	line, int sticks, int *pos);
int		print_endspaces(int width, int sticks, int *printedchar);
void	topandbottom(int width);
void	print_stick(int sticknbr,  int pos);
void	print_board(int line,  int *sticksnbr);

/*
** check.c
*/
int		checkargs(char *arg_one, char *arg_two);
int		check_line_input(char *user_input, int line, int *sticksnbr);
int		check_stick_input(char *user_input, int maxstick, int sticksnbr);
int		is_stickleft(int *sticksnbr, int line);

/*
** get_args.c
*/
int			getchoosenline(int line, int *sticksnbr);
int			getchoosenstick(int maxstick, int sticknbr);

/*
** ai.c
*/
int			calc_theline(int line, int *sticksnbr);
int			calc_thestick(int maxstick, int sticksnbr);

/*
** game.c
*/
int			player_game(int line, int maxstick, int *sticksnbr);
int			ai_game(int	line, int maxstick, int *sticksnbr);

#endif
