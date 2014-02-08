/*

Grid80
Michael Moffitt 2014
mikejmoffitt.com


Grid80 is a simple program that renders a 5-day schedule to an 80-column text
file. This is to facilitate printing of such a schedule on an old Dot Matrix
Printer. It could also be used to render a schedule into a standard terminal
session as well, I suppose. 

For each event, put a block like so:
  
EV [13-char name]
IN [13-char second line]
ON [MTWHF]
TS [24-hour time]
TE [24-hour time]
OK


Add as many of these as you want. It will not check for schedule conflicts, and
overlapping events will be rendered over each other. That's up to you.

*/

#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include "grid80_print.h"
#include "grid80_map.h"
#include "grid80_put.h"

int g80_time_lookup(char* timestring);
int main(int argc, char **argv);

#endif
