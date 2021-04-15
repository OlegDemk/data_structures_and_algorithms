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

#define MAX 100

char *p[MAX];
char *qretrive(void);
int spos = 0;
int rpos = 0;

void enter(void);
void qstore(char *q);
void review(void);
void delete_ap(void);

int queues(void)
{
	char s[80];
	register int t;

	for(t = 0; t < MAX; ++t)	// Init array like NULL pointers
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
	char s[256], *p;
	do{
		printf("Enter mitting %d: ", spos+1);
		gets(s);
		if(*s == '0')    // Was if(*s == 0)
 		{
			break;
		}
		p = (char *) malloc(strlen(s)+1);
		if(!p)
		{
			printf("Didn't malloc memory \n");
			return;
		}
		strcpy(p, s);
		if(*s)
		{
			qstore(p);
		}
	}while (*s);
}
// -------------------------------------------------------------------------
void review(void)
{
	register int t;
	for(t = rpos; t < spos; ++t)
	{
		printf("%d. %s\n", t+1, p[t]);
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
void qstore(char *q)
{
	if(spos == MAX)
	{
		printf("List full\n");
		return;
	}
	p[spos] = q;
	spos ++;
}
// -------------------------------------------------------------------------
char *qretrive(void)
{
	if(rpos == spos)
	{
		printf("No any mitting\n");
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
