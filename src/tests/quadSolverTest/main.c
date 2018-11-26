#include "../../main/all.h"

int main(int argc, char *argv[])
{
	//Input these numbers to get the right discriminant and roots
	mpf_set_default_prec(6);

	mpf_t a;
	mpf_t b;
	mpf_t c;

	double testA = 7;
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

	double dmacheps;
	double dm;

	/*while ((1.0+(dm=dmacheps/2.0)) != 1.0  ) {
		dmacheps = dm;
	}*/

	
	mpf_sub(diffOne, rootOne, cmpOne);
	mpf_abs(diffOne, diffOne);
	mpf_sub(diffTwo, rootTwo, cmpTwo);
	mpf_abs(diffTwo, diffTwo);

	if (mpf_cmp_d(diffOne, .000001) == 1 ){		//this is used to check difference
		printf("\nError Log File for inputTest\n");
		printf("----------------------------\n\n");
		printf("Expected Roots Output:\n");
		printf("Root One: -0.735890\n");
		printf("Root Two: 1.358899\n");
		printf("\n");
		printf("Actual Roots Output:\n");
		gmp_printf("Actual Root One: %Ff\n", rootOne);
		gmp_printf("Actual Root Two: %Ff\n", rootTwo);
	}

	mpf_clear(diffOne);
	mpf_clear(diffTwo);
	mpf_clear(discriminant);
	mpf_clear(rootOne);
	mpf_clear(rootTwo);
	mpf_clear(cmpOne);
	mpf_clear(cmpTwo);

}
