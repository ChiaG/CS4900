#include <stdio.h>
#include <stdlib.h>			
#include <gmp.h>

void findDiscriminant(mpf_t a, mpf_t b, mpf_t c, mpf_t discriminant);
int findNumRoots(mpf_t discriminant);
void findRoots(mpf_t a, mpf_t b, mpf_t c, mpf_t discriminant, int numRoots);

int main(int argc, char *argv[])
{
	mpf_set_default_prec(6);

	double *toLoad = malloc(sizeof(double) * 3);
	char *inBuffer = malloc(sizeof(char) * 256);
	
	printf("Note: Program will continue execution until three valid inputs are entered.\n");
	printf("Note: Program will disregard any numerical entries after the first for a given value.\n");

	do{
		printf("Please enter a number for value a: ");
		fgets(inBuffer, 256, stdin);
		// if (*toLoad == 0) { printf("a, b, and c can't be zero!\n"); }
	}
	while(sscanf(inBuffer, "%lf", toLoad) != 1 || *toLoad == 0);

	do{
		printf("Please enter a number for value b: ");
		fgets(inBuffer, 256, stdin);
	}
	while(sscanf(inBuffer, "%lf", toLoad + sizeof(double)) != 1 
		|| *(toLoad + sizeof(double)) == 0);
	
	do{
		printf("Please enter a number for value c: ");
		fgets(inBuffer, 256, stdin);
	}
	while(sscanf(inBuffer, "%lf", toLoad + 2 * sizeof(double)) != 1 
		|| *(toLoad + 2 * sizeof(double)) == 0);


	double i_a = *toLoad, i_b = *(toLoad + sizeof(double));
	double i_c = *(toLoad + 2 * sizeof(double)); // Will be parsed from input
	
	// a, b, and c values for quadratic formula
	mpf_t a;
	mpf_t b;
	mpf_t c; 

	mpf_init_set_d(a, i_a); 
	mpf_init_set_d(b, i_b);
	mpf_init_set_d(c, i_c);
	
	mpf_t discriminant;
	int numRoots;
	mpf_init(discriminant); // Initiating values to get discriminant

	findDiscriminant(a, b, c, discriminant);  //find discriminant
	numRoots = findNumRoots(discriminant);    //find number of roots

	findRoots(a, b, c, discriminant, numRoots);	//find roots
    
	/*mpf_t bsq; 
	mpf_t fac;
	mpf_t num;

	// gmp_printf("\na: %Ff\nb: %Ff\nc: %Ff\n", a, b, c);

	mpf_init(discriminant); // Initiating values to get discriminant
	mpf_init(bsq);
	mpf_init(fac);
	mpf_init_set_d(num, 4.0);

	mpf_mul(fac, a, c); //Starting to get 4*ac
	mpf_mul(fac, num, fac); // There it is

	mpf_mul(bsq, b, b); // b-squared

	mpf_sub(discriminant, bsq, fac); // Get discriminant

	gmp_printf("\nDiscriminant: %Ff\n", discriminant);

	mpf_clear(bsq); // Don't need these, now
	mpf_clear(fac);

	*/

	//----------------Finding the roots----------------

	/*mpf_t zeroCmp; //0.0 initialized for comparison
	mpf_init_set_d(zeroCmp, 0.0);

	mpf_t sqrt;     //square root of discriminant

	mpf_t rootOne;  //two roots at most
	mpf_t rootTwo;

	mpf_t numerator;      //either (-b + discriminant) or (-b - discriminant)
	mpf_t denom;	//2a basically
	mpf_t two;      //2, used for getting negative b

	mpf_t neg_b;    //negative b for operation
		
	mpf_init_set_d(two, 2.0); //set two to 2
	mpf_init(sqrt);
	mpf_init(rootOne);
	mpf_init(rootTwo);
	mpf_init(numerator);
	mpf_init(denom);
	mpf_init(neg_b);
	
	mpf_mul(denom, a, two);		//2*a

	mpf_neg(neg_b, b);

	if(0 > mpf_cmp(discriminant, zeroCmp)) { //comparewith 0 to see if negative
		printf("%s\n","There are no real solutions");
	}

	else if(mpf_cmp(discriminant, zeroCmp) == 0) {		//-b/2a if discriminant is 0
		mpf_div(rootOne, neg_b, denom);
		gmp_printf("\nAll Roots: %Ff\n", rootOne);		//rootOne = rootTwo etc
		printf("Accurate to at least 6 decimal places.\n");
	}

	else{

		mpf_sqrt(sqrt, discriminant); //get square root of b^2-4ac

		// gmp_printf("Square Root of Discriminant: %Ff\n", sqrt);
		// gmp_printf("Negative B: %Ff\n", neg_b);
	
		//I used this only because of the link dustin sent for largest root, otherwise, 
		//I would have done the top and compared to print instead.
		

		if(0 > mpf_cmp(b, zeroCmp)) {  //if b is negative then do -b+sqrt/2a
			mpf_add(numerator, neg_b,sqrt);
			mpf_div(rootOne, numerator, denom);

			if(mpf_cmp(rootOne, c) > 0) {				//if root one is greater than c then c/rootOne is rootTwo
				mpf_div(rootTwo, c, rootOne);
			}
			else{
				mpf_sub(numerator, neg_b,sqrt);
				mpf_div(rootTwo, numerator, denom);
			}

		}
		else{
			mpf_sub(numerator, neg_b,sqrt);
			mpf_div(rootOne, numerator, denom);

			if(mpf_cmp(rootOne, c) > 0) {				//if root one is greater than c then c/rootOne is rootTwo
				mpf_div(rootTwo, c, rootOne);
			}
			else{
				mpf_add(numerator, neg_b,sqrt);
				mpf_div(rootTwo, numerator, denom);
			}
		}

		gmp_printf("\nFirst Root: %Ff\n", rootOne);
		gmp_printf("Second Root: %Ff\n", rootTwo);
		printf("Accurate to at least 6 decimal places.\n");
	}


	mpf_clear(a);
	mpf_clear(b);
	mpf_clear(c);
	mpf_clear(zeroCmp);
	mpf_clear(sqrt);
	mpf_clear(rootOne);
	mpf_clear(rootTwo);
	mpf_clear(numerator);
	mpf_clear(denom);
	mpf_clear(two);
	mpf_clear(neg_b);*/
}