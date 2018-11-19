#include <stdio.h>
#include <stdlib.h>			
#include <gmp.h>

int main(int argc, char *argv[]){

	double * toLoad = malloc(sizeof(double) * 3);
	int debugIndicator;
	char * inBuffer = malloc(sizeof(char) * 256);
	
	printf("Note: Program will continue execution until three valid inputs are entered.\n");
	printf("Note: Program will disregard any numerical entries after the first for a given value.\n");

	do{
		printf("Please enter a number for value a: ");
		fgets(inBuffer, 256, stdin);
		debugIndicator = sscanf(inBuffer, "%lf", toLoad);
	}
	while(debugIndicator != 1);

	debugIndicator = 0;
	
	do{
		printf("Please enter a number for value b: ");
		fgets(inBuffer, 256, stdin);
		debugIndicator = sscanf(inBuffer, "%lf", toLoad + sizeof(double));
	}
	while(debugIndicator != 1);

	debugIndicator = 0;
	
	do{
		printf("Please enter a number for value c: ");
		fgets(inBuffer, 256, stdin);
		debugIndicator = sscanf(inBuffer, "%lf", toLoad + 2 * sizeof(double));
	}
	while(debugIndicator != 1);

	mpf_set_default_prec(5);

	double i_a = *toLoad, i_b = *(toLoad + sizeof(double)), i_c = *(toLoad + 2 * sizeof(double)); // Will be parsed from input
	mpf_t a, b, c; // Will be worked with throughout

	// mpf_set_d(num, -4);

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
