/*
** game.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Feb 22 22:52:55 2017 John Doe
** Last update Thu Feb 23 17:39:14 2017 John Doe
*/

#include "stick.h"
#include <stdlib.h>

int			player_game(int line, int maxstick, int *sticksnbr)
{
  int		row;
  int		stick;

  p_printf(1, "\nYour turn:\n");
  while (is_stickleft(sticksnbr, line) != 1)
    {
      if ((row = getchoosenline(line, sticksnbr)) == -1)
	return (0);
      if ((stick = getchoosenstick(maxstick, sticksnbr[row - 1])) == -1)
	return (0);
      sticksnbr[row - 1] -= stick;
      p_printf(1, "Player removed %d match(es) from line %d\n", stick, row);
      print_board(line, sticksnbr);
      return (is_stickleft(sticksnbr, line) == 1) ? (2) : (3);
    }
  return (0);
}

int			ai_game(int line, int maxstick, int *sticksnbr)
{
  int		row;
  int		stick;

  if (is_stickleft(sticksnbr, line) == 1)
    {
      p_printf(1, "%s\n", ULOOSE);
      return (2);
    }
  p_printf(1, "\nAI's turn...\n");
  while (is_stickleft(sticksnbr, line) != 1)
    {
      row = calc_theline(line, sticksnbr);
      stick = calc_thestick(maxstick, sticksnbr[row - 1]);
      sticksnbr[row - 1] -= stick;
      p_printf(1, "AI removed %d match(es) from line %d\n", stick, row);
      print_board(line, sticksnbr);
      if (is_stickleft(sticksnbr, line) == 1)
	{
    p_printf(1, "%s\n", AILOOSE);
	  return (1);
	}
      return (4);
    }
  return (0);
}
