#include "../../src/main/all.h"

int main() {
	char *inBuffer = malloc(sizeof(char) * 256);
	double *stored_input = malloc(sizeof(double));

	do{
		printf("Enter input to test (expecting integer or floating-point number):\n");
		
		fgets(inBuffer, 256, stdin);
	}
	while (sscanf(inBuffer, "%lf", stored_input) != 1 || *stored_input == 0);

	return 0;
}