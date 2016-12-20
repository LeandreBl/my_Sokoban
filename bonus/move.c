/*
** move.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Dec  5 15:25:01 2016 Leandre Blanchard
** Last update Tue Dec 20 18:06:45 2016 Léandre Blanchard
*/

#include "include/sokoban.h"

t_xy            check_pos_mvt(char **tab, t_xy xy, char *path, int color)
{
  int		alpha;
  int		move;

  keypad(stdscr, TRUE);
  alpha = getch();
  if (alpha == KEY_UP)
    xy = move_up(tab, xy);
  if (alpha == KEY_DOWN)
    xy = move_down(tab, xy);
  if (alpha == KEY_LEFT)
    xy = move_left(tab, xy);
  if (alpha == KEY_RIGHT)
    xy = move_right(tab, xy);
  if (alpha == 32)
    terrain_display(str_to_tab(path), path, color);
  if (alpha == 'm')
    sfMusic_pause(theme);
  if (alpha == 'M')
    sfMusic_play(theme);
  if (alpha == 10)
    {
      endwin();
      exit(QUIT);
    }
  return (xy);
}

t_xy		move_right(char **tab, t_xy xy)
{
  if (tab[xy.x][xy.y + 1] != '#' && tab[xy.x][xy.y + 1] != 'X'
      && tab[xy.x][xy.y] == 'P')
    {
      tab[xy.x][xy.y] = ' ';
      tab[xy.x][xy.y + 1] = 'P';
      xy = get_pos(tab);
    }
  else if (tab[xy.x][xy.y + 1] == 'X' && tab[xy.x][xy.y + 2] != '#'
	   && tab[xy.x][xy.y + 2] != 'X' && tab[xy.x][xy.y] == 'P')
    {
      if (tab[xy.x][xy.y + 2] == 'O')
	sfMusic_play(sfMusic_createFromFile("coin.ogg"));
      tab[xy.x][xy.y] = ' ';
      tab[xy.x][xy.y + 1] = 'P';
      tab[xy.x][xy.y + 2] = 'X';
      xy = get_pos(tab);
    }
  return (xy);
}

t_xy            move_left(char **tab, t_xy xy)
{
  if (tab[xy.x][xy.y - 1] != '#' && tab[xy.x][xy.y - 1] != 'X'
      && tab[xy.x][xy.y] == 'P')
    {
      tab[xy.x][xy.y] = ' ';
      tab[xy.x][xy.y - 1] = 'P';
      xy = get_pos(tab);
    }
  else if (tab[xy.x][xy.y - 1] == 'X' && tab[xy.x][xy.y - 2] != '#'
	   && tab[xy.x][xy.y - 2] != 'X' && tab[xy.x][xy.y] == 'P')
    {
      if (tab[xy.x][xy.y - 2] == 'O')
	sfMusic_play(sfMusic_createFromFile("coin.ogg"));
      tab[xy.x][xy.y] = ' ';
      tab[xy.x][xy.y - 1] = 'P';
      tab[xy.x][xy.y - 2] = 'X';
      xy = get_pos(tab);
    }
  return (xy);
}

t_xy            move_up(char **tab, t_xy xy)
{
  if (tab[xy.x - 1][xy.y] != '#' && tab[xy.x - 1][xy.y] != 'X'
      && tab[xy.x][xy.y] == 'P')
    {
      tab[xy.x][xy.y] = ' ';
      tab[xy.x - 1][xy.y] = 'P';
      xy = get_pos(tab);
    }
  else if (tab[xy.x - 1][xy.y] == 'X' && tab[xy.x - 2][xy.y] != '#'
	   && tab[xy.x - 2][xy.y] != 'X' && tab[xy.x][xy.y] == 'P')
    {
      if (tab[xy.x - 2][xy.y] == 'O')
	sfMusic_play(sfMusic_createFromFile("coin.ogg"));
      tab[xy.x][xy.y] = ' ';
      tab[xy.x - 1][xy.y] = 'P';
      tab[xy.x - 2][xy.y] = 'X';
      xy = get_pos(tab);
    }
  return (xy);
}

t_xy            move_down(char **tab, t_xy xy)
{
  if (tab[xy.x + 1][xy.y] != '#' && tab[xy.x + 1][xy.y] != 'X'
      && tab[xy.x][xy.y] == 'P')
    {
      tab[xy.x][xy.y] = ' ';
      tab[xy.x + 1][xy.y] = 'P';
      xy = get_pos(tab);
    }
  else if (tab[xy.x + 1][xy.y] == 'X' && tab[xy.x + 2][xy.y] != '#'
	   && tab[xy.x + 2][xy.y] != 'X' && tab[xy.x][xy.y] == 'P')
    {
      if (tab[xy.x + 2][xy.y] == 'O')
	sfMusic_play(sfMusic_createFromFile("coin.ogg"));
      tab[xy.x][xy.y] = ' ';
      tab[xy.x + 1][xy.y] = 'P';
      tab[xy.x + 2][xy.y] = 'X';
      xy = get_pos(tab);
    }
  return (xy);
}

