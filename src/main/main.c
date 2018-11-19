#include <stdio.h>
#include <stdlib.h>			
#include <gmp.h>

int main(int argc, char *argv[]){
	mpf_set_default_prec(5);

	double * toLoad = malloc(sizeof(double) * 3);
	char * inBuffer = malloc(sizeof(char) * 256);
	
	printf("Note: Program will continue execution until three valid inputs are entered.\n");
	printf("Note: Program will disregard any numerical entries after the first for a given value.\n");

	do{
		printf("Please enter a number for value a: ");
		fgets(inBuffer, 256, stdin);
	}
	while(sscanf(inBuffer, "%lf", toLoad) != 1);

	do{
		printf("Please enter a number for value b: ");
		fgets(inBuffer, 256, stdin);
	}
	while(sscanf(inBuffer, "%lf", toLoad + sizeof(double)) != 1);
	
	do{
		printf("Please enter a number for value c: ");
		fgets(inBuffer, 256, stdin);
	}
	while(sscanf(inBuffer, "%lf", toLoad + 2 * sizeof(double)) != 1);


	double i_a = *toLoad, i_b = *(toLoad + sizeof(double)), i_c = *(toLoad + 2 * sizeof(double)); // Will be parsed from input
	mpf_t a, b, c; // Will be worked with throughout
	mpf_t discriminant, bsq, fac, num; //The variables that will store the discriminant,
	//b squared, and 4*ac, respectively, and the variable that will let us multiply a*c 
	// by four to get 4*ac

	mpf_init_set_d(a,i_a); 
	mpf_init_set_d(b,i_b);
	mpf_init_set_d(c,i_c);

	gmp_printf("a: %Ff\nb: %Ff\nc: %Ff\n",a,b,c);

	mpf_init(discriminant); // Initiating values to get discriminant
	mpf_init(bsq);
	mpf_init(fac);
	mpf_init_set_d(num, 4.0);

	mpf_mul(fac,a,c); //Starting to get 4*ac
	mpf_mul(fac,num,fac); // There it is

	mpf_mul(bsq,b,b); // b-squared

	mpf_sub(discriminant,bsq,fac); // Get discriminant

	gmp_printf("Discriminant: %Ff\n",discriminant);

	mpf_clear(bsq); // Don't need these, now
	mpf_clear(fac);

	// To be resumed ***************************

	mpf_clear(a);
	mpf_clear(b);
	mpf_clear(c);
}
