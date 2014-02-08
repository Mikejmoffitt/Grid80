Grid80
Michael Moffitt 2014
======

Grid80 is licensed under the MIT license blah blah blah

Grid80 renders a 5-day schedule in an 80-column text view. This is to faciliate
the printing of such a schedule on an old dot-matrix printer. 

Usage:

grid80 schedule_file [fillchar]

Fillchar is optional and specifies which character is used to fill empty space
in the grid. If no character is specified, a space is used (empty).

The format for the schedule file is as follows. For each event, put a block 
like the one here (filling in your own values, of course):
 
EV [13-char name]
IN [13-char second line]
ON [MTWHF]
TS [24-hour time]
TE [24-hour time]
OK

Add as many of these as you want. It will not check for schedule conflicts, and
overlapping events will be rendered over each other. That's up to you.

An example schedule (my real schedule at the time of writing) is visible in
the project directory, named moffitt-schedule. An example output is there as
well. The program does not currently write any files on its own and relies on
the operating system for output redirection. Do this save to a text file:

grid80 file > output.txt
