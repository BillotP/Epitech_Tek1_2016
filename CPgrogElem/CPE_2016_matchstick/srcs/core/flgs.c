/*
** flgs.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/core/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Feb 23 16:48:52 2017 John Doe
** Last update Thu Feb 23 16:49:05 2017 John Doe
*/

#include <stdarg.h>

#include "base.h"
#include "printf.h"

int			flg_d(va_list list, int fd)
{
  int		nb;

  nb = va_arg(list, int);
  p_putnbr(nb, fd);
  return (nb);
}

int			flg_i(va_list list, int fd)
{
  int		nb;

  nb = va_arg(list, int);
  p_putnbr(nb, fd);
  return (0);
}
int			flg_c(va_list list, int fd)
{
  int		a;

  a = va_arg(list, int);
  write(fd, &a, 1);
  return (0);
}

int					 flg_s(va_list list, int fd)
{
  const	char *s;

  s = va_arg(list, char *);
  if (s == NULL)
    pprint("(null)", fd);
  pprint(s, fd);
  return (0);
}
