/*
** setenv.h for Minishell1 in /home/bender/snippets/setenv/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Jan 18 16:32:03 2017 John Doe
** Last update	Sun Jan 22 09:42:00 2017 Full Name
*/

#ifndef SETENV_H_
# define SETENV_H_

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

typedef struct s_env {
int						pos;
char					*data;
struct s_env	*next;
}							t_env;

t_env		*env_inlist(char **environ);
void		pprintenv(void);
void		free_list(t_env *list);
t_env		*add_toenv(const char *newdata, int pos);
int 		list_size(t_env *list);

#endif
