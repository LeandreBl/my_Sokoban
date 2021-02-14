/*
** main.c for my_sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Mon Dec  5 11:06:54 2016 Leandre Blanchard
** Last update Tue Dec 20 18:40:56 2016 Léandre Blanchard
*/

#include "include/sokoban.h"

sfMusic *theme;
sfMusic *load;

char *file_test(char *input)
{
    char *buffer;
    struct stat file;

    if ((stat(input, &file)) == (-1))
        return (NULL);
    if ((buffer = malloc(sizeof(char) * file.st_size)) == NULL)
        return (NULL);
    if ((read(open(input, O_RDONLY), buffer, file.st_size)) == (-1))
        return (NULL);
    return (buffer);
}

void music()
{
    theme = sfMusic_createFromFile("theme.wav");
    sfMusic_setVolume(theme, 10);
    sfMusic_play(theme);
}

int main(void)
{
    char *buffer;
    char *input;
    int a;

    music();
    input = menu();
    if (input == NULL)
        return (0);
    if ((buffer = strdup(file_test(input))) == NULL)
        return (84);
    free(input);
    if ((a = p_x_o_check(str_to_tab(buffer), buffer)) != 0)
    {
        endwin();
        if (a == 1)
            printf("%sIncorrect number of [X] and [O]%s\n", BOLDRED, RESET);
        else if (a == 2)
            printf("%sIncorrect number of [P]%s\n", BOLDRED, RESET);
        return (0);
    }
    terrain_display(str_to_tab(buffer), buffer, 2);
    free(buffer);
    sfMusic_destroy(load);
    sfMusic_destroy(theme);
    return (0);
}

char *menu()
{
    char **names;
    char *input;

    if ((names = display_files(opendir("."))) == NULL)
    {
        printf("\n%sNo .sk file found in current repository\n\n%s",
               BOLDRED,
               RESET);
        return (0);
    }
    initscr();
    clear();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    keypad(stdscr, TRUE);
    input = menu_loop(names);
    load = sfMusic_createFromFile("load.ogg");
    sfMusic_play(load);
    return (input);
}

int test_wf(char *name)
{
    if (my_strlen(name) < 4)
        return (1);
    if (name[my_strlen(name) - 1] == 'k')
        if (name[my_strlen(name) - 2] == 's')
            if (name[my_strlen(name) - 3] == '.')
                return (0);
    return (1);
}
