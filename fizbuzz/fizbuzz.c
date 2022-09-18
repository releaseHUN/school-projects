#include <stdio.h>
#include <string.h>

int main()
{
	char fizz[8] = "Fizz";
	char buzz[8] = "Buzz";
	char free[8];

	for (int i = 1; i < 100; i += 1)
	{
		char output[8];

		if (i % 3 == 0)
		{
			strcat(output, fizz);
		}

		if (i % 5 == 0)
		{
			strcat(output, buzz);
		}

		if (strlen(output) > 0)
		{
			printf("%s \n", output);
		}
		else
		{
			printf("%d \n", i);
		}
		strcpy(output, free);
	}
	return 0;
}