/*
** setenv.h for Minishell1 in /home/bender/snippets/setenv/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Jan 18 16:32:03 2017 John Doe
** Last update Fri Jan 20 23:10:21 2017 John Doe
*/

#ifndef SETENV_H_
# define SETENV_H_

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

typedef struct s_env {
char					*data;
struct s_env	*next;
}							t_environ;

t_environ		*env_inalist(char **nb);
void				pprintenv(t_environ *list);
void				free_list(t_environ *list);

#endif
