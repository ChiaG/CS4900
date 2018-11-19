#include <stdio.h>			
#include <gmp.h>

int main(int argc, char *argv[]){
	mpf_set_default_prec(5);

	double i_a, i_b, i_c; // Will be parsed from input
	mpf_t a, b, c; // Will be worked with throughout

	// mpf_set_d(num, -4);

	if(argc<4){
	    printf("Please enter 3 floating-point numbers with a newline after each:\n");
        scanf("%lf",&i_a);
        scanf("%lf",&i_b);
        scanf("%lf",&i_c);
	} 

	else{
	    sscanf(argv[1], "%lf", &i_a);
	    sscanf(argv[2], "%lf", &i_b);
	    sscanf(argv[3], "%lf", &i_c);
	}

	mpf_init(a);
	mpf_init(b);
	mpf_init(c);

	mpf_set_d(a,i_a); 
	// gmp_printf("a: %Ff\n", a); 
	mpf_set_d(b,i_b);
	// gmp_printf("b: %Ff\n", b); 
	mpf_set_d(c,i_c);
	// gmp_printf("c: %Ff\n", c); 

	gmp_printf("a: %Ff\nb: %Ff\nc: %Ff",a,b,c);

	mpf_clear(a);
	mpf_clear(b);
	mpf_clear(c);
}
