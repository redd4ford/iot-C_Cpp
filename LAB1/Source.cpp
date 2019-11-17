#include <iostream>

int main()
{
	float z;
	
	scanf_s("%f", &z);

	float res = pow(z,6) + (13 * pow(z,4)) + (7 * pow(z,3)) + (14 * pow(z,2)) - (2 * z) + 21;

	printf("result = %lf \n", res);

	system("pause");
	return 0;
}