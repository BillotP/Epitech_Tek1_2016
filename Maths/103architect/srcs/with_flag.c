/*
** multi_main.c for  in /home/CAZAUB_C/projet_de_lanée/103architect/clement2
**
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
**
** Started on  Mon Dec 12 23:03:24 2016 clement cazaubon
** Last update Tue Dec 13 16:21:07 2016 John Doe
*/

#include "../include/my.h"

void					multi_calc(int ac, char **av)
{
  int					i = 1;
  int	bol =0;
  int	*bol2 = NULL;
  t_list			*list = NULL;
  float 			new_coord1;
  float 			new_coord2;

  new_coord1 = 0;
  new_coord2 = 0;
  bol2 = &bol;
  while (i < ac)
    {
      list = set_multy_flags(ac, av, i, bol2, list);
      i++;
    }
  list = fill_list(list);
    new_coord1 = (list->matrix[0][0] * atof(av[1]) + list->matrix[0][1] * \
		  atof(av[2]) +list->matrix[0][2]);
    new_coord2 = (list->matrix[1][0] * atof(av[1]) + list->matrix[1][1] * \
		  atof(av[2]) + list->matrix[1][2]);
  print_list(list, new_coord1, new_coord2, av);
}

void		print_list(t_list *list, float new_coord1, float new_coord2,  char **av)
{
  printf("%.2f\t%.2f\t%.2f\n%.2f\t%.2f\t%.2f\n%.2f\t%.2f\t%.2f\n", \
	 list->matrix[0][0], list->matrix[0][1], list->matrix[0][2], \
	 list->matrix[1][0], list->matrix[1][1], list->matrix[1][2], \
	 list->matrix[2][0], list->matrix[2][1], list->matrix[2][2]);

  printf("(%.0f,%.0f)=>(%.2f,%.2f)\n", atof(av[1]), atof(av[2]), \
	 new_coord1, new_coord2);
}

t_list			*fill_list(t_list *list)
{
  while (list->next != NULL)
    {
      list->next->matrix[0][0] = (list->next->buffer[0][0] * list->matrix[0][0]) + (list->next->buffer[0][1] * list->matrix[1][0]) + (list->next->buffer[0][2] * list->matrix[2][0]);
      list->next->matrix[0][1] = (list->next->buffer[0][0] * list->matrix[0][1]) + (list->next->buffer[0][1] * list->matrix[1][1]) + (list->next->buffer[0][2] * list->matrix[2][1]);
      list->next->matrix[0][2] = (list->next->buffer[0][0] * list->matrix[0][2]) + (list->next->buffer[0][1] * list->matrix[1][2]) + (list->next->buffer[0][2] * list->matrix[2][2]);

      list->next->matrix[1][0] = (list->next->buffer[1][0] * list->matrix[0][0]) + (list->next->buffer[1][1] * list->matrix[1][0]) + (list->next->buffer[1][2] * list->matrix[2][0]);
      list->next->matrix[1][1] = (list->next->buffer[1][0] * list->matrix[0][1]) + (list->next->buffer[1][1] * list->matrix[1][1]) + (list->next->buffer[1][2] * list->matrix[2][1]);
      list->next->matrix[1][2] = (list->next->buffer[1][0] * list->matrix[0][2]) + (list->next->buffer[1][1] * list->matrix[1][2]) + (list->next->buffer[1][2] * list->matrix[2][2]);

      list->next->matrix[2][0] = (list->next->buffer[2][0] * list->matrix[0][0]) + (list->next->buffer[2][1] * list->matrix[1][0]) + (list->next->buffer[2][2] * list->matrix[2][0]);
      list->next->matrix[2][1] = (list->next->buffer[2][0] * list->matrix[0][1]) + (list->next->buffer[2][1] * list->matrix[1][1]) + (list->next->buffer[2][2] * list->matrix[2][1]);
      list->next->matrix[2][2] = (list->next->buffer[2][0] * list->matrix[0][2]) + (list->next->buffer[2][1] * list->matrix[1][2]) + (list->next->buffer[2][2] * list->matrix[2][2]);
      list = list->next;
    }
  return (list);
}
