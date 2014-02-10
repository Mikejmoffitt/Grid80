#include <stdlib.h>
#include <string.h>

#include <map.h>

// Puts a rectangle at given coords (char coords)
void g80_draw_rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, char fill)
{
	w++;
	h++;
	// Clear out the area
	for(unsigned int ypos = y+1; ypos < y+h; ypos++)
	{
		for(unsigned int xpos = x+1; xpos < x+w; xpos++)
		{
			if(ypos < GRID80_MAP_H && xpos < GRID80_MAP_W)
			{
				g80_map[ypos][xpos] = fill;
			}
		}
	}
	// Vertical sides
	for(unsigned int ypos = y+1; ypos < y+h+1; ypos++)
	{
		if (ypos < GRID80_MAP_H)
		{
			g80_map[ypos][x] = '|';
			g80_map[ypos][x+w] = '|';
		}
	}
	// Horizontal sides
	for(unsigned int xpos = (x+1); xpos < x+w; xpos++)
	{
		if(xpos < GRID80_MAP_W)
		{
			g80_map[y][xpos] = '_';
			g80_map[y+h][xpos] = '_';
		}
	}
}

// Puts a string at given coords (char coords)
void g80_draw_string(unsigned int x, unsigned int y, char* string)
{
	x++;
	y++;
	size_t length = strlen(string);
	for(unsigned int i = 0; i < length && i < 13; i++)
	{
		if(y < GRID80_MAP_H && x < GRID80_MAP_W)
		{
			g80_map[y][x+i] = string[i];
		}
	}
}

// Initialize the map array
void g80_init_map()
{
	g80_map = (char**)malloc(GRID80_MAP_H * sizeof(char*));
	for(unsigned int y = 0; y < GRID80_MAP_H; y++)
	{
		g80_map[y] = (char*)malloc(GRID80_MAP_W * sizeof(char));
		for(int x = 0; x < GRID80_MAP_W; x++)
		{
			g80_map[y][x] = ' ';
		}
	}
}

void g80_free_map()
{
	for(unsigned int y = 0; y < GRID80_MAP_H; y++)
	{
		free(g80_map[y]);
	}
	free(g80_map);
}
