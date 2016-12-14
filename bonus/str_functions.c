/*
** str_functions.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Dec  5 13:03:44 2016 Leandre Blanchard
** Last update Tue Dec 13 17:06:15 2016 Leandre Blanchard
*/

#include "include/sokoban.h"

int                     line_len(char *str)
{
  int                   i;

  i = 0;
  while (str[i] != '\n')
    i = i + 1;
  return (i);
}

int                     nb_of_line(char *str)
{
  int                   i;
  int                   nb;

  i = 0;
  nb = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\n')
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

int			my_tablen(char **tab)
{
  int			i;

  i = 0;
  while (tab[i] != NULL)
    i = i + 1;
  return (i);
}

char            **str_to_tab(char *str)
{
  int           i;
  int           j;
  int           k;
  char          **tab;

  i = 0;
  k = 0;
  if ((tab = malloc(sizeof (char *) * nb_of_line(str) + 1)) == NULL)
    exit(MALLOC_ERROR);
  tab[nb_of_line(str)] = NULL;
  while (str[i] != 0)
    {
      j = 0;
      if ((tab[k] = malloc(sizeof (char *) * line_len(str) + 1)) == NULL)
	exit(MALLOC_ERROR);
      while (str[i] != '\n' && tab[k] != NULL)
	{
	  tab[k][j] = str[i];
	  i = i + 1;
	  j = j + 1;
	}
      k = k + 1;
      i = i + 1;
    }
  return (tab);
}

char		**restart_path(char *input)
{
  char		**path;

  path = malloc(sizeof (char *) * 3);
  path[0] = my_strdup("./sokoban");
  path[1] = my_strdup(input);
  path[2] = NULL;
  return (path);
}
