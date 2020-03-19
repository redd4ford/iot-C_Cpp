#include <iostream>
#include <iomanip>
#define row 5
#define column 5

class Vector
{
private:
	int matrixColumn[column];

public:
	friend void inputMatrix(Vector matrixRow[]);
	friend void outputMatrix(Vector matrixRow[]);
	void mergeSort(int theRow[], int rowLength);
	void merge(int firstPartOfRow[], int leftLimit, int secondPartOfRow[], int rightLimit, int theRow[]);
	void sortRowsInAscendingOrder(Vector matrixRow[]);
	double * getArithmeticMeanUnderMainDiagonal();
	double productOfArithmeticMeans(double arithmeticMean[]);
};


void inputMatrix(Vector matrixRow[])
{
	for (int rowPosition = 0; rowPosition < row; rowPosition++)
	{
		for (int columnPosition = 0; columnPosition < column; columnPosition++)
		{
			std::cin >> matrixRow[rowPosition].matrixColumn[columnPosition];
		}
	}
}

void outputMatrix(Vector matrixRow[])
{
	for (int rowPosition = 0; rowPosition < row; rowPosition++)
	{
		for (int columnPosition = 0; columnPosition < column; columnPosition++)
		{
			std::cout << std::setw(5) << matrixRow[rowPosition].matrixColumn[columnPosition] << " ";
		}
		std::cout << std::endl;
	}
}

void Vector::merge(int firstPartOfRow[], int firstPartOfRowLength, int secondPartOfRow[], int secondPartOfRowLength, int theRow[])
{
	int firstPartPosition = 0;
	int secondPartPosition = 0;
	int originalRowPosition = 0;

	while (firstPartPosition < firstPartOfRowLength && secondPartPosition < secondPartOfRowLength)
	{

		if (firstPartOfRow[firstPartPosition] < secondPartOfRow[secondPartPosition])
		{
			theRow[originalRowPosition] = firstPartOfRow[firstPartPosition];
			firstPartPosition++;
			originalRowPosition++;
		}
		else
		{
			theRow[originalRowPosition] = secondPartOfRow[secondPartPosition];
			secondPartPosition++;
			originalRowPosition++;
		}
	}

	if (firstPartPosition >= firstPartOfRowLength)
	{
		theRow[originalRowPosition] = secondPartOfRow[secondPartPosition];
		secondPartPosition++;
		originalRowPosition++;
	}
	else if (secondPartPosition >= secondPartOfRowLength)
	{
		theRow[originalRowPosition] = firstPartOfRow[firstPartPosition];
		firstPartPosition++;
		originalRowPosition++;
	}
}

void Vector::mergeSort(int theRow[], int rowLength)
{
	int firstPartOfRowLength = rowLength / 2;
	int secondPartOfRowLength = rowLength - firstPartOfRowLength;

	int * firstPartOfRow = new int[firstPartOfRowLength];
	int * secondPartOfRow = new int[secondPartOfRowLength];

	for (int rowPosition = 0; rowPosition < firstPartOfRowLength; rowPosition++)
	{
		firstPartOfRow[rowPosition] = theRow[rowPosition];
	}

	for (int rowPosition = 0; rowPosition < secondPartOfRowLength; rowPosition++)
	{
		secondPartOfRow[rowPosition] = theRow[firstPartOfRowLength + rowPosition];
	}

	if (rowLength == 2)
	{
		merge(firstPartOfRow, firstPartOfRowLength, secondPartOfRow, secondPartOfRowLength, theRow);
	}
	else if (rowLength == 3)
	{
		mergeSort(secondPartOfRow, secondPartOfRowLength);
		merge(firstPartOfRow, firstPartOfRowLength, secondPartOfRow, secondPartOfRowLength, theRow);
	}
	else
	{
		mergeSort(firstPartOfRow, firstPartOfRowLength);
		mergeSort(secondPartOfRow, secondPartOfRowLength);
		merge(firstPartOfRow, firstPartOfRowLength, secondPartOfRow, secondPartOfRowLength, theRow);
	}


	delete[] firstPartOfRow;
	delete[] secondPartOfRow;
}

void Vector::sortRowsInAscendingOrder(Vector matrixRow[])
{
	for (int rowPosition = 0; rowPosition < row; rowPosition++)
	{
		mergeSort(matrixRow[rowPosition].matrixColumn, row);
	}
}

double * Vector::getArithmeticMeanUnderMainDiagonal()
{
	double * arithmeticMeans = new double[column - 1];
	int numberOfColumnsToCalculate = column - 1;
	double temporaryElementStore = 0;
	int rowPositionUnderMainDiagonal = 1;


	for (int columnPosition = 0; columnPosition < column - 1; columnPosition++)
	{
		for (int rowPosition = rowPositionUnderMainDiagonal; rowPosition < row; rowPosition++)
		{
			temporaryElementStore += this[rowPosition].matrixColumn[columnPosition];
		}
		arithmeticMeans[columnPosition] = temporaryElementStore / numberOfColumnsToCalculate;
		numberOfColumnsToCalculate--;
		std::cout << "Column #" << columnPosition + 1 << " === " << arithmeticMeans[columnPosition] << std::endl;
		temporaryElementStore = 0;
		rowPositionUnderMainDiagonal++;
	}
	return arithmeticMeans;
}

double Vector::productOfArithmeticMeans(double arithmeticMeans[])
{

	double product = 1;
	for (int columnNumber = 0; columnNumber < column - 1; columnNumber++)
	{
		product *= arithmeticMeans[columnNumber];
	}

	std::cout << std::endl << "Product of arithmetic means === " << product;

	return product;
}

int main()
{
	Vector matrix5x5[row];
	std::cout << "Please enter your matrix (elements separated by SPACES, new rows start with ENTER): " << std::endl;
	inputMatrix(matrix5x5);
	system("cls");
	std::cout << "Your matrix === " << std::endl << std::endl;
	outputMatrix(matrix5x5);
	std::cout << std::endl << std::endl << "Sorted matrix === " << std::endl << std::endl;
	matrix5x5->sortRowsInAscendingOrder(matrix5x5);
	outputMatrix(matrix5x5);
	std::cout << std::endl << std::endl << "Arithmetic means under main diagonal in each column === " << std::endl << std::endl;
	matrix5x5->productOfArithmeticMeans(matrix5x5->getArithmeticMeanUnderMainDiagonal());
	std::cout << std::endl;

	system("pause");
	return 0;
}