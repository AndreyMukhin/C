#include "header.h"

#define MAXVAL 100
#define NUMBER '0'

void push(double);
double pop(void);
int getop(char[]);

int sp = 0;
double val[MAXVAL];
int last_read_char;

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
	int i = 0;

	while ((s[i] = get_next_char()) == ' ');

	if (!isdigit(s[i]))
	{
		return s[i];
	}

	while (isdigit(s[++i] = get_next_char()));

	last_read_char = s[i];
	s[i] = '\0';

	return NUMBER;
}

int isdigit(char c)
{
	return c >= '0' && c <= '9';
}

int get_next_char()
{
	if (last_read_char)
	{
		int ret = last_read_char;
		last_read_char = 0;
		return ret;
	}
	else
	{
		return getchar();
	}
}
