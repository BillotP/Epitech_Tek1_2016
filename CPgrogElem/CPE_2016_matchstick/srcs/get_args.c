/*
** get_args.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Feb 23 02:11:14 2017 John Doe
** Last update Sun Feb 26 17:00:40 2017 John Doe
*/

#include "stick.h"
#include <stdlib.h>

/*
** The two following functions
** used get next line to retrieve
** user input and check this value
*/
int			getchoosenline(int line, int *sticksnbr)
{
  char	*user_input;
  int		choosenline;

  p_printf(1, "Line: ");
  while ((user_input = get_next_line(0)))
{
      if (check_line_input(user_input, line, sticksnbr) == 0)
	{
	  choosenline = my_atoi(user_input);
	  free(user_input);
	  return (choosenline);
	}
      p_printf(1, "Line: ");
      free(user_input);
    }
  return (-1);
}
int			getchoosenstick(int maxstick, int sticknbr)
{
  char	*user_input;
  int		stick;

  p_printf(1, "Matches: ");
  while ((user_input = get_next_line(0)))
{
      if (check_stick_input(user_input, maxstick, sticknbr) == 0)
	{
    stick = my_atoi(user_input);
    free(user_input);
	  return (stick);
	}
      free(user_input);
      return (-2);
    }
  return (-1);
}
