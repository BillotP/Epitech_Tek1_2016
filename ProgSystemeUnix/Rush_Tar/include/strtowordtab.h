/*
** strtowordtab.h for CPE_2016_B2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/include/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:58:32 2017 Bender_Rodriguez
** Last update Sun Mar  5 22:16:02 2017 Bender_Rodriguez
*/

#ifndef STRTOWORDTAB_H_
# define STRTOWORDTAB_H_

typedef struct s_count {
  int		i;
  int		j;
  int		wrd;
}							t_count;

/*
** strtowordtab.c
*/

int			init_buffer(char *str, const char *delim, char ***tab);
int			check_words(char c, const char *delim);
void		move_str(int *i, int *linesize, char *str, const char *delim);
char		**strto_wordtab(char *str, const char *delim);

#endif
