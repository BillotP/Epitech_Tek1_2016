/*
** p_printf.h for Libfunk in /home/bender/Snippets/libfunk/include/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sun Jan 29 10:13:19 2017 John Doe
** Last update Wed Feb  1 21:00:51 2017 John Doe
*/

#ifndef PRINTF_H_
# define PRINTF_H_

#include <stdarg.h>
#include "base.h"
#include "errors.h"

int				flag_match(const char c);
int				flg_d(va_list list, int fd);
int				flg_i(va_list list, int fd);
int				flg_c(va_list list, int fd);
int				flg_s(va_list list, int fd);

int				p_printf(int fd, const char *format, ...);
int				p_putnbr(long nb, int fd);
void			flag_funct(int (*ptr[4])(va_list list, int fd));

#endif
