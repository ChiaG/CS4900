#include "../../main/all.h"

int main(int argc, char *argv[])
{
	//Input variable declaration and input function execution.
	double toLoadA = 0;
	double toLoadB = 0;
    double toLoadC = 0;
	runtimeLoad(&toLoadA, &toLoadB, &toLoadC);

	if (toLoadA != 2 || toLoadB != 5 || toLoadC != 3) {
		printf("Error Log File for inputTest\n");
		printf("----------------------------\n\n");
		printf("Expected Input:\n");
		printf("	A. 2\n");
		printf("	B. 5\n");
		printf("	C. 3\n\n");
		printf("Actual Input:\n");
		printf("	A. %f\n", toLoadA);
		printf("	B. %f\n", toLoadB);
		printf("	C. %f\n", toLoadC);	
	}

}
