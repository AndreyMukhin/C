#include "header.h"

#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

void push(double);
double pop(void);
int getop(char[]);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
int buf[BUFSIZE];
int bufp = 0;

main()
{
	int type;
	char s[MAXVAL];

	while (type = getop(s))
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack is full, cannot push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack is empty\n");
		return 0.0;
	}
}

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ');

	s[1] = '\0';

	i = 0;
	while (isdigit(s[++i] = c = getch()));

	s[i] = '\0';
	ungetch(c);

	return NUMBER;
}

int isdigit(char c)
{
	return c >= '0' && c <= '9';
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	buf[bufp++] = c;
}

