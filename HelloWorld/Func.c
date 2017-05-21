#include "func.h"

int strindex(char sourcestr[], char searchstr[])
{
	for (int sourceIdx = 0; sourcestr[sourceIdx] != '\0'; sourceIdx++)
	{
		int searchIdx;
		for (searchIdx = 0; searchstr[searchIdx] != '\0' && sourcestr[searchIdx + sourceIdx] == searchstr[searchIdx]; searchIdx++);

		if (searchIdx > 0 && searchstr[searchIdx] == '\0')
		{
			return sourceIdx;
		}
	}

	return -1;
}