#ifndef GRID80_MAP
#define GRID80_MAP

#define GRID80_CELL_W 13 // Characters per line of a cell
#define GRID80_CELL_H 2 // Lines in a cell
#define GRID80_MAP_W 80 // Char map width (width of screen)
#define GRID80_MAP_H 43 // Char map height

// Global map state:
char** g80_map;

// Puts a rectangle at given coords (char coords)
void g80_draw_rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, char fill);

// Puts a string at given coords (char coords)
void g80_draw_string(unsigned int x, unsigned int y, char* string);

// Initialize the map array
void g80_init_map();
void g80_free_map();

#endif
