/*
** xy_fonctions.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Dec  5 14:25:38 2016 Leandre Blanchard
** Last update Tue Dec 13 17:05:41 2016 Leandre Blanchard
*/

#include "include/sokoban.h"

t_xy		xy_tuple(int x, int y)
{
  t_xy		xy;

  xy.x = x;
  xy.y = y;
  return (xy);
}

t_xy		get_pos(char **tab)
{
  int		i;
  int		j;
  t_xy		xy;

  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == 'P')
	    xy = xy_tuple(i, j);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (xy);
}

int		nb_of_dots(char **tab)
{
  int		i;
  int		j;
  int		dots;

  i = 0;
  dots = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == 'O')
	    dots = dots + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  return (dots);
}

t_xy		*add_coord(t_xy *posdot, char **tab)
{
  int		i;
  int		j;
  int		k;

  k = 0;
  i = 0;
  j = 0;
  if ((posdot = malloc(sizeof (t_xy) * nb_of_dots(tab) + 1)) == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == 'O')
	    {
	      posdot[k] = xy_tuple(i, j);
	      k = k + 1;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  posdot[k] = xy_tuple(2000, 2000);
  return (posdot);
}

int		check_spot(char **tab, t_xy *posdot)
{
  int		k;
  int		i;

  i = 0;
  k = 0;
  while (posdot[k].x < (2000))
    {
      if (tab[posdot[k].x][posdot[k].y] == ' ')
	tab[posdot[k].x][posdot[k].y] = 'O';
      if (tab[posdot[k].x][posdot[k].y] == 'O')
	i = 1;
      if (tab[posdot[k].x][posdot[k].y] == 'P')
	i = 1;
      k = k + 1;
    }
  if (i == 1)
    return (1);
  return (0);
}
