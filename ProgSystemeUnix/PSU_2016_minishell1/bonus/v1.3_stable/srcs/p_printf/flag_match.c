/*
** flag_match.c for P_printf in /home/bender/GrowUp/snippetsandmore/printf_nextry/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 23 10:38:40 2017 John Doe
** Last update Mon Jan 23 13:36:49 2017 John Doe
*/

#define FLAG  "dcsi"
#include "../include/p_printf.h"

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
