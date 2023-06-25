#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define _GNU_SOURCE


#include <gmp.h>

void factorize(char *s) {
    mpz_t n, i;
    mpz_init(n);
    mpz_init_set_ui(i,2);

    mpz_set_str(n, s, 10);

    while (mpz_cmp(i, n) < 0) {
        if (mpz_divisible_p(n, i)) {
            mpz_t div;
            mpz_init(div);
            mpz_div(div, n, i);
            gmp_printf("%Zd=%Zd*%Zd\n", n, div, i);
            mpz_clear(div);
            break;
        }
        mpz_add_ui(i, i, 1);
    }

    mpz_clear(n);
    mpz_clear(i);
}


int main(int argc, char **argv) {
	FILE *file;
	size_t read;
	
	size_t count;
    size_t line;
	char *text;

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

	while((line = getline(&text, &count, file)) != -1)
	{
		factorize(text);
	}

	return 0;
}
