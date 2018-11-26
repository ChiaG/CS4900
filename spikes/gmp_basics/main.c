#include "../../src/main/all.h"

int main()
{
	mpf_t a;
	mpf_t b;
	mpf_t c; 

	mpf_init_set_d(a, 3.0); 
	mpf_init_set_d(b, 2.0);
	mpf_init(c);

	mpf_sub(c, a, b);

	gmp_printf("3.0 - 2.0 = %Ff\n", c);
}