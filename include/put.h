#ifndef GRID80_PUT_H
#define GRID80_PUT_H

// Puts the times on the left side
void g80_draw_times();

// Puts the days on the top
void g80_draw_days();

// Render an event.
void g80_draw_event(char* name,char* place,char* days,int start,int end);

#endif
