/*
** check.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Dec 12 15:54:03 2016 Leandre Blanchard
** Last update Tue Dec 20 16:16:34 2016 Léandre Blanchard
*/

#include "include/sokoban.h"

int	count_x(char **tab, char *path)
{
  int	i;
  int	j;
  int   nb;

  nb = 0;
  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (j != line_len(path))
	{
	  if (tab[i][j] == 'X')
	    nb = nb + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  return (nb);
}

int	check_lose(char **tab, char *path)
{
  int	i;
  int   j;
  int	blocs;

  blocs = 0;
  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (j != line_len(path))
	{
	  if (tab[i][j] == 'X' && check_boxes(tab, i, j) == 1)
	    blocs = blocs + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  if (blocs == count_x(tab, path))
    return (1);
  return (0);
}

int	check_boxes(char **tab, int x, int y)
{
  if ((tab[x - 1][y] == '#' || tab[x - 1][y] == 'X')
      && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
	  || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
    return (1);
  if ((tab[x + 1][y] == '#' || tab[x + 1][y] == 'X')
      && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
	  || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
    return (1);
  return (0);
}

int		p_x_o_check(char **tab, char *buffer)
{
  t_xy		x_o;
  t_vars	v;

  v.k = 0;
  v.i = 0;
  x_o = xy_tuple(0, 0);
  while (tab[v.i] != NULL)
    {
      v.j = 0;
      while (v.j != line_len(buffer))
	{
	  if (tab[v.i][v.j] == 'X' || tab[v.i][v.j] == 'O')
	    (tab[v.i][v.j] == 'X') ? x_o.x++ : x_o.y++;
	  if (tab[v.i][v.j] == 'P')
	    v.k = v.k + 1;
	  v.j = v.j + 1;
	}
      v.i = v.i + 1;
    }
  if (x_o.x == x_o.y && v.k == 1)
    return (0);
  if (x_o.x != x_o.y)
    return (1);
  if (v.j != 1)
    return (2);
}
