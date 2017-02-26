/*
** putnbr.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/core/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 10 09:22:01 2017 John Doe
** Last update Fri Feb 10 09:22:07 2017 John Doe
*/

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "errors.h"
#include "base.h"

int				p_putnbr(long nb, int fd)
{
  if (nb >= LONG_MAX || nb <= LONG_MIN)
    errors("putnbr: illegal value\n", 84);
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
