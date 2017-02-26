/*
** P1game.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/game/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Feb 11 11:44:49 2017 John Doe
** Last update Fri Feb 17 20:22:19 2017 John Doe
*/

#include "navy.h"

/*
** this function wait for
** the other player connection
** return 1 if connection engaged.
*/
int				wait_forP2(struct sigaction *init)
{
  init->sa_sigaction = initcom;
  sigemptyset(&init->sa_mask);
  init->sa_flags = SA_SIGINFO;
  p_printf(1, "my_pid: %d\n", getpid());
  p_printf(1, "waiting for enemy connexion...\n");
  sigaction(SIGUSR1, init, NULL);
  sigaction(SIGUSR2, init, NULL);
  pause();
  return (1);
}
/*
** Main game loop for
** first player. Handle
** sigaction struct initialisation
** and buffer filling (map and counters)
*/
int				P1_game(const char *filename)
{
  t_map   *map;
  struct sigaction init;

  if ((map = malloc(sizeof(*map))) == NULL)
    errors("Malloc error\n", 84);
  check_f(filename, map);
  proto.ptr.map = map;
  if (wait_forP2(&init))
    {
      proto.oldact = &init;
      proto.turn = 1;
      affich_map(proto.ptr.map);
      M_loop();
    }
  free(map);
  return (0);
}
