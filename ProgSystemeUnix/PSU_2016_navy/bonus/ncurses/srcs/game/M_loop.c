/*
** M_loop.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/game/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 19:15:53 2017 John Doe
** Last update Sun Feb 19 00:51:57 2017 clement cazaubon
*/

#include "navy.h"

const char 	*check_resp(char *resp)
{
  if (resp[0] == 'H')
    return ("HIT");
  else if (resp[0] == 'M')
    return ("MISS");
  return (NULL);
}

int		attack(void)
{
  sender(proto.ptr.sender_pid, *proto.oldact);
  receiver(*proto.oldact);
  printw("%s: %s\n\n", proto.ptr.bfrcpy, check_resp(proto.ptr.bfr));
  update_map(check_resp(proto.ptr.bfr), proto.ptr.map, 2, proto.ptr.bfrcpy);
  free(proto.ptr.bfrcpy);
  return (1);
}

int		recept(void)
{
  printw("waiting for enemy's attack...\n");
  receiver(*proto.oldact);
  printw("%s: %s\n\n", proto.ptr.bfr, \
     check_hit(proto.ptr.map, proto.ptr.bfr));
  trad_resp(check_hit(proto.ptr.map, proto.ptr.bfr));
  send_message(proto.ptr.resp, proto.ptr.sender_pid, *proto.oldact);
  update_map(check_hit(proto.ptr.map, proto.ptr.bfr), \
	     proto.ptr.map, 1, proto.ptr.bfr);
  return (1);
}

int		M_loop(void)
{
  int i;

  i = 1;
  while (check_win_loose(proto.ptr.map->map) != 1)
    {
      if (proto.turn == 1)
	{
	  i++;
    if (attack())
	    proto.turn = 0;
	}
      else if (proto.turn == 0)
	{
	  i++;
	  if (recept())
	    proto.turn = 1;
	}
      if ((i % 2))
	affich_map(proto.ptr.map);
    }
  return (0);
}
