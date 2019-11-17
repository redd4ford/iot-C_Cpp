#include <iostream>
#include <cmath>

int main()
{

	double x;
	double h; // ���� ���������
	double a, b; // ����� �� ������ ��� ���������
	double func1 = 0;
	double func2 = 0;
	double func3 = 0;

	// �������� �������
	printf("Enter the tab step: ");
	scanf_s("%lf", &h);
	printf("Enter the lower limit of interval: ");
	scanf_s("%lf", &a);
	printf("Enter the upper limit of interval: ");
	scanf_s("%lf", &b);

	for (x = a; x <= b + 0.1; x += h)
	{
		if (x < 2)	//����� �������
		{
			func1 = 1 / (sin(exp(x)));
			printf("\nx = %lf ; y = %lf ; x [%lf; 2) - func1", x, func1, a);
		}
		if (x >= 2 && x < 3)	//����� �������
		{
			func2 = 1 / (cos(log(x)));
			printf("\nx = %lf ; y = %lf ; x [2; 3) - func2", x, func2);
		}
		if (x >= 3)		//����� �������
		{
			func3 = sin(log(x));
			printf("\nx = %lf ; y = %lf ; x [3; +inf) - func3", x, func3);
		}
	}

	printf("\n\nThere are no more values belonging to the interval [%f, %f].\n", a, b);
	system("pause");
	return 0;
}
