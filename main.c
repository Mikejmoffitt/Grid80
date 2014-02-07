/*

Grid80
Michael Moffitt 2014
mikejmoffitt.com


Grid80 is a simple program that renders a 5-day schedule to an 80-column text
file. This is to facilitate printing of such a schedule on an old Dot Matrix
Printer. It could also be used to render a schedule into a standard terminal
session as well, I suppose. 

Format for the schedule file to feed it is as follows:

For a line to be printed on the top, put:

HT [Header text, maximum 80 characters]

  For each event, put a block like so:
  
EV [13-char name]
IN [13-char second line]
ON [MTWHF]
TS [24-hour time]
TE [24-hour time]
OK

For a line at the bottom, put:

FT [Footer text, maximum 80 characters]

Add as many of these as you want. It will not check for schedule conflicts, and
overlapping events will be rendered over each other. That's up to you.

*/

#include "main.h"

int g80_time_lookup(char* timestring)
{	
	int retval = 3;
	char hr[2];
	for (unsigned int i = 0; i < (unsigned)strlen(timestring); i++)
	{
		if (timestring[i] == ':')
		{
			retval += ((timestring[i+1]=='3')?1:0);
			break;
		}
		hr[i] = timestring[i];
	}
	return retval + (((atoi(hr)-8) * 3));;
}

int main(int argc, char **argv)
{
	g80_init_map();
	
	// Put the border there
	g80_draw_rect(0,0,GRID80_MAP_W-2,GRID80_MAP_H-2,'.');
	
	// Print a test event
	g80_draw_event("Doing squats!","Everywhere!","MWF",g80_time_lookup("8:00"),g80_time_lookup("10:00"));
	g80_draw_event("Programming C"," In a hole ","MW",g80_time_lookup("11:00"),g80_time_lookup("12:30"));
	g80_draw_event("Meeting girls"," Elsewhere ","TH",g80_time_lookup("10:30"),g80_time_lookup("14:00"));
	
	// Get boilerplate stuff in there
	g80_draw_times();
	g80_draw_days();
	g80_print_map();
	g80_free_map();
	return 0;
}
