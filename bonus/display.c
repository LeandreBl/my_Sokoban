/*
** display.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Dec  5 12:56:15 2016 Leandre Blanchard
** Last update Tue Dec 13 19:43:08 2016 Leandre Blanchard
*/

#include "include/sokoban.h"

int		terrain_display(char **tab, char *path, int color)
{
  WINDOW	*box;
  t_xy		xy;
  t_xy		*posdot;
  int		moves;

  posdot = add_coord(posdot, tab);
  xy = get_pos(tab);
  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  moves = 0;
  while (1)
    {
      moves = moves + 1;
      tight(path, tab);
      curs_set(0);
      xy = loop_screen(tab, path, xy, posdot);
      if (check_spot(tab, posdot) == 0)
	win_screen(tab, path, color, scores(tab, posdot) - moves);
      if (check_lose(tab, path) == 1)
	lose_screen(tab, path, color);
    }
  endwin();
  return (0);
}

void		lose_screen(char **tab, char *path, int color)
{
  int		key;
  t_xy		*posdot;

  posdot = add_coord(posdot, tab);
  key = 0;
  clear();
  mvprintw(LINES / 2 - 1, COLS / 2 - 5, "You lose !\n");
  mvprintw(LINES / 2, COLS / 2 - 5, "Restart ? Y/n\n");
  scores(tab, posdot);
  key = getch();
  while (key != 'n' && key != 'Y' && key != 'y')
    key = getch();
  if (key == 'n')
    {
      endwin();
      exit(QUIT);
    }
  if (key == 'Y' || key == 'y' || key == 32)
    terrain_display(str_to_tab(path), path, color);
}

t_xy		loop_screen(char **tab, char *path, t_xy xy, t_xy *posdot)
{
  int	i;
  int	j;

  i = 0;
  clear();
  init_pairs();
  while (tab[i] != NULL)
    {
      j = 0;
      while (j != line_len(path))
	{
	  put_tab_color(tab, i, j, posdot);
	  scores(tab, posdot);
	  j = j + 1;
	}
      curs_set(0);
      i = i + 1;
    }
  refresh();
  xy = check_pos_mvt(tab, xy, path, 2);
  return (xy);
}

void		win_screen(char **tab, char *path, int color, int score)
{
  int		key;

  key = 0;
  clear();
  refresh();
  mvprintw(LINES / 2 - 1, COLS / 2 - 5, "You win !");
  mvprintw(LINES / 2, COLS / 2 - 7, "Restart ? Y/n");
  mvprintw(LINES / 2 + 1, COLS / 2 - 9, "Your score is [%d]", score);
  while	(key != 'n' && key != 'Y' && key != 'y')
    key = getch();
  if (key == 'n')
    {
      endwin();
      exit(QUIT);
    }
  if (key == 'Y' || key == 'y')
    terrain_display(str_to_tab(path), path, color);
}
