/*
** pshellv2.c for Pshell in /home/bender/GrowUp/snippetsandmore/shellv1/V2/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 27 23:09:16 2016 John Doe
** Last update	Tue Jan 03 15:25:12 2017 Full Name
*/

#include "pshell.h"

int		parse_env(char **env, char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (env[i])
    {
      while (env[i][j])
	{
	  if (env[i][0] == str[0] && env[i][1] == str[1] && env[i][2] == str[2])
	    return (i);
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}
char				*stradd(char *src, char *next)
{
  ssize_t		len_src;
  ssize_t		i;

  i = 0;
  len_src = len(src);
  src[len_src] = '/';
  while (next[i])
    src[++len_src] = next[i++];
  src[len_src + 1] = '\0';
  return (src);
}
void		 		exec(char **args, char **environ, char *buff)
{
  char			**path;
  int				*wstatus;
  int				i, j, exe, cpid;

  path = NULL;
  wstatus = 0;
  i = j = exe = cpid = 0;
  if ((cpid = fork()) == -1)
    errors("Fork error");
  i = parse_env(environ, "PAT");
  path = strtowordtab(environ[i] + 5, ':');
  i = 0;
  while (path[i])
    i++;
  if ((cpid = waitpid(-1, wstatus, 0)) == -1)
    while (path[j])
	while ((exe = execve(stradd(path[j++], args[0]), args, environ)))
	    if (exe == -1 && j == i)
		{
		  pprint(args[0], 2);
		  pprint(": command not found\n", 2);
		  free(buff);
		}
}

void		loop(char **environ)
{
  char		*buffer;
  char		**args;
  char		delim;
  ssize_t	rd;

  rd = 0;
  args = NULL;
  delim = ' ';
  buffer = NULL;
  while ((buffer = readline(PROMPT)))
    {
      buffer[len(buffer) + 1] = '\0';
      shortcuts(buffer);
      if (buffer[0] == 'c' && buffer[1] == 'd')
	{
	  environ = change_path(environ, buffer);
	  *buffer = '\0';
	}
      args = strtowordtab(buffer, delim);
      exec(args, environ, buffer);
      free(buffer);
    }
}
