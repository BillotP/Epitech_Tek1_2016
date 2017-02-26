/*
** sigauxbitwised.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/test/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 10 09:23:24 2017 John Doe
** Last update Sat Feb 18 12:32:39 2017 John Doe
*/

#include "navy.h"
#include <string.h>

/*
** Support function
** to send bits in good
** order. filling a char array
** with the bits in int message
*/
const char 		*byte_to_binary(unsigned int x)
{
  int 				z;
  static char b[17];

  b[0] = '\0';
  z = 512;
  while (z > 0)
    {
      my_strcatvs(b, ((x & z) == z) ? "1" : "0");
      z >>= 1;
    }
  return (b);
}
/*
** Init and reseting message reception's
** counters and datas.
*/
void	init_list(t_sender *list, const char *message)
{
  list->i = 0;
  list->k = 15;
  list->msg[0] = message[0];
  list->msg[1] = message[1];
}
/*
** Message reception check
** with pingpong method.
** Send signal to sender
** when one received.
*/
void								init_pingpong(struct sigaction oldact)
{
  struct sigaction	pingpong;

  pingpong.sa_sigaction = pphandler;
  sigemptyset(&pingpong.sa_mask);
  pingpong.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &pingpong, &oldact);
  sigaction(SIGUSR2, &pingpong, &oldact);
}
/*
** Core sending message function
** Parsing the "bits" in reverse order
** on char array and sending signal accordingly
** SIGUSR1 for 0 and SIGUSR2 for 1.
*/
void					send_message(const char *message, int pid, \
						     struct sigaction oldact)
{
  t_sender		list;

  init_pingpong(oldact);
  init_list(&list, message);
  while (list.i != 2)
{
      list.msg[list.i] ^= END_TRANSMISSION(9, 10);
      list.bfr = byte_to_binary(list.msg[list.i]);
      while (list.k != -1)
	{
	  if (list.bfr[list.k] == '0')
	    {
	      kill(pid, SIGUSR1);
	      pause();
	    }
	  else if (list.bfr[list.k] == '1')
	    {
	      kill(pid, SIGUSR2);
	      pause();
	    }
	  list.k--;
	}
      list.k = 15;
      list.i = list.i + 1;
    }
}
