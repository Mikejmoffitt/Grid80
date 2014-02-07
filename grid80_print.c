#include "grid80_print.h"

void g80_print_top()
{
	for (unsigned char i = 0; i < 80; i++)
	{
		printf("#");
	}
	printf("\n");
}

void g80_print_map()
{
	for (int y = 0; y < GRID80_MAP_H; y++)
	{
		for (int x = 0; x < GRID80_MAP_W; x++)
		{
			printf("%c",g80_map[y][x]);
		}
		printf("\n");
	}
}
