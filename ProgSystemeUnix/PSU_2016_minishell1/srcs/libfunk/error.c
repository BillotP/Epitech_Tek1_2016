/*
** error.c for Minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 22:40:27 2017 John Doe
** Last update	Sat Jan 21 10:20:57 2017 Full Name
*/

#include "../../include/base.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int		p_exit(const char *str, int exitval)
{
  write(2, str, len(str));
  return (exitval);
}
int		errors(const char *errmsg, int exitval)
{
  write(2, errmsg, len(errmsg));
  exit (exitval);
}
