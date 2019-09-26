#include <ncurses.h>

int main(int argc, char *argv[])
{
    int ch,c;
    initscr();
    cbreak();
    noecho();

    while( ch != 'q')
    {
        printw("%i\n", getch());
    }
    endwin();
    return(0);
}
