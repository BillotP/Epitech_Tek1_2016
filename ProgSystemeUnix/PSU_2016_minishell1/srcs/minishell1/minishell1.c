/*
** minishell1.c for Minishell1 in /home/bender/Repo/PSU_2016_minishell1/v1.2/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Jan 17 19:39:33 2017 John Doe
** Last update	Sun Jan 22 14:04:16 2017 Full Name
*/

#include <wait.h>
#include "../../include/errors.h"
#include "../../include/shell1.h"

int handlepid(int pid, t_pid *ptr);

int handlepid(int pid, t_pid *ptr) {
    if ((pid))
    {
        ptr->ctrl = waitpid(pid, &ptr->status, WUNTRACED | WCONTINUED);
        do {
            if (ptr->ctrl == -1)
                errors(strerror(errno), 84);
            if (WIFEXITED(ptr->status))
                return (0);
            else if (WIFSIGNALED(ptr->status))
            {
                if (WTERMSIG(ptr->status) == 11)
                    p_exit(SEGFLT, 139);
                if (WTERMSIG(ptr->status) == 8)
                    p_exit(FPERR, 136);
            }
            else if (WIFSTOPPED(ptr->status))
                pprint("process stopped\n", 1);
            else if (WIFCONTINUED(ptr->status))
                pprint("continued\n", 1); }
        while (!WIFEXITED(ptr->status) && !WIFSIGNALED(ptr->status));
        return (0); }
    return (1);
}

int				forkandrun(t_shell *list, char **env)
{
  int			way;
  t_pid   pid;
  t_pid   *ptr;

  ptr = &pid;
  pid.status = 0;
  if ((way = findgoodpath(list->args[0], list->paths)) == -1)
    return (p_exit(my_strcat(list->args[0], NOEXEC), 1));
  if ((pid.urmyson = fork()) < 0)
    errors(strerror(errno), 84);
  else if (pid.urmyson == 0)
    {
      if ((execve(my_strcat(list->paths[way], list->args[0]), list->args, env)\
	   == -1) && (execve(list->args[0], list->args, env)) < 0)
	{
	  if ((errno = 13))
	    errors(my_strcat(list->args[0], NOPERM), 1);
	  errors(my_strcat(strerror(errno), "\n"), 1);
	  return (1);
	}
    }
  else if (pid.urmyson > 0)
    handlepid(pid.urmyson, ptr);
  return (0);
}

int				exec_that(char **environ)
{
  t_shell list;
  t_shell *ptr;
  static int	ctrl = 0;
  char		**t_env;

  t_env = init_shell(&list, environ);
  ptr = &list;
  signal(SIGINT, SIG_IGN);
  while ((list.user_input = clean_args(get_next_line(0))))
    {
      if ((built_in(list.user_input, t_env)) == 1)
	{
	  list.args = strto_wordtab(list.user_input, " ");
	  if ((ctrl = forkandrun(ptr, t_env)) == 1)
	    ctrl = ctrl + 1;
	}
      if ((isatty(0)))
	pprint(PROMPT, 1);
      free(list.user_input);
    }
  if ((isatty(0)))
    pprint("exit\n", 1);
  return (ctrl);
}

char		**init_shell(t_shell *list, char **environ)
{
  char 	**t_env;
  int		pos;

  pos = 0;
  if ((!(environ[0])) || (!environ[1]))
    {
      list->tmpenv = my_strdup(TENV);
      t_env = strto_wordtab(list->tmpenv, " ");
      list->paths = strto_wordtab(t_env[0] + len("PATH="), ":");
      return (t_env);
    }
  t_env = dup_env(environ);
  pos = find_inenv(t_env, "PATH=");
  list->paths = strto_wordtab(t_env[pos] + len("PATH="), ":");
  return (t_env);
}
