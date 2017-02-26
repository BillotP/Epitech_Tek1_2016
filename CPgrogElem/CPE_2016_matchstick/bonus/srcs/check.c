/*
** check.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Feb 22 22:33:02 2017 John Doe
** Last update Fri Feb 24 01:20:01 2017 John Doe
*/

#include "stick.h"
#include <ncurses.h>

int		checkargs(char *arg_one, char *arg_two)
{
  int	line;
  int	stick;

  line = my_atoi(arg_one);
  stick = my_atoi(arg_two);
  if ((line > 0 && line <= 100) && stick > 0)
    return (0);
  return (84);
}

int		check_line_input(char *user_input, int line, int *sticksnbr)
{
  if (!my_stringisnum(user_input))
    {
      p_printf(1, "%s\n", BADARG);
      return (1);
    }
  else if (my_atoi(user_input) > line || my_atoi(user_input) == 0)
    {
      p_printf(1, "%s\n", OUTOFRANGE);
      return (1);
    }
  else if (sticksnbr[my_atoi(user_input) - 1] == 0)
    {
      p_printf(1, "%s\n", EMPTYLINE);
      return (1);
    }
  return (0);
}

int		check_stick_input(char *user_input, int maxstick, int sticknbr)
{
  if (!my_stringisnum(user_input))
    {
      p_printf("%s\n", BADARG);
      return (-1);
    }
  else if (my_atoi(user_input) > maxstick || my_atoi(user_input) < 0)
    {
      p_printf(1, "%s %d matches per turn\n", MORESTICK, maxstick);
      return (-1);
    }
    else if (my_atoi(user_input) == 0)
      {
        p_printf(1, "%s\n", ZERO);
      return (-1);
      }
  else if (my_atoi(user_input) > sticknbr)
    {
      p_printf(1, "%s\n", NOSTICK);
      return (-1);
    }
  return (0);
}

int		is_stickleft(int *sticksnbr, int line)
{
  int	result;
  int	i;

  result = 0;
  i = 0;
  while (i != line)
    {
      if (sticksnbr[i] == 0)
	result++;
      i++;
    }
  return (result == line) ? (1) : (0);
}
