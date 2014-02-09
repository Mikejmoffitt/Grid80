#ifndef GRID80_MAP
#define GRID80_MAP

#define GRID80_CELL_W 13 // Characters per line of a cell
#define GRID80_CELL_H 2 // Lines in a cell
#define GRID80_MAP_W 80 // Char map width (width of screen)
#define GRID80_MAP_H 43 // Char map height

char** g80_map;

// Puts a rectangle at given coords (char coords)
void g80_draw_rect(int x, int y, int w, int h, char fill);

// Puts a string at given coords (char coords)
void g80_draw_string(int x, int y, char* string);

// Puts the times on the left side
void g80_draw_times();

// Initialize the map array
void g80_init_map();
void g80_free_map();

#endif
