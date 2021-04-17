/*
 * queues.c
 *
 *  Created on: Apr 15, 2021
 *      Author: odemki
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 4

char *p[MAX];
char *qretrive(void);
int spos = 0;     	// Set pos
int rpos = 0;		// Read pos

void enter(void);
int qstore(char *q);
void review(void);
void delete_ap(void);

// -------------------------------------------------------------------------
int queues(void)
{
	char s[80];						// String for command
	register int t;

	for(t = 0; t < MAX; ++t)		// Init array like NULL pointers
	{
		p[t] = NULL;
	}

	for(;;)
	{
		printf("Enter (E), List (L), Remove (R), Out (Q)");
		gets(s);
		*s = toupper(*s);

		switch (*s){
			case 'E':
				enter();
				break;
			case 'L':
				review();
				break;
			case 'R':
				delete_ap();
				break;
			case 'Q':
				exit(0);
		}
	}
	return 0;
}
// -------------------------------------------------------------------------
void enter(void)		// Enter items
{
	char s[256];		// Buffer for one item
	char *p;			// Pointer
	do{
		printf("Enter mitting %d: ", spos+1);
		gets(s);
		if(*s == '0')    // EXIT   // Was if(*s == 0)
 		{
			break;
		}
		p = (char *) malloc(strlen(s)+1);		// malloc memory for 's'
		if(!p)
		{
			printf("Didn't malloc memory \n");
			return;
		}
		strcpy(p, s);		// Copy
		if(*s)				// What it mean???? <<<<<<<<<<<<<<<<<<<<<<<
		{
			int status = qstore(p);
			if(status == 1)
			{
				break;
			}
		}
	}while (*s);
}
// -------------------------------------------------------------------------
void review(void)
{
	register int t;
	for(t = rpos; t < spos; ++t)
	{
		printf("%d. %s\n", t+1, p[t]);	 	// вивести дані за показником
	}
}
// -------------------------------------------------------------------------
void delete_ap(void)
{
	char *p;
	if((p = qretrive()) == NULL)
	{
		return;
	}
	printf("%s\n", p);
}
// -------------------------------------------------------------------------
int qstore(char *q)
{
	if(spos+1 == rpos || (spos+1 == MAX && !rpos))
	{
		printf("List is full\n");
		return 1;
	}
	p[spos] = q;					/* Записується в масив показників показник на масив
	з даним запиcом
	*/
	spos++;						// Інкремент показника
	if(spos == MAX)				// Провірка на переповнення
	{
		spos = 0;		// Set on the start
	}
	return 0;
}
// -------------------------------------------------------------------------
char *qretrive(void)
{
	if(rpos == MAX)
	{
		spos = 0;
	}
	if(rpos == spos)
	{
		printf("The list is empty\n");
		return NULL;
	}
	rpos++;
	return p[rpos-1];
}
// -------------------------------------------------------------------------




// -------------------------------------------------------------------------

// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
