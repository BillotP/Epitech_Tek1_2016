/*
** get_board.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Feb 22 08:21:17 2017 John Doe
** Last update Thu Feb 23 01:59:23 2017 John Doe
*/

#include "stick.h"
#include <stdlib.h>

int		get_width(int line)
{
  int	width;

  width = (line * 2) + 2;
  return (width);
}

int			*get_stick_online(int line)
{
  int		i;
  int		j;
  int		*stickonline;

  i = 0;
  j = 1;
  if ((stickonline = malloc(sizeof(*stickonline) * line)) == NULL)
    return (NULL);
  while (i != line)
    {
      stickonline[i++] = j;
      j = j + 2;
    }
  return (stickonline);
}
