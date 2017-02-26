/*
** games.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/v1.1/srcs/game/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Feb  1 19:13:35 2017 John Doe
** Last update	Sun Feb 05 22:38:53 2017 Full Name
*/

#include "navy.h"
#include <stdlib.h>

/*
** this function wait for
** the other player connection
*/
int			wait_forP1(struct sigaction *init, int pid)
{
  init->sa_sigaction = initcom;
  sigemptyset(&init->sa_mask);
  init->sa_flags = SA_SIGINFO;
  p_printf(1, "my_pid: %d\n", getpid());
  sigaction(SIGUSR1, init, NULL);
  sigaction(SIGUSR2, init, NULL);
  kill(pid, SIGUSR1);
  pause();
  return (1);
}
/*
** Main game loop for
** "2nd" player handle
** sigaction struct initialisation
** and buffer filling.
*/
int 		P2_game(const char *filename, int pid)
{
  int	rt;
  t_map	*map;
  struct sigaction init;

  rt = 2;
  if ((map = malloc(sizeof(*map))) == NULL)
    return (-1);
  if (check_f(filename, map) == -1)
    return (-1);
  proto.ptr.map = map;
  proto.turn = 0;
  proto.oldact = &init;
  proto.ptr.sender_pid = pid;
  if (wait_forP1(&init, pid))
    {
      affich_map(proto.ptr.map);
      rt = M_loop();
      return (rt == 1) ? (1) : (0);
    }
  free(map);
  return (0);
}
