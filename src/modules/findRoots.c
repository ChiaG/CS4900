#include "../main/all.h"

void findDiscriminant(mpf_t a, mpf_t b, mpf_t c, mpf_t discriminant)
{

    //The variables that will store the discriminant,
	//b squared, and 4*ac, respectively, and the variable that will let us multiply a*c 
	// by four to get 4*ac

	mpf_t bsq; 
	mpf_t fac;
	mpf_t num;

	// gmp_printf("\na: %Ff\nb: %Ff\nc: %Ff\n", a, b, c);

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
    mpf_clear(num);
 

}

int findNumRoots(mpf_t discriminant)
{
    mpf_t zeroCmp; //0.0 initialized for comparison
    mpf_init_set_d(zeroCmp, 0.0);

    if (0 > mpf_cmp(discriminant, zeroCmp)) { //compare with 0 to see if negative
		printf("%s\n","There are no real solutions");
        mpf_clear(zeroCmp);
        return 0;
	}

    else if (mpf_cmp(discriminant, zeroCmp) == 0) {		//-b/2a if discriminant is 0
        printf("%s\n","There is only one solution");
        mpf_clear(zeroCmp);
		return 1;   //only one solution
	}

    else{
        printf("%s\n","There are two solutions");
        mpf_clear(zeroCmp);
        return 2;   //two solutions
    }

}


void findRoots(mpf_t a, mpf_t b, mpf_t c, mpf_t discriminant, mpf_t rootOne, mpf_t rootTwo, int numRoots)
{
    mpf_t zeroCmp; //0.0 initialized for comparison
	mpf_init_set_d(zeroCmp, 0.0);

	mpf_t sqrt;     //square root of discriminant

	mpf_t numerator;      //either (-b + discriminant) or (-b - discriminant)
	mpf_t denom;	//2a basically
	mpf_t two;      //2, used for getting negative b

	mpf_t neg_b;    //negative b for operation
		
	mpf_init_set_d(two, 2.0); //set two to 2
	mpf_init(sqrt);
	mpf_init(numerator);
	mpf_init(denom);
	mpf_init(neg_b);
	
	mpf_mul(denom, a, two);		//2*a

	mpf_neg(neg_b, b);

    if (numRoots == 0) {
        return;
    }

    else if (numRoots == 1) {
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
		

		if (0 > mpf_cmp(b, zeroCmp)) {  //if b is negative then do -b+sqrt/2a
			mpf_add(numerator, neg_b,sqrt);
			mpf_div(rootOne, numerator, denom);

			if (mpf_cmp(rootOne, c) > 0) {				//if root one is greater than c then c/rootOne is rootTwo
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

			if (mpf_cmp(rootOne, c) > 0) {				//if root one is greater than c then c/rootOne is rootTwo
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

	mpf_clear(zeroCmp);
	mpf_clear(sqrt);
	mpf_clear(numerator);
	mpf_clear(denom);
	mpf_clear(two);
	mpf_clear(neg_b);

}
