#include "m-data.h"

/* screen struct - defines aspects of the current screen */
typedef struct screen {
    int width;
    
    int height;
    
    int draw_row;
} screen;


screen * scr;

/* driver */
int main() {
    // init curses
    init_window();
    // type TODO
    user_wait();
    // closing
    // exit
    return 0;
}

/* Init a curse window for the player */
void init_window() {
    scr = malloc(sizeof(screen));
    
    initscr();
    cbreak();
    noecho();
    intrflush(stdscr, 0);
    keypad(stdscr, 1);
    atexit(kill_curse);
    
    getmaxyx(stdscr, scr->width, scr->height);
    char mesg[] = ">m-player - try 'help'";
    mvprintw(0, 0,"%s",mesg);
    refresh();
}

/* A function to read user input */
void user_wait() {
    // to save user input
    char input[128];
    int idx = 0;
    
    // character currently entered by user
    int ch = 0;
    // move cursor to bottom
    move(scr->width - 1, 0);
    while(1) {
        int ch;
        nodelay(stdscr, TRUE);
        for (;;) {
             if ((ch = getch()) == ERR) {
                 continue;
             }
             else {
                 // on enter
                 if (ch == '\n') {
                     // terminate string before newline
                     input[idx] = 0;
                     // clear input bar
                     curse_clear_line(scr->width - 1);
                     // parse command
                     parse_cmd(input);
                 }
                 
                 // failsafe constant reposition of cursor
                 int x = 0;
                 int y = 0;
                 getyx(stdscr, x, y);
                 move(scr->width - 1, y);
                 addch(ch);
                 
                 // add to str
                 input[idx] = ch;
                 idx++;
                 // TODO max input
             }
        }
    }
}

/* Curse exit conditions - close handler */
void kill_curse() {
    endwin();
}

/* wipe a line */
void curse_clear_line(int y) {
    move(scr->width - 1, -16);
    for (int i = 0; i < 132; i++) {
        delch();
        move(scr->width - 1, 0 + i);
    }
}
void parse_cmd(char * input) {
    mvprintw(3 + scr->draw_row, 0, "%s", input);
    scr->draw_row++;
    
    refresh();
    user_wait();
}
