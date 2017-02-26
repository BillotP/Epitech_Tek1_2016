/*
** get_args.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Feb 23 02:11:14 2017 John Doe
** Last update Fri Feb 24 01:20:15 2017 John Doe
*/

#include "stick.h"
#include <stdlib.h>
#include <ncurses.h>

int			getchoosenline(int line, int *sticksnbr)
{
  char	user_input[100];
  int		choosenline;

  p_printf(1, "Line: ");
  getstr(user_input);
  while (1)
    {
      if (check_line_input(user_input, line, sticksnbr) == 0)
	{
	  choosenline = my_atoi(user_input);
	  return (choosenline);
	}
      else
	{
	  p_printf("Line: ");
	  getstr(user_input);
	}
    }
  return (-1);
}
int			getchoosenstick(int maxstick, int sticknbr)
{
  char	user_input[100];
  int		stick;

  p_printf("Matches: ");
  getstr(user_input);
  if (check_stick_input(user_input, maxstick, sticknbr) == 0)
    {
      stick = my_atoi(user_input);
      return (stick);
    }
  else
    {
      p_printf("Matches: ");
      getstr(user_input);
    }
  return (-1);
}
