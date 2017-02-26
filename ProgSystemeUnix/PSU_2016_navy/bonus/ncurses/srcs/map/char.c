/*
** char.c for  in /home/CAZAUB_C/projet_de_lanée/PSU_2016_navy
**
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
**
** Started on  Mon Jan 30 14:04:38 2017 clement cazaubon
** Last update Sun Feb 19 01:55:00 2017 clement cazaubon
*/

#include "navy.h"

int	is_number(char c)
{
  if (c >= '1' && c <= '8')
    return (0);
  return (-1);
}

int	is_alpha(char c)
{
  if (c >= 'A' && c <= 'H')
    return (0);
  return (-1);
}

int	is_boat(char c)
{
  if (c >= '2' && c <= '5')
    return (0);
  return (-1);
}

void	liner(char str[8][8])
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (i < 8)
    {
      printw("%d|", i + 1);
      while (j < 8)
	{
	  colorfull(str[i][j]);
	  if (j < 7)
	    colorfull(' ');
	  j++;
	}
      printw("\n");
      j = 0;
      i++;
    }
}
