#include "all.h"

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
	mpf_t rootOne;  //two roots at most
	mpf_t rootTwo;
	int numRoots;
	mpf_init(discriminant); // Initiating values to get discriminant
	mpf_init(rootOne);
	mpf_init(rootTwo);

	findDiscriminant(a, b, c, discriminant);  //find discriminant
	numRoots = findNumRoots(discriminant);    //find number of roots

	findRoots(a, b, c, discriminant, rootOne, rootTwo, numRoots);	//find roots

	mpf_clear(discriminant);
	mpf_clear(rootOne);
	mpf_clear(rootTwo);
    

}
