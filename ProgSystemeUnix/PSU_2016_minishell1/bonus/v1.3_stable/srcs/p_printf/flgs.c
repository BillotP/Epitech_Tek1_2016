/*
** flgs.c for P_printf in /home/bender/GrowUp/snippetsandmore/printf_nextry/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 23 10:49:36 2017 John Doe
** Last update Mon Jan 23 17:18:19 2017 John Doe
*/

#include <stdarg.h>
#include "../include/base.h"
#include "../include/p_printf.h"
#include "../include/string.h"

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
