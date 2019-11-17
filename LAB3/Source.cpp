#include <stdlib.h> 
#include <iostream>
#define i 5		// i - �-���� �����
#define j 5		// j - �-���� �������� � �����

//������� ���������� �������� ����� ������� �� ��������� ������� �����
void msorting(int(&A)[i][j])
{
	for (int n = 0; n < i; n++)
	{
		for (int p = 0; p < j; p++)
		{
			for (int k = 0; k < j - 1; k++)
			{
				if (A[n][k] < A[n][k + 1])
				{
					int temp = A[n][k];
					A[n][k] = A[n][k + 1];
					A[n][k + 1] = temp;
				}
			}
		}
	}
}

//������� �������� �������
void moutput(int(&A)[i][j])
{
	for (int n = 0; n < i; n++)
	{
		for (int k = 0; k < j; k++)
		{
			if (A[n][k] < 0 && A[n][k] > -10)
				printf("  %d", A[n][k]);
			if (A[n][k] < -10)
				printf(" %d", A[n][k]);
			if (A[n][k] >= 0 && A[n][k] < 10)
				printf("   %d", A[n][k]);
			if (A[n][k] > 0 && A[n][k] > 9)
				printf("  %d", A[n][k]);
		}
		printf("\n");
	}
}

//������� �������� ���� �������� �������� ��� �������� ��������� �� �������� ��
int *msum(int(&A)[i][j])
{
	int sum[j - 1] = { NULL };
	static int sum2[j - 1] = { NULL };

	printf("\n\nSum of the elements of each column above the main diagonal of matrix === ");
	for (int k = 1; k < j; k++)
	{
		for (int n = 0; n < k && n < i - 1; n++)
		{
			sum[k - 1] += A[n][k];
		}
		printf("\n  sum[%d] = %d", k, sum[k - 1]);
		sum2[k - 1] = sum[k - 1];
	}

	return sum2;
}

//������� �������� ������� ��� �������� �������� ��� �������� ���������
int mprod(int sum2[])
{
	int prod = 1;

	for (int k = 0; k < j - 1; k++)
	{
		prod *= sum2[k];
	}

	printf("\n  prod = %d\n\n", prod);

	return prod;
}


int main()
{
	int A[i][j];

	//�������� �������� �������
	for (int n = 0; n < i; n++)
	{
		printf("\nEnter %d elements of row %d (separated by spaces):\n", j, n + 1);
		for (int k = 0; k < j; k++)
		{
			scanf_s("%d", &A[n][k]);
		}
	}

	system("cls");

	//��������� �������
	printf("Matrix A[%d][%d] === \n", i, j);
	moutput(A);

	//���������� �������
	msorting(A);

	//��������� ����������� �������
	printf("\n\nSorted matrix A[%d][%d] === \n", i, j);
	moutput(A);

	//���� �������� � ������� ������� ��� �������� ��������� ������� + ������� f(A);
	printf("\n\nProduct of sums === ");
	mprod(msum(A));

	system("pause");
	return 0;
}
