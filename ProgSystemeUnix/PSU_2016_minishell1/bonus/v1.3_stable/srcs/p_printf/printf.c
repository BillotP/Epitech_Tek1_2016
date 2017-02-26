/*
** printf.c for p_printf in /home/bender/GrowUp/snippetsandmore/printf_nextry/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 23 07:58:10 2017 John Doe
** Last update Mon Jan 23 13:37:32 2017 John Doe
*/

#include "../include/p_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

int					p_printf(int fd, const char *format, ...)
{
  va_list		list;
  int				(*ptr[4])(va_list list, int fd);
  int				i;
  int				run;

  i = 0;
  run = 0;
  va_start(list, format);
  flag_funct(ptr);
  if (!(format))
    return (-1);
  while ((format[i]))
    {
      if (format[i] == '%' && (flag_match(format[i + 1]) != -1))
	{
	  run = flag_match(ptr[flag_match(format[i + 1])](list, fd));
	  i++;
	}
      else
	write(fd, &format[i], 1);
      i++;
    }
  va_end(list);
  return (run);
}
