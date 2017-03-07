/*
** printf.c for CPE_2016_B2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/core/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:56:15 2017 Bender_Rodriguez
** Last update Sun Mar  5 05:56:18 2017 Bender_Rodriguez
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
