/*
** receiver.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/newcom/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Feb 11 11:00:59 2017 John Doe
** Last update Sun Feb 19 19:16:47 2017 John Doe
*/

#include "navy.h"
#include <signal.h>

/*
** Analyse struct counters
** to stop reception
** when valid message received
*/
int		check_message(void)
{
  if (proto.count == 2)
    {
      proto.ptr.bfr[proto.count + 1] = '\0';
      proto.count = 0;
      return (1);
    }
  return (0);
}
/*
** Signal handler who receive
** the "pseudo binary" message.
** Setting bit at one on good position
** on the unsigned int who encode the message.
** with the help of the below macro.
*/
void		receive_msg(int signum, siginfo_t *info, void *context)
{
  if (signum == SIGUSR1)
    {
      proto.pos++;
      kill(proto.ptr.sender_pid, SIGUSR2);
    }
  else if (signum == SIGUSR2)
    {
      proto.ptr.message |= SET_ONE(proto.pos);
      proto.pos++;
      kill(proto.ptr.sender_pid, SIGUSR1);
    }
  if ((proto.pos == 10) && (proto.ptr.message & END_TRANSMISSION(9, 10)))
    {
      proto.ptr.bfr[proto.count++] = proto.ptr.message;
      proto.ptr.message = 0;
      proto.pos = 0;
    }
}
/*
** Main receive handler function.
** check counter and gather the
** signal with sigaction.
** Note : thread "paused" to avoid
** cpu overcharge.
*/
int			receiver(struct sigaction oldact)
{
  struct sigaction cli;

  proto.ptr.bfr[0] = '\0';
  cli.sa_sigaction = receive_msg;
  sigemptyset(&cli.sa_mask);
  cli.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &cli, &oldact);
  sigaction(SIGUSR2, &cli, &oldact);
  while (!check_message())
    pause();
  return (1);
}
