/*
** printf.h for CPE_2016_B2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/include/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:58:23 2017 Bender_Rodriguez
** Last update Sun Mar  5 22:14:58 2017 Bender_Rodriguez
*/

#ifndef PRINTF_H_
# define PRINTF_H_

#include <stdarg.h>
#include "base.h"

#ifndef FLAG
#define FLAG  "dcsi"
#endif

/*
** flag_match.c
*/
int				flag_match(const char c);
void			flag_funct(int (*ptr[4])(va_list list, int fd));

/*
** flgs.c
*/
int				flg_d(va_list list, int fd);
int				flg_i(va_list list, int fd);
int				flg_c(va_list list, int fd);
int				flg_s(va_list list, int fd);

/*
** printf.c
*/
int				p_printf(int fd, const char *format, ...);

/*
** putnbr.c
*/
int				p_putnbr(long nb, int fd);

#endif
