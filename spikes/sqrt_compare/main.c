#include "../../src/main/all.h"

int main()
{
	mpf_t sqrt2;
	mpf_t basically2;

	mpf_init(sqrt2);
	mpf_init_set_d(basically2, 2.0);

	mpf_sqrt(sqrt2, basically2);

	gmp_printf("Square Root of 2:\n1.41421356237\n\n");
	gmp_printf("GMP's solution:\n%Ff\n", sqrt2);
}