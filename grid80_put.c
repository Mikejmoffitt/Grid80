#include "grid80_put.h"

void g80_draw_times()
{
	g80_draw_rect(0,0,8,2,' ');
	g80_draw_string(2,1,"TIME");
	for (int y = 0; y < 13; y ++)
	{
		int target = 3 + ((GRID80_CELL_H+1)*y);
		g80_draw_rect(0,target,8,GRID80_CELL_H,' ');
	}
}

void g80_draw_days()
{
	for (int x = 0; x < 5; x++)
	{
		int target = 9 + ((1+GRID80_CELL_W)*x);
		g80_draw_rect(target,0,GRID80_CELL_W+((x==4)?(0):(1)),GRID80_CELL_H,' ');
		switch (x)
		{
		case 0:
			g80_draw_string(target,1,"    MONDAY   ");
			break;
		case 1:
			g80_draw_string(target,1,"   TUESDAY   ");
			break;
		case 2:
			g80_draw_string(target,1,"  WEDNESDAY  ");
			break;
		case 3:
			g80_draw_string(target,1,"   THURSDAY  ");
			break;
		case 4:
			g80_draw_string(target,1,"    FRIDAY   ");
			break;
		}
	}
}

void g80_draw_event(char* name, char* place, char* days, int start, int end)
{
	
}
