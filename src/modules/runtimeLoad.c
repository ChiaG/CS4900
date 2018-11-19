#include <stdio.h>
#include <stdlib.h>			

void runtimeLoad(double * toLoad)
{
	//printf("%p", toLoad);
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

	printf("%f", *toLoad);
	printf("%f", *(toLoad + sizeof(double)));
	printf("%f", *(toLoad + (2 * sizeof(double))));
}
