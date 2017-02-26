/*
** flag_match.c for CPE_2016_matchstick in /home/bender/Documents/CPE/CPE_2016_
** matchstick/srcs/core/
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Feb 21 08:50:48 2017 John Doe
** Last update Tue Feb 21 08:55:02 2017 bender
*/

#include "printf.h"

int						flag_match(const char c)
{
  int					i;
  const char	*flag;

  i = 0;
  flag = FLAG;
  while (flag[i])
    {
      if (c == flag[i])
	return (i);
      i++;
    }
  return (-1);
}

void			flag_funct(int (*ptr[4])(va_list list, int fd))
{
  ptr[0] = &flg_d;
  ptr[1] = &flg_c;
  ptr[2] = &flg_s;
  ptr[3] = &flg_i;
}
