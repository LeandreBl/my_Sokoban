/*
** sokoban.h for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Dec 13 16:59:35 2016 Leandre Blanchard
** Last update Tue Dec 13 17:00:58 2016 Leandre Blanchard
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <curses.h>
#include <termios.h>

#include "colors.h"
#include "my.h"

#define ARGS_ERROR      84
#define BUFFER_ERROR    84
#define READ_EMPTY      84
#define MALLOC_ERROR    84
#define BUG             84
#define QUIT            0

typedef struct  s_xy
{
  int   x;
  int   y;
}               t_xy;

void    tight(char *, char **);

int     check_pose(char **, char *);

int     check_lose(char **, char *);

void    lose_screen(char **, char *, int);

int     check_boxes(char **, int, int);

void    win_screen(char **, char *, int);

int     menu(char **, char *);

t_xy    xy_tuple(int, int);

int     check_spot(char **, t_xy *);

t_xy    *add_coord(t_xy *, char **);

t_xy    loop_screen(char **, char *, t_xy, int);

char    **restart_path(char *);

int     main(int, char **);

t_xy    move_right(char **, t_xy);

t_xy    move_left(char **, t_xy);

t_xy    move_up(char **, t_xy);

t_xy    move_down(char **, t_xy);

t_xy    check_pos_mvt(char **, t_xy, char *, int);

t_xy    get_pos(char **);

void    my_put_tab(char **);

int     terrain_display(char **, char *, int);

int     my_tablen(char **);

char    **str_to_tab(char *);

int     nb_of_line(char *);

int     line_len(char *);
