/*
** struct_Make.c for  in /home/CAZAUB_C/projet_de_lanée/103architect/clement2
**
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
**
** Started on  Tue Dec 13 00:06:13 2016 clement cazaubon
** Last update Tue Dec 13 13:45:44 2016 clement cazaubon
*/

#include "../../include/my.h"

t_list		*initLC()
{
  t_list	*list;

  list = malloc(sizeof(t_list));
  return (list);
}

t_list		*LCfirst()
{
  t_list	*list;

  list = initLC();
  list->next = NULL;
  return (list);
}

t_list		*LCadd(t_list *liste)
{
  t_list	*list;

  list = initLC();
  list->next = liste;
  return (list);
}

void		LCfree(t_list *list)
{
  t_list	*tmp;

  while (list->next != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
  free(list);
}
