/*
** main.c for PShellV2 in /home/bender/Desktop/Snippets/bookv2/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Dec 23 21:02:14 2016 John Doe
** Last update	Mon Jan 02 17:08:07 2017 Full Name
*/

#include "pshell.h"

char			**set_env(char **environ)
{
  int			i;

  i = 0;
  i = parse_env(environ, "SHELL");
  if ((i))
    {
      environ[i] = NAME;
	  return (environ);
    }
  errors("No such environnement");
  return (NULL);
}

int							main(int ac, char **av, char **environ)
{
  av = NULL;
  signal(SIGINT, SIG_IGN);
  pprint(INTRO, 1);
  if (!getuid())
    pprint(ROOT_ERR, 1);
  environ = set_env(environ);
  while (ac)
	{
	  loop(environ);
	  return (0);
	}
      return (0);
}
