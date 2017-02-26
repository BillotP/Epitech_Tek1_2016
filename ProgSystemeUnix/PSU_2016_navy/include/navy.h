/*
** navy.h for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/include/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 10 09:24:32 2017 John Doe
** Last update Sun Feb 19 19:32:38 2017 John Doe
*/

#ifndef NAVY_H_
# define NAVY_H_

#include <signal.h>

#include "usage.h"
#include "base.h"
#include "get_next_line.h"
#include "printf.h"
#include "strtowordtab.h"
#include "map.h"

/* ********************************* */
/*
** communication protocol functions
** and structures.
*/
#define END_TRANSMISSION(a, b) ((1 << a) | (1 << b))
/*
** Macro for bits left shift
** traducing binary sigals
** usr1 = 0 & usr2 = 1 in
** their ascii values.
*/
#define SET_ONE(pos) (1 << pos)

typedef struct s_sender {
  int						k;
  int						i;
  unsigned int	msg[4];
  const char 		*bfr;
}							t_sender;

struct data {
  unsigned int	message;
  int  					sender_pid;
  char   				bfr[4];
  char					*bfrcpy;
  char					resp[4];
  t_map  				*map;
};

struct count {
  int					turn;
  int 				pos;
  int 				count;
  struct data ptr;
  struct sigaction *oldact;
};

struct count proto;

int					receiver(struct sigaction oldact);
int					sender(int pid, struct sigaction oldact);
int					isokcmd(char *cmd);
int					check_message(void);
int					print_message(void);
int					waitfor_response(void);
char				*correct_input(char *cmd);
const char	*byte_to_binary(unsigned int msg);
void				trad_resp(const char *resp);
void 				swap(char *xp, char *yp);
void				print_prompt(void);
void			  receive_msg(int signum, siginfo_t *info, void *context);
void				send_message(const char *message, int pid, \
						     struct sigaction oldact);

/*
***************************************************
***************************************************
*/
/*
** Game loops
*/
int					start(const char *pathname);
int					P1_game(const char *filename);
int 				P2_game(const char *filename, int serv_pid);
int					M_loop(void);
int					attack(int *i);
int					recept(int *i);
int					endgame(void);
const char 	*check_resp(char *resp);
void 				endcom(int *i);
void				initcom(int signum, siginfo_t *info, void *context);
void				pphandler(int signum, siginfo_t *info, void *context);

#endif
