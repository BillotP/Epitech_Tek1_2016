/*
** main.c for CPE_2016_matchstick in /home/bender/Documents/CPE/CPE_2016_matchstick/srcs
**
** Made by John Doe
** Login   <bender@epitech.net>
**
** Started on  Tue Feb 21 09:08:15 2017
** Last update Fri Feb 24 01:18:27 2017 John Doe
*/

#include "stick.h"
#include <stdlib.h>
#include <ncurses.h>

int		game_loop(char **av, int *sticksnbr)
{
  int	rt;

  rt = 3;
  while (rt == 3 || rt == 4)
    {
      // refresh();
      rt = player_game(my_atoi(av[1]), my_atoi(av[2]), sticksnbr);
      if (rt == 0)
  return (rt);
      rt = ai_game(my_atoi(av[1]), my_atoi(av[2]), sticksnbr);
    }
  return (rt);
}
int		main(int ac, char **av)
{
  int	*sticksnbr;
  int check;
  int	rt;

  // init_graph();
  if (ac == 3 && my_stringisnum(av[1]) && my_stringisnum(av[2]))
    {
      check = checkargs(av[1], av[2]);
      if (!check)
	{
	  sticksnbr = get_stick_online(my_atoi(av[1]));
	  print_board(my_atoi(av[1]), sticksnbr);
	  rt = game_loop(av, sticksnbr);
	  if (rt)
	    {
	      free(sticksnbr);
	      // endwin();
	      return (rt);
	    }
	}
    }
  return (84);
}
