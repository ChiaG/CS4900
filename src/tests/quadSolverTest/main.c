#include "../../main/all.h"

int main(int argc, char *argv[])
{
	//Input these numbers to get the right discriminant and roots
	mpf_set_default_prec(6);

	mpf_t a;
	mpf_t b;
	mpf_t c;

	double testA = 10;
	double testB = 6;
	double testC = -1;

	mpf_init_set_d(a, testA); 
	mpf_init_set_d(b, testB);
	mpf_init_set_d(c, testC);

	mpf_t discriminant;
	mpf_t rootOne;  //two roots at most
	mpf_t rootTwo;
	int numRoots;
	mpf_init(discriminant);
	mpf_init(rootOne);
	mpf_init(rootTwo);

	findDiscriminant(a, b, c, discriminant);
	numRoots = findNumRoots(discriminant);    //find number of roots

	findRoots(a, b, c, discriminant, rootOne, rootTwo, numRoots);

	if (mpf_cmp_d(discriminant, 76.000000) != 0) {
		printf("Error Log File for inputTest\n");
		printf("----------------------------\n\n");
		printf("Expected Discriminant Output:\n");
		printf("Discriminant: 76.000000\n");
		printf("\n");
		printf("Actual Discriminant Output:\n");
		gmp_printf("Discriminant: %Ff\n", discriminant);
		
	}

	mpf_t cmpOne;
	mpf_t cmpTwo;
	mpf_t diffOne;
	mpf_t diffTwo;

	mpf_init(diffOne);
	mpf_init(diffTwo);
	mpf_init_set_d(cmpOne, -0.735890);
	mpf_init_set_d(cmpTwo, 1.358899);

	mpf_reldiff(diffOne, rootOne, cmpOne);
	mpf_reldiff(diffTwo, rootTwo, cmpTwo);

	gmp_printf("Difference for Expected Root One: %Ff\n", diffOne);
	gmp_printf("Difference for Expected Root Two: %Ff\n", diffTwo);

	// double dmacheps;
	// double dm;

	// while((1.0 + (dm = dmacheps / 2.0)) != 1.0  ) {
	//    dmacheps = dm;
	// } Compare each difference to <some number> * dmacheps afterwards. Draw inspiration from t1 & t2

	mpf_clear(diffOne);
	mpf_clear(diffTwo);
	mpf_clear(discriminant);
	mpf_clear(rootOne);
	mpf_clear(rootTwo);
	mpf_clear(cmpOne);
	mpf_clear(cmpTwo);

}
