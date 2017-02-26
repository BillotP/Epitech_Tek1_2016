/*
** pingpong.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/game/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Feb 11 11:53:39 2017 John Doe
** Last update Sun Feb 19 19:10:29 2017 John Doe
*/

#include "navy.h"

/*
** Signal handler for
** waitfor* function group
** pingpong method.
*/
void			initcom(int signum, siginfo_t *info, void *context)
{
  if (signum == SIGUSR1)
    {
      proto.turn += 1;
      if (proto.turn == 1)
	{
	  p_printf(1, "enemy connected\n\n");
	  proto.turn += 1;
	  kill(info->si_pid, SIGUSR2);
	}
      proto.turn = 1;
    }
  else if (signum == SIGUSR2)
    {
      proto.turn += 1;
      if (proto.turn == 1)
	p_printf(1, "successfully connected\n\n");
      proto.turn = 0;
    }
  proto.ptr.sender_pid = info->si_pid;
}

/*
** Signal handler for sender function group
** with ping-pong method.
** Update counters in struct regarding the
** number of bits aka signum received.
*/
void		pphandler(int signum, siginfo_t *info, void *context)
{
  static int p1 = 0;
  static int p2 = 0;

  if (signum == SIGUSR1)
    p1++;
  else if (signum == SIGUSR2)
    p2++;
}

void	trad_resp(const char *resp)
{
  if (resp[0] == 'H')
    {
      proto.ptr.resp[0] = 'H';
      proto.ptr.resp[1] = '1';
    }
  else if (resp[0] == 'M')
    {
    proto.ptr.resp[0] = 'M';
    proto.ptr.resp[1] = '1';
    }
}
