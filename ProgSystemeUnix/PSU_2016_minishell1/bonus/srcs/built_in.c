/*
** built_in.c for minishell1 in /home/bender/Repo/PSU_2016_minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan  9 09:54:38 2017 John Doe
** Last update Tue Jan 10 08:06:49 2017 John Doe
*/

#include "pshell.h"

char		**change_path(char **environ, char *path)
{
  int		i;
  char	*buffer;

  i = 0;
  if ((buffer = malloc(sizeof(*buffer) * BUFFERSIZE)) == NULL)
    errors("malloc error\n");
  i = parse_env(environ, "OLDPWD");
  environ[i] = NULL;
  environ[i] = my_strcat("OLDPWD=", getcwd(buffer, BUFFERSIZE));
  i = 0;
  if ((chdir(path + 3)) == - 1)
    pprint("No such file or directory\n", 2);
  i = parse_env(environ, "PWD=");
  environ[i] = NULL;
  environ[i] = my_strcat("PWD=", getcwd(buffer, BUFFERSIZE));
  return (environ);
}
