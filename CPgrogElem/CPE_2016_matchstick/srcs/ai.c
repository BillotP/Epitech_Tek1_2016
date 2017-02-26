/*
** ai.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Feb 23 11:13:02 2017 John Doe
** Last update Sun Feb 26 16:56:40 2017 John Doe
*/

#include "stick.h"

/*
** retrieve the
** first non empty line
*/
int			calc_theline(int line, int *sticksnbr)
{
  int		i;

  i = 0;
  while (i != line)
    {
      if (sticksnbr[i] > 0)
	return (i + 1);
      i++;
    }
  return (0);
}

/*
** pseudo ai
** conditions
*/
int			calc_thestick(int maxstick, int sticksnbr, int islastrow)
{
  if (sticksnbr == 1 || maxstick == 1)
    return (1);
  if (sticksnbr == 2)
    return (1);
  if (islastrow == 1 && sticksnbr == 3)
    return (2);
  else if (sticksnbr > 2 && maxstick > 2)
    return (3);
  return (0);
}
