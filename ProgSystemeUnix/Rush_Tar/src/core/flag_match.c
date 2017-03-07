/*
** flag_match.c for CPE_2016_B2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/core/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:55:52 2017 Bender_Rodriguez
** Last update Sun Mar  5 05:55:55 2017 Bender_Rodriguez
*/

#include "printf.h"

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
