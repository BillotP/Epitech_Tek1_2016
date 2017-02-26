/*
** l_flgs.c for P_printf in /home/bender/GrowUp/snippetsandmore/printf_nextry/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 23 13:41:28 2017 John Doe
** Last update Mon Jan 23 13:44:24 2017 John Doe
*/

#include <stdarg.h>
#include "../include/base.h"
#include "../include/p_printf.h"
#include "../include/string.h"

int					flg_ld(va_list list, int fd)
{
  long int	nb;

  nb = va_arg(list, long int);
  p_putnbr(nb, fd);
  return (0);
}
