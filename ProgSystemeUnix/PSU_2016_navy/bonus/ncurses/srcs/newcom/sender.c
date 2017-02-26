/*
** main.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/test/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 10 09:23:53 2017 John Doe
** Last update Sun Feb 19 01:12:30 2017 clement cazaubon
*/

#include "navy.h"

/*
** Parse user input expression
** and return 1 if values are good
** zero otherwise.
*/
int			isokcmd(char *cmd)
{
  int		i;
  int		ok;
  const char  *legitchar;

  ok = i = 0;
  legitchar = "ABCDEFGHabcdefgh12345678";
  while (legitchar[i])
    {
      if (cmd[0] == legitchar[i])
	ok++;
      if (cmd[1] == legitchar[i])
	ok++;
      i++;
    }
  if (ok == 2)
    return (1);
  return (0);
}
/*
** Get user input expression
** and return 1 if values are
** and message sent.
** zero otherwise.
*/
int			sender(int pid, struct sigaction oldact)
{
  char	cmd[10000];

  printw("\x1B[0mattack: ");
  printw("\x1B[3m");
  while (1)
    {
      getstr(cmd);
      printw("%d\n", cmd);
      if ((isokcmd(cmd)) && len(cmd) == 2)
	{
	  proto.ptr.bfrcpy = my_strdup(cmd);
    send_message(cmd, pid, oldact);
	  return (1);
	}
      else
	printw("wrong position\n");
      printw("\x1B[0mattack: ");
      printw("\x1B[3m");
    }
  return (0);
}
