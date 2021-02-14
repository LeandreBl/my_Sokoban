/*
** main.c for My_popup in /home/lblanchard/System_unix/PSU_2016_my_popup
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Dec  5 11:06:54 2016 Leandre Blanchard
** Last update Tue Dec 13 17:16:39 2016 Leandre Blanchard
*/

#include "include/sokoban.h"

void tight(char *path, char **tab)
{
  while (LINES < my_tablen(tab) || COLS < line_len(path))
  {
    clear();
    mvprintw(LINES / 2, COLS / 2 - 11, "terminal to tight [!]");
    refresh();
  }
}

int main(int ac, char **av)
{
  char *buffer;
  int size;

  if (ac != 2)
    exit(ARGS_ERROR);
  if (av[1][0] == '-' && av[1][1] == 'h')
  {
    printf("%s%s%s%s", "USAGE\n\t./my_sokoban map\nDescription\n\t",
           "map     file representing the warehouse map, containing ’#’",
           "for walls,\n\t\t’P’ for the player, ’X’",
           "for boxes and ’O’ for storage locations.\n");
    return (0);
  }
  buffer = malloc(5000);
  size = read(open(av[1], O_RDONLY), buffer, 5000);
  if (size == 0)
    return (READ_EMPTY);
  buffer[size] = 0;
  terrain_display(str_to_tab(buffer), buffer, 0);
  free(buffer);
  return (0);
}
