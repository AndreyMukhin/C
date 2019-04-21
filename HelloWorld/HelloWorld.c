#include "header.h"

#define MAXVAL 100
#define NUMBER '0'

void push(double);
double pop(void);
int getop(char[]);

int sp = 0;
double val[MAXVAL];
static int last_read_char;
long long fib(int);
void swap(int *x, int *y);

typedef struct tree tree;

struct tree
{
	tree *left;
	tree *right;
};

void strcpy1(char *_dest, char *_source);

main()
{
	/*
	int i = NULL;
	tree left_left = { 0, 0 };
	tree left_right = { 0, 0 };
	tree left = { &left_left, &left_right };

	tree right_right = { 0, 0 };
	tree right = {0, &right_right };

	tree root = {&left, &right };

	printf("%d\n", getnodesnumber(&root));

	char *source = "test";
	char *dest = NULL;

	strcpy1(&dest, &source);

	printf(dest);
	
	getchar();
	*/

	for (int i = 1; i <= 100; i++)
	{
		if (i == 1 || i == 2)
		{
			printf("%d#", i);
		}
		else if (i % 2 != 0)
		{
			int k = 1;
			for (int j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					k = 0;
					break;
				}
			}

			if (k == 1)
			{
				printf("%d#", i);
			}
		}
	}

	getchar();
}

void test()
{
	return 1;
}

void strcpy1(char *_dest, char *_source)
{
	while (*_dest++ = *_source++);
}

int getnodesnumber(tree *_tree)
{
	int nodesnumber = 0;

	if (_tree != NULL)
	{
		if (_tree->left != NULL)
		{
			nodesnumber += getnodesnumber(_tree->left);
		}

		if (_tree->right != NULL)
		{
			nodesnumber += getnodesnumber(_tree->right);
		}

		nodesnumber++;
	}

	return nodesnumber;
}

ptrdiff_t strlen(char *s)
{
	char *start_element = s;
	
	while (*start_element != '\0')
	{
		start_element++;
	}
	
	return start_element - s;
}

void swap(int *x, int *y)
{
	int *temp = y;
	y = x;
	x = temp;
}

long long fib(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}

	long long fib1 = 0;
	long long fib2 = 1;
	long long x;

	for (int i = 2; i <= n; i++)
	{
		x = fib1;
		fib1 = fib1 + fib2;
		fib2 = x;
	}

	long long res = fib1 + fib2;
	return res;
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
