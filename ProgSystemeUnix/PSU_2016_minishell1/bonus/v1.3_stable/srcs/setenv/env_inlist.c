/*
** add_link.c for Minishell1 in /home/bender/Repo/PSU_2016_minishell1/v1.2/srcs/test/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Jan 18 13:59:57 2017 John Doe
** Last update	Sun Jan 22 09:54:53 2017 Full Name
*/

#include "setenv.h"
#include "strtowordtab.h"
#include "base.h"
#include <stdio.h>

t_env *first = NULL;
t_env *curr = NULL;

t_env		*add_toenv(const char *newdata, int pos)
{
  t_env *ptr;

  if (first == NULL)
    return (env_inlist((char **)&newdata));
  ptr = malloc(sizeof(*ptr));
  if (ptr == NULL)
    errors(strerror(errno), 84);
  ptr->data = (char *)newdata;
  ptr->next = NULL;
  if (pos == (char)'e')
    {
      curr->next = ptr;
      curr = ptr;
    }
  else
    {
      ptr->next = first;
      first = ptr;
    }
  return (ptr);
}
t_env		*env_inlist(char **environ)
{
  int			i;
  t_env	*list;
  t_env	*tmp;

  i = 0;
  list = NULL;
  while (environ[i] != NULL)
    {
      if ((tmp = malloc(sizeof(*tmp))) == NULL)
	return (NULL);
      tmp->pos = tmp->pos + 1;
      tmp->data = environ[i];
      tmp->next = list;
      list = tmp;
      i++;
    }
  first = list;
  curr = list;
  return (list);
}

void		free_list(t_env *list)
{
  t_env *next;

  next = first;
  while (list != NULL)
    {
      next = list->next;
	  free(list);
      list = next;
    }
}
int 		list_size(t_env *list)
{
  int		i;
  t_env *next;

  i = 0;
  next = curr;
  while (list != NULL)
    {
      next = list->next;
      i++;
      list = next;
    }
  return (i);
}
void		pprintenv(void)
{
  t_env *ptr;

  ptr = curr;
  while (ptr != NULL)
    {
      pprint(ptr->data, 1);
      pprint("\n", 1);
      ptr = ptr->next;
    }
  return ;
}
