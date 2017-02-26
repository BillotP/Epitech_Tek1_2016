/*
** printf.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/core/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Feb 23 16:50:26 2017 John Doe
** Last update Thu Feb 23 16:50:37 2017 John Doe
*/

#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

#include "printf.h"

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
