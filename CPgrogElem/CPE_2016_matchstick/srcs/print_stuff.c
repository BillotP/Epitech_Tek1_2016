/*
** print_stuff.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Feb 22 09:36:20 2017 John Doe
** Last update Sun Feb 26 17:09:36 2017 John Doe
*/

#include "stick.h"

void	topandbottom(int width)
{
  int	j;

  j = 1;
  while (j != width)
    {
      write(1, "*", 1);
      j++;
    }
  write(1, "\n", 1);
}

int		print_begspaces(int line, int *pos)
{
  int i;

  i = 1;
  while (i <= ((line - 1) - *pos))
    {
      write(1, " ", 1);
      i++;
    }
  return (i);
}

void	print_stick(int sticknbr)
{
  int	j;

  j = 0;
  while (j != sticknbr)
    {
      p_printf(1, "|");
      j++;
    }
}

int		print_endspaces(int width, int *printedchar)
{
  int	i;

  i = 1;
  while (i <= (width - 2) - *printedchar)
    {
      write(1, " ", 1);
      i++;
    }
  return (i);
}

void	print_board(int line, int *sticksnbr)
{
  int	i;
  int	width;
  int	pos;
  int	printedchar;

  i = 0;
  pos = 0;
  width = get_width(line);
  topandbottom(width);
  while (i != line)
    {
      write(1, "*", 1);
      printedchar = print_begspaces(line, &pos) + sticksnbr[i];
      print_stick(sticksnbr[i]);
      pos++;
      print_endspaces(width, &printedchar);
      i++;
      write(1, "*\n", 2);
    }
  topandbottom(width);
}
