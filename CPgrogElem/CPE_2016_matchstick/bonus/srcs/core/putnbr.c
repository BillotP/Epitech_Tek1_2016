/*
** putnbr.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/core/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Feb 23 16:50:44 2017 John Doe
** Last update Thu Feb 23 16:51:02 2017 John Doe
*/

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "base.h"

int				p_putnbr(long nb, int fd)
{
  if (nb >= LONG_MAX || nb <= LONG_MIN)
    return (84);
  if (nb < 0)
    {
      pprint("-", fd);
      p_putnbr(nb * - 1, fd);
    }
  if (nb >= 0 && nb <= 9)
    {
      nb = nb + '0';
      pprint((const char*)&nb, fd);
    }
  else if (nb > 9)
    {
      p_putnbr(nb / 10, fd);
      nb = (nb % 10) + '0';
      pprint((const char*)&nb, fd);
    }
  return (0);
}
