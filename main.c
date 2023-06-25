#include <stdio.h>
#include <stdlib.h>


void factorize(char *s)
{
	unsigned long int n;
	unsigned long int i = 2;

	n = atoi(s);
	while (i < n)
	{
		if(n % i == 0)
		{
			printf("%lu=%lu*%lu\n",n,n/i,i);
			return;
		}
		i++;
	}

}

int main(int argc, char **argv) {
	FILE *file;
	ssize_t read;
	size_t len = 0;
	char *line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: factors file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&(line), &len, file)) != -1)
	{
		factorize(line);
	}

	return 0;
}
