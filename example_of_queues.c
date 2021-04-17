/*
 * example_of_queues.c
 *
 *  Created on: Apr 15, 2021
 *      Author: odemki
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 10

char buf[MAX + 1];
int spos_1 = 0;     	// Set pos
int rpos_1 = 0;		// Read pos

void qstore_t(char q);
char qretrieve(void);

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

// -------------------------------------------------------------------------
example_of_queues()
{
	register char ch;
	int t;

	buf[80] = '\0';

	for(ch = ' ', t = 0; t < 32000 && ch != '\r'; ++t)
	{
		if(kbhit())			//if(_kbhit())		// If pressed any button
		{
			ch = getchar();
	//		qstore_(ch);              <<<<<<<<<<<<<<,
		}
		printf("%d", t);
		if(ch == '\r')
		{
			printf('\n');
			while((ch = qretrieve()) != '\0')
			{
				printf("%c", ch);
			}
			printf("\n");
		}
	}
	return 0;
}
// -------------------------------------------------------------------------
void qstore_t(char q)
{
	if(spos_1 + 1 == rpos_1 || (spos_1 +1 == MAX && !rpos_1))
	{
		printf("List is full\n");
		return;
	}
	buf[spos_1] = q;
	spos_1++;
	if(spos_1 == MAX)
	{
		spos_1 = 0;   // set on the start
	}
}
// -------------------------------------------------------------------------
char qretrieve(void)
{
	if(rpos_1 == MAX)
	{
		rpos_1 = 0;
	}
	if(rpos_1 == spos_1)
	{
		return '\0';
	}
	rpos_1++;
	return buf[rpos_1 - 1];
}
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------

