#include "All.h"

int main(int argc, char *argv[])
{
	mpf_set_default_prec(6);

	//Input variable declaration and input function execution.
	double toLoadA = 0, toLoadB = 0, toLoadC = 0;
	runtimeLoad(&toLoadA, &toLoadB, &toLoadC);

	// a, b, and c values for quadratic formula
	mpf_t a;
	mpf_t b;
	mpf_t c; 

	mpf_init_set_d(a, toLoadA); 
	mpf_init_set_d(b, toLoadB);
	mpf_init_set_d(c, toLoadC);
	
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
