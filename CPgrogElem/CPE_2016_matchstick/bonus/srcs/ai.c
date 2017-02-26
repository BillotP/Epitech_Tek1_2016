/*
** ai.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Feb 23 11:13:02 2017 John Doe
** Last update Thu Feb 23 15:57:54 2017 John Doe
*/

#include "stick.h"

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

int			calc_thestick(int maxstick, int sticksnbr)
{
  if (sticksnbr == 1 || maxstick == 1)
    return (1);
  else if (sticksnbr > 1 && maxstick >= 2)
    return (2);
  return (0);
}
