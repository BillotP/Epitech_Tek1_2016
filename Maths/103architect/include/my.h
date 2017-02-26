/*
** my.h for 103Architect in /home/bender/Repo/103architect/clement
**
** Made by Junior Bender
** Login   <bender@epitech.net>
**
** Started on  Tue Dec  6 16:58:24 2016 Junior Bender
** Last update Tue Dec 13 12:44:54 2016 clement cazaubon
*/
#ifndef MY_H_
#define MY_H_

# define ERRARG "Error: too few argument"

#include <math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct chain_list t_list;
struct chain_list {
  float					matrix[3][3];
  float					buffer[3][3];
  t_list 				*next;
};

int				is_number(char *str);
void			translation(int ac, char **av);
void			homothety(int ac, char **av);
void			rotation(int ac, char **av);
void			symetry(int ac, char **av);
void			set_flags(int ac, char **av);
int				printerr(char *errormsg);
int				set_multy_flag(int ac, char **av, int i, int bol, t_list *maillon);
void			translationM(int ac, char **av, int i, t_list *maillon);
void			homothetyM(int ac, char **av, int i, t_list *maillon);
void			rotationM(int ac, char **av, int i, t_list *maillon);
void			symetryM(int ac, char **av, int i, t_list *maillon);
void			multicalc(int ac, char**av);
void			multi_calc(int ac, char **av);
t_list		*initLC();
t_list		*LCfirst();
t_list		*LCadd(t_list *list);
t_list 		*fill_list(t_list *list);
void			print_list(t_list *list, float new_coord1, float new_coord2, char **av);
void			LCfree(t_list *list);
void			feed_matrix(t_list *list, float matrix[3][3]);
t_list				*set_multy_flags(int ac, char **av, int i, int *bol, t_list *list);

#endif
