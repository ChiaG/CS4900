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

	mpf_init_set_d(cmpOne, -0.735890);
	mpf_init_set_d(cmpTwo, 1.358899);
	
	if (mpf_cmp(rootOne, cmpOne) != 0 || mpf_cmp(rootTwo, cmpTwo)){
		printf("Error Log File for inputTest\n");
		printf("----------------------------\n\n");
		printf("Expected Root Output:\n");
		printf("Root One: -0.735890\n");
		printf("Root Two: 1.358899\n");
		printf("\n");
		printf("Actual Root Output:\n");
		gmp_printf("Root One: %Ff\n", rootOne);
		gmp_printf("Root Two: %Ff\n", rootTwo);
	}

	mpf_clear(discriminant);
	mpf_clear(rootOne);
	mpf_clear(rootTwo);
	mpf_clear(cmpOne);
	mpf_clear(cmpTwo);

}
