/*
** base.c for Minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 22:10:35 2017 John Doe
** Last update	Sat Jan 21 10:45:48 2017 Full Name
*/

#include "base.h"
#include "string.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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
