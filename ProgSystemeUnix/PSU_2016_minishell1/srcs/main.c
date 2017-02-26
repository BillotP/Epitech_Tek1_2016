/*
** main.c for minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 22:55:53 2017 John Doe
** Last update	Thu Jan 19 15:19:45 2017 Full Name
*/

#include "../include/base.h"
#include "../include/shell1.h"

int				main(int ac, char **av, char **environ)
{
  ac = ac + 42;
  av = av + 42;
  if ((isatty(0)))
    pprint(PROMPT, 1);
  if ((exec_that(environ)) == 1)
    return (1);
  return (0);
}
