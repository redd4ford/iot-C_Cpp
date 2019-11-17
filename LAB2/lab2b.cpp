#include <iostream>
#include <cmath>

int main()
{

	double h; // ���� ���������; ����: 0.01
	double d; // �������; ����: 0.001
	double a, b; // ����� �� ������ ��� ���������; ����: � = -1, b = -0.9
	int k = 2; // k � �������
	double sum = 0; // ������� ����
	double element = 0; // �������� ����

						// �������� �������
	printf("Enter the tab step: ");
	scanf_s("%lf", &h);
	printf("Enter the observational error: ");
	scanf_s("%lf", &d);
	printf("Enter the lower limit of interval: ");
	scanf_s("%lf", &a);
	printf("Enter the upper limit of interval: ");
	scanf_s("%lf", &b);

	double x = a;

	while (x <= b + 0.005)
	{
		do
		{
			element = ((pow(-1, k))*cos(k*x)) / (pow(k, 2) - 1);
			sum += element;
			k++;
		} while (fabs(element) > d);

		printf("x = %lf ; y = %lf\n", x, sum);
		sum = 0;
		x += h;
		k = 2;
	}



	system("pause");
	return 0;

}
