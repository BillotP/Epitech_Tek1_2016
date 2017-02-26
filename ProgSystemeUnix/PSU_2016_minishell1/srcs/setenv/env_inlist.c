/*
** add_link.c for Minishell1 in /home/bender/Repo/PSU_2016_minishell1/v1.2/srcs/test/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Jan 18 13:59:57 2017 John Doe
** Last update Thu Jan 19 13:23:45 2017 John Doe
*/

#include "../../include/setenv.h"
#include "../../include/base.h"

t_environ		*env_inalist(char **environ)
{
  int			i;
  t_environ	*list;
  t_environ	*tmp;

  i = 0;
  list = NULL;
  while (environ[i] != NULL)
    {
      tmp = malloc(sizeof(*tmp));
      tmp->data = environ[i];
      tmp->next = list;
      list = tmp;
      i++;
    }
  return (list);
}
void		free_list(t_environ *list)
{
  t_environ *next;

  while (list != NULL)
    {
      next = list->next;
	  free(list);
      list = next;
    }
}

void		pprintenv(t_environ *list)
{
  while (list != NULL)
    {
      pprint(list->data, 1);
      pprint("\n", 1);
      list = list->next;
    }
  write(1, "\n", 1);
}
