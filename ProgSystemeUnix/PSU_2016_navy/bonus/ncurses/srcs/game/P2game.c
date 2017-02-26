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

/*
** this function wait for
** the other player connection
** return 1 if connection engaged.
*/
int			wait_forP1(struct sigaction *init, int pid)
{
  proto.ptr.sender_pid = pid;
  init->sa_sigaction = initcom;
  sigemptyset(&init->sa_mask);
  init->sa_flags = SA_SIGINFO;
  p_printf(1, "my_pid: %d\n", getpid());
  kill(pid, SIGUSR1);
  sigaction(SIGUSR1, init, NULL);
  sigaction(SIGUSR2, init, NULL);
  pause();
  // affich_map(proto.ptr.map);
  // p_printf(1, "Waiting for enemy's attack...\n");
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
  t_map	*map;
  struct sigaction init;

  if ((map = malloc(sizeof(*map))) == NULL)
    errors("Malloc error\n", 84);
  check_f(filename, map);
  proto.ptr.map = map;
  proto.turn = 0;
  if (wait_forP1(&init, pid))
    {
      proto.oldact = &init;
      affich_map(proto.ptr.map);
      M_loop();
    }
  free(map);
  return (0);
}
