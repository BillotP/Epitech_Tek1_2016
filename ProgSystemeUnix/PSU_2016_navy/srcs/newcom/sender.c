/*
** main.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/test/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 10 09:23:53 2017 John Doe
** Last update Sun Feb 19 19:50:55 2017 John Doe
*/

#include "navy.h"
#include <stdlib.h>

/*
** Get user input expression
** 1 if values are
** and message sent.
** zero otherwise.
*/
int			sender(int pid, struct sigaction oldact)
{
  char	*cmd;

  print_prompt();
  while (1)
{
      cmd = get_next_line(0);
      if ((isokcmd(cmd)) && len(cmd) == 2)
	{
	  cmd = correct_input(cmd);
	  proto.ptr.bfrcpy = my_strdup(cmd);
    usleep(6666);
	  send_message(cmd, pid, oldact);
	  return (1);
	}
      else
	write(1, "wrong position\n", 15);
      print_prompt();
      free(cmd);
    }
  return (0);
}
