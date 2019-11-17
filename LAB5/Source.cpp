#include <iostream>
#include <iomanip>
#define row 5
#define column 5

class Vector
{
private:
	int B[column];

public:
	friend void InputMatrix(Vector A[]);
	friend void OutputMatrix(Vector A[]);
	void mergeSort(int theRow[], int rowLength);
	void merge(int firstPartOfRow[], int leftLimit, int secondPartOfRow[], int rightLimit, int theRow[]);
	void Sort(Vector A[]);
	double * getArithmeticMeanUnderDiagonal();
	double productOfArithmeticMeans(double arithmeticMean[]);
};


void InputMatrix(Vector A[])
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			std::cin >> A[i].B[j];
		}
	}
}

void OutputMatrix(Vector A[])
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			std::cout << std::setw(5) << A[i].B[j] << " ";
		}
		std::cout << std::endl;
	}
}

void Vector::merge(int firstPartOfRow[], int leftLimit, int secondPartOfRow[], int rightLimit, int theRow[])
{
	int a = 0;
	int b = 0;
	int c = 0;

	while (a < leftLimit && b < rightLimit)
	{

		if (firstPartOfRow[a] < secondPartOfRow[b])
		{
			theRow[c] = firstPartOfRow[a];
			a++;
			c++;
		}
		else
		{
			theRow[c] = secondPartOfRow[b];
			b++;
			c++;
		}
	}

	if (a >= leftLimit)
		{
			theRow[c] = secondPartOfRow[b];
			b++;
			c++;
		}
	else if (b >= rightLimit)
		{
			theRow[c] = firstPartOfRow[a];
			a++;
			c++;
		}
}

void Vector::mergeSort(int theRow[], int rowLength)
{
	int leftLimit = rowLength / 2;
	int rightLimit = rowLength - leftLimit;
	
	int * firstPartOfRow = new int[leftLimit];
	int * secondPartOfRow = new int[rightLimit];

	for (int i = 0; i < leftLimit; i++)
	{
		firstPartOfRow[i] = theRow[i];
	}

	for (int i = 0; i < rightLimit; i++)
	{
		secondPartOfRow[i] = theRow[leftLimit + i];
	}

	if (rowLength == 2)
	{
		merge(firstPartOfRow, leftLimit, secondPartOfRow, rightLimit, theRow);
	}
	else if (rowLength == 3)
	{
		mergeSort(secondPartOfRow, rightLimit);
		merge(firstPartOfRow, leftLimit, secondPartOfRow, rightLimit, theRow);
	}
	else
	{
		mergeSort(firstPartOfRow, leftLimit);
		mergeSort(secondPartOfRow, rightLimit);
		merge(firstPartOfRow, leftLimit, secondPartOfRow, rightLimit, theRow);
	}
	

	delete[] firstPartOfRow;
	delete[] secondPartOfRow;
}

void Vector::Sort(Vector A[])
{
	for (int i = 0; i < row; i++)
	{
		mergeSort(A[i].B, row);
	}
}

double * Vector::getArithmeticMeanUnderDiagonal()
{
	double * arithmeticMean = new double[column - 1];
	int n = column-1;
	double temp = 0;
	int numunderdiag = 1;


	for (int i = 0; i < column - 1; i++)
	{
		for (int j = numunderdiag; j < row; j++)
		{
			temp += this[j].B[i];
		}
		arithmeticMean[i] = temp / n;
		n--;
		std::cout << "Column #" << i + 1 << " === " << arithmeticMean[i] << std::endl;
		temp = 0;
		numunderdiag++;
	}
	return arithmeticMean;
}

double Vector::productOfArithmeticMeans(double arithmeticMean[])
{

	double product = 1;
	for (int i = 0; i < column - 1; i++)
	{
		product *= arithmeticMean[i];
	}

	std::cout << std::endl << "Product of arithmetic means === " << product;

	return product;
}

int main()
{
	Vector matrix5x5[row];
	std::cout << "Please enter your matrix (elements separated by SPACES, new rows start with ENTER): " << std::endl;
	InputMatrix(matrix5x5);
	system("cls");
	std::cout << "Your matrix === " << std::endl << std::endl;
	OutputMatrix(matrix5x5);
	std::cout << std::endl << std::endl << "Sorted matrix === " << std::endl << std::endl;
	matrix5x5->Sort(matrix5x5);
	OutputMatrix(matrix5x5);
	std::cout << std::endl << std::endl << "Arithmetic means under main diagonal in each column === " << std::endl << std::endl;
	matrix5x5->productOfArithmeticMeans(matrix5x5->getArithmeticMeanUnderDiagonal());
	std::cout << std::endl;

	system("pause");
	return 0;
}