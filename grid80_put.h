#ifndef GRID80_PUT_H
#define GRID80_PUT_H

#include <stdlib.h>
#include "main.h"
#include "grid80_print.h"
#include "grid80_map.h"

// Puts the times on the left side
void g80_draw_times();

// Puts the days on the top
void g80_draw_days();

// Render an event.
void g80_draw_event(char* name,char* place,char* days,int start,int end);

#endif
