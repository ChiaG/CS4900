#include "../main/All.h"		

void runtimeLoad(double *toLoadA, double *toLoadB, double *toLoadC)
{
	//Variable declaration
	char *inBuffer = malloc(sizeof(char) * 256);
	
	//Introductory and input-clarifying messages
	printf("\nQuadratic Equation Solver\n");
	printf("-------------------------\n");
	printf("\nNote: Program will continue execution until three valid inputs are entered.\n");
	printf("      A valid input is described as any numerical value that is not zero.\n");
	printf("      Program will disregard any numerical entries after the first for a\n");
	printf("      given value.\n\n");

	//Input read. Loops will execute until a valid input is given. 
	do{
		printf("Please enter a number for root a: ");
		fgets(inBuffer, 256, stdin);
		// if (*toLoad == 0) { printf("a, b, and c can't be zero!\n"); }
	}
	while(sscanf(inBuffer, "%lf", toLoadA) != 1 || *toLoadA == 0);
	do{
		printf("Please enter a number for root b: ");
		fgets(inBuffer, 256, stdin);
	}
	while(sscanf(inBuffer, "%lf", toLoadB) != 1 || *toLoadB == 0);
	do{
		printf("Please enter a number for root c: ");
		fgets(inBuffer, 256, stdin);
	}
	while(sscanf(inBuffer, "%lf", toLoadC) != 1 || *toLoadC == 0);

	free(inBuffer);	//Free unused memory buffer to plug memory leak.
	return;
}
