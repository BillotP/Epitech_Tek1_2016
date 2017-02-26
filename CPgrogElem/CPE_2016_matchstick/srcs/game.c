/*
** game.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Feb 22 22:52:55 2017 John Doe
** Last update Sun Feb 26 17:18:27 2017 John Doe
*/

#include "stick.h"
#include <stdlib.h>

/*
** Player game :
** retrieve choosen line and stick
** from user , update the board and print it
*/
int			player_game(int line, int maxstick, int *sticksnbr)
{
  int		row;
  int		stick;

  stick = -3;
  p_printf(1, "\nYour turn:\n");
  while (is_stickleft(sticksnbr, line) != 1)
    {
      while (stick < 0)
	{
	  row = getchoosenline(line, sticksnbr);
	  if (row == -1)
	    return (0);
	  stick = getchoosenstick(maxstick, sticksnbr[row - 1]);
	  if (stick == -1)
	    return (0);
	}
      sticksnbr[row - 1] -= stick;
      p_printf(1, "Player removed %d match(es) from line %d\n", stick, row);
      print_board(line, sticksnbr);
      return (is_stickleft(sticksnbr, line) == 1) ? (2) : (3);
    }
  return (0);
}

/*
** Ai game :
** retrieve choosen line and stick
** update the board and print it
*/
int			ai_game(int line, int maxstick, int *sticksnbr)
{
  int		row;
  int		stick;

  if (is_stickleft(sticksnbr, line) == 1)
    return (p_printf(1, "%s\n", ULOOSE), 2);
  p_printf(1, "\nAI's turn...\n");
  while (is_stickleft(sticksnbr, line) != 1)
    {
      row = calc_theline(line, sticksnbr) - 1;
      stick = (row == line) ? (calc_thestick(maxstick, sticksnbr[row], \
				   1)) : (calc_thestick(maxstick, sticksnbr[row], 0));
      sticksnbr[row] -= stick;
      p_printf(1, "AI removed %d match(es) from line %d\n", stick, row + 1);
      print_board(line, sticksnbr);
      if (is_stickleft(sticksnbr, line) == 1)
	return (p_printf(1, "%s\n", AILOOSE), 1);
      return (4);
    }
  return (0);
}
