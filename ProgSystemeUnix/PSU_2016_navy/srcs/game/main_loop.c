/*
** M_loop.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/game/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 19:15:53 2017 John Doe
** Last update Sun Feb 19 18:30:40 2017 John Doe
*/

#include "navy.h"
#include <stdlib.h>

const char 	*check_resp(char *resp)
{
  return (resp[0] == 'H') ? ("HIT\n\n") : ("MISS\n\n");
}

int		attack(int *i)
{
  *i += 1;
  sender(proto.ptr.sender_pid, *proto.oldact);
  receiver(*proto.oldact);
  write(1, proto.ptr.bfrcpy, 3);
  write(1, ": ", 2);
  write(1, check_resp(proto.ptr.bfr), 6);
  update_map(check_resp(proto.ptr.bfr), proto.ptr.map, 2, proto.ptr.bfrcpy);
  free(proto.ptr.bfrcpy);
  return (1);
}

int		recept(int *i)
{
  i += 1;
  write(1, "waiting for enemy's attack...\n", 31);
  receiver(*proto.oldact);
  write(1, proto.ptr.bfr, 3);
  write(1, ": ", 2);
  write(1, check_hit(proto.ptr.map, proto.ptr.bfr), 6);
  trad_resp(check_hit(proto.ptr.map, proto.ptr.bfr));
  usleep(2000);
  send_message(proto.ptr.resp, proto.ptr.sender_pid, *proto.oldact);
  update_map(check_hit(proto.ptr.map, proto.ptr.bfr), \
	     proto.ptr.map, 1, proto.ptr.bfr);
  return (1);
}

int		M_loop(void)
{
  int i;

  i = 0;
  while (check_win_loose(proto.ptr.map->map) != 1 && \
	 check_win_loose(proto.ptr.map->enemy_map) != 0)
    {
      if (proto.turn == 1)
	{
    if (attack(&i))
	    proto.turn = 0;
	}
      else if (proto.turn == 0)
	{
	  if (recept(&i))
	    proto.turn = 1;
	}
      (i % 2) ? (affich_map(proto.ptr.map)) : i;
    }
  endcom(&i);
  return (endgame());
  return (2);
}
