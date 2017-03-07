/*
** putnbr.c for CPE_2016_B2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/core/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:56:25 2017 Bender_Rodriguez
** Last update Tue Mar  7 13:07:40 2017 bender
*/

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "base.h"

int		p_putnbr(long nb, int fd)
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
