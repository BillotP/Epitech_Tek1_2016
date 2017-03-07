/*
** flgs.c for CPE_2016_B2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/core/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:55:59 2017 Bender_Rodriguez
** Last update Sun Mar  5 05:56:03 2017 Bender_Rodriguez
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
