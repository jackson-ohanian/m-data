/*### Driver and TUI Design ###*/

#pragma once

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>


void user_wait();

void init_window();

void kill_curse();

void parse_cmd(char * input);

void curse_clear_line(int y);
