/*
** p_printf.h for P_printf in /home/bender/GrowUp/snippetsandmore/printf_nextry/include/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 23 08:01:46 2017 John Doe
** Last update Mon Jan 23 17:53:06 2017 John Doe
*/

#ifndef P_PRINTF_H_
# define P_PRINTF_H_

#include <stdarg.h>
#include "base.h"

int		p_printf(int fd, const char *format, ...);

int		flg_d(va_list list, int fd);
int		flg_i(va_list list, int fd);
int		flg_s(va_list list, int fd);
int		flg_c(va_list list, int fd);

int		flag_match(const char c);
int		p_putnbr(long nb, int fd);
void	flag_funct(int (*ptr[4])(va_list list, int fd));

#endif
