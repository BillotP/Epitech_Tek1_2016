/*
** flag_match.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/core/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 10 09:20:36 2017 John Doe
** Last update Fri Feb 10 09:20:44 2017 John Doe
*/

#include "printf.h"

#define FLAG  "dcsi"

int				flag_match(const char c)
{
  int			i;
  const 	char	*flag;

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
