#include "grid80_put.h"

void g80_draw_times()
{
	g80_draw_rect(0,0,8,2,' ');
	g80_draw_string(2,1,"TIME");
	for (int y = 0; y < 13; y ++)
	{
		int target = 3 + ((GRID80_CELL_H+1)*y);
		g80_draw_rect(0,target,8,GRID80_CELL_H,' ');
		switch (y)
		{
			case 0:
				g80_draw_string(0,target+1," 8:00AM");
				break;
			case 1:
				g80_draw_string(0,target+1," 9:00AM");
				break;
			case 2:
				g80_draw_string(0,target+1,"10:00AM");
				break;
			case 3:
				g80_draw_string(0,target+1,"11:00AM");
				break;
			case 4:
				g80_draw_string(0,target+1,"12:00PM");
				break;
			case 5:
				g80_draw_string(0,target+1," 1:00PM");
				break;
			case 6:
				g80_draw_string(0,target+1," 2:00PM");
				break;
			case 7:
				g80_draw_string(0,target+1," 3:00PM");
				break;
			case 8:
				g80_draw_string(0,target+1," 4:00PM");
				break;
			case 9:
				g80_draw_string(0,target+1," 5:00PM");
				break;
			case 10:
				g80_draw_string(0,target+1," 6:00PM");
				break;
			case 11:
				g80_draw_string(0,target+1," 7:00PM");
				break;
			case 12:
				g80_draw_string(0,target+1," 8:00PM");
				break;
		}
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
	if (start < end)
	{
		for (unsigned int i = 0; i < (unsigned)strlen(days); i++)
		{
			int target = 9;
			switch (days[i])
			{
				case 'M':
					target = 9;
					break;
				case 'T':
					target = 9+GRID80_CELL_W+1;
					break;
				case 'W':
					target = 9+(2*(1+GRID80_CELL_W));
					break;
				case 'H':
					target = 9+(3*(1+GRID80_CELL_W));
					break;
				case 'F':
					target = 9+(4*(1+GRID80_CELL_W));
					break;
			}
			int height = end-start-1;
			g80_draw_rect(target,start,GRID80_CELL_W,height,' ');
			g80_draw_string(target,start,name);
			if (height > 1)
			{
				g80_draw_string(target,start+1,place);
			}
		}
	}
}
