#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <put.h>
#include <print.h>
#include <map.h>

int g80_time_lookup(char* timestring)
{	
	int retval = 3;
	char hr[] = "  ";
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

void g80_load_events(FILE* fptr)
{
	// Line buffer
	char line[83];
	char ev[14];
	char in[14];
	char on[] = "     ";
	char ts[] = "     ";
	char te[] = "     ";
	// Clear out vars
	while (fgets(line, sizeof(line), fptr))
	{
		if (strlen(line) > 1)
		{
			// Remove any unacceptable characters
			for (unsigned int i = 0; i < (unsigned)strlen(line); i++)
			{
				if (line[i] < ' ')
				{
					line[i] = '\0';
				}
			}
			if ((line[0]|0x20) == 'e' && (line[1]|0x20) == 'v')
			{
				// Make event name
				strncpy(ev,line+3,13);
			}
			else if ((line[0]|0x20) == 'i' && (line[1]|0x20) == 'n')
			{
				// Make event name
				strncpy(in,line+3,13);
			}
			else if ((line[0]|0x20) == 'o' && (line[1]|0x20) == 'n')
			{
				// Make event name
				strncpy(on,line+3,5);
			}
			else if ((line[0]|0x20) == 't')
			{
				if ((line[1]|0x20) == 's')
				{
					// Make event name
					strncpy(ts,line+3,5);
				}
				else if ((line[1]|0x20) == 'e')
				{
					// Make event name
					strncpy(te,line+3,5);
				}
			}
			else if ((line[0]|0x20) == 'o' && (line[1]|0x20) == 'k')
			{
				g80_draw_event(ev,in,on,g80_time_lookup(ts),g80_time_lookup(te));
				
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
	{
		printf("Usage: %s infile [fillchar]\n",argv[0]);
		return 0;
	}
	g80_init_map();
	// Put the border there
	if (argc == 3)
	{
		g80_draw_rect(0,0,GRID80_MAP_W-2,GRID80_MAP_H-2,argv[2][0]);
	}
	else
	{
		g80_draw_rect(0,0,GRID80_MAP_W-2,GRID80_MAP_H-2,' ');
	}

	FILE* fptr;
	char *mode = "r";
	fptr = fopen(argv[1], mode);
	
	if (fptr == NULL)
	{
		fprintf(stderr, "Grid80: Couldn't open \"%s\".\n",argv[1]);
		g80_free_map();
		return 0;
	}
	g80_load_events(fptr);
	fclose(fptr);
	g80_draw_times();
	g80_draw_days();
	g80_print_map();
	g80_free_map();
	return 0;
}
