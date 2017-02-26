/*
** check_location.c for  in /home/CAZAUB_C/projet_de_lanée/PSU_2016_navy
**
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
**
** Started on  Wed Feb  1 14:40:12 2017 clement cazaubon
** Last update Wed Feb 15 10:12:24 2017 John Doe
*/

#include "map.h"

int	size_boat(char *str)
{
  if (str[0] - '0' < 2 || str[0] - 48 > 5)
    return (-1);
  return (0);
}

int	f_location(char *str)
{
  if (is_alpha(str[2]) == -1 || is_number(str[3]) == -1)
    return (-1);
  return (0);
}

int	l_location(char *str)
{
  if (is_alpha(str[5]) == -1 || is_number(str[6]) == -1)
    return (-1);
  return (0);
}

int	check_both(char *str)
{
  int	taille;
  int	val_total;
  int	val_total2;

  taille = str[0] - '0';
  val_total = (str[2] - 'A') - (str[5] - 'A');
  val_total2 = (str[3] - '0') - (str[6] - '0');
  if (val_total < 0)
    val_total = (val_total - 1) * -1;
  else if (val_total != 0)
    val_total = val_total + 1;
  if (val_total2 < 0)
    val_total2 = (val_total2 - 1) * -1;
  else if (val_total2 != 0)
    val_total2 = val_total2 + 1;
  if ((val_total == taille && val_total2 == 0) || (val_total2 == taille && \
       val_total == 0))
    return (0);
  else
    return (-1);
}
