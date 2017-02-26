/*
** to_chain.c for  in /home/CAZAUB_C/projet_de_lanée/103architect/clement2
**
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
**
** Started on  Tue Dec 13 00:21:39 2016 clement cazaubon
** Last update Tue Dec 13 10:12:39 2016 John Doe
*/

#include "../../include/my.h"

void	feed_matrix(t_list *list, float matrix[3][3])
{
  list->matrix[0][0] = matrix[0][0];
  list->matrix[0][1] = matrix[0][1];
  list->matrix[0][2] = matrix[0][2];

  list->matrix[1][0] = matrix[1][0];
  list->matrix[1][1] = matrix[1][1];
  list->matrix[1][2] = matrix[1][2];

  list->matrix[2][0] = matrix[2][0];
  list->matrix[2][1] = matrix[2][1];
  list->matrix[2][2] = matrix[2][2];

  list->buffer[0][0] = matrix[0][0];
  list->buffer[0][1] = matrix[0][1];
  list->buffer[0][2] = matrix[0][2];

  list->buffer[1][0] = matrix[1][0];
  list->buffer[1][1] = matrix[1][1];
  list->buffer[1][2] = matrix[1][2];

  list->buffer[2][0] = matrix[2][0];
  list->buffer[2][1] = matrix[2][1];
  list->buffer[2][2] = matrix[2][2];
}
