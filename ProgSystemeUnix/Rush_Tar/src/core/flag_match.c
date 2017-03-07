/*
** flag_match.c for Project-Master in /home/bender/Repo/rush/CPE_2016_b2rush1
** 
** Made by bender
** Login   <abel@epitech.eu>
** 
** Started on  Tue Mar  7 13:01:38 2017 bender
** Last update Tue Mar  7 13:02:08 2017 bender
*/

#include "printf.h"

int		flag_match(const char c)
{
  int		i;
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

void		flag_funct(int (*ptr[4])(va_list list, int fd))
{
  ptr[0] = &flg_d;
  ptr[1] = &flg_c;
  ptr[2] = &flg_s;
  ptr[3] = &flg_i;
}
