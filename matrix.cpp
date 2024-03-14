#include "matrix.h"

void printArray(int** array, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void fillArray(int** array, int rows)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			  array[i][j]=rand() % 10;
		}
	}
}

int** multiplyArrays(int** array1, int** array2, int size,int size1)
{
	if (size != size1)
	{
		cout << "The matrices cannot be multiplied with each other." << endl;
		return 0;
	}

	int** result = new int* [size];
	for (int i = 0; i < size; i++)
	{
		result[i] = new int[size];
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < size1; k++)
			{
				result[i][j] += array1[i][k] * array2[k][j];
			}
		}
	}
	cout<< "The result of the multiplication is:" << endl;
	printArray(result,size1);

	return result;
}

int** create(int** a, int l, int m, int n)
{
	int i, k, o, b;
	int** c = new int* [n];
	for (i = 0; i < n; i++)
		c[i] = new int[n];
	for (k = 0, i = l; k < n; k++, i++)
		for (o = 0, b = m; o < n; o++, b++)
			c[k][o] = a[i][b];
	return c;
}

int** add(int** a, int** b, int n)
{
	int** c = new int* [n];
	int i, j;
	for (i = 0; i < n; i++)
		c[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			c[i][j] = a[i][j] + b[i][j];
	return c;
}

int** sub(int** a, int** b, int n)
{
	int** c = new int* [n];
	int i, j;
	for (i = 0; i < n; i++)
		c[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			c[i][j] = a[i][j] - b[i][j];
	return c;
}

void combine(int** c, int** c11, int i, int j, int n)
{
	int a, b, x, y;
	for (a = 0, x = i; a < n; a++, x++)
		for (b = 0, y = j; b < n; b++, y++)
			c[x][y] = c11[a][b];
}

int** multiply(int** a, int** b, int n)
{
	if (n == 1)
	{
		int** c = new int* [n];
		c[0] = new int[n];
		c[0][0] = a[0][0] * b[0][0];
		return c;
	}
	int** a11 = create(a, 0, 0, n / 2);
	int** a12 = create(a, 0, n / 2, n / 2);
	int** a21 = create(a, n / 2, 0, n / 2);
	int** a22 = create(a, n / 2, n / 2, n / 2);
	int** b11 = create(b, 0, 0, n / 2);
	int** b12 = create(b, 0, n / 2, n / 2);
	int** b21 = create(b, n / 2, 0, n / 2);
	int** b22 = create(b, n / 2, n / 2, n / 2);

	int** p1 = multiply(add(a11, a22, n / 2), add(b11, b22, n / 2), n / 2);
	int** p2 = multiply(add(a21, a22, n / 2), b11, n / 2);
	int** p3 = multiply(a11, sub(b12, b22, n / 2), n / 2);
	int** p4 = multiply(a22, sub(b21, b11, n / 2), n / 2);
	int** p5 = multiply(add(a11, a12, n / 2), b22, n / 2);
	int** p6 = multiply(sub(a21, a11, n / 2), add(b11, b12, n / 2), n / 2);
	int** p7 = multiply(sub(a12, a22, n / 2), add(b21, b22, n / 2), n / 2);

	int** c11 = add(sub(add(p1, p4, n / 2), p5, n / 2), p7, n / 2);
	int** c12 = add(p3, p5, n / 2);
	int** c21 = add(p2, p4, n / 2);
	int** c22 = add(sub(add(p1, p3, n / 2), p2, n / 2), p6, n / 2);

	int** c = new int* [n];
	for (int i = 0; i < n; i++)
		c[i] = new int[n];

	combine(c, c11, 0, 0, n / 2);
	combine(c, c12, 0, n / 2, n / 2);
	combine(c, c21, n / 2, 0, n / 2);
	combine(c, c22, n / 2, n / 2, n / 2);
	return c;
}


void addZeros(int**& matrix, int oldSize, int newSize) {
	if (oldSize == newSize) { 
		printArray(matrix, newSize);
		return;
	};

	
	int** temp = new int* [newSize];
	for (int i = 0; i < newSize; ++i) {
		temp[i] = new int[newSize];
	}

	for (int i = 0; i < oldSize; ++i) {
		for (int j = 0; j < oldSize; ++j) {
			temp[i][j] = matrix[i][j];
		}
	}

	
	for (int i = oldSize; i < newSize; ++i) {
		for (int j = 0; j < newSize; ++j) {
			temp[i][j] = 0;
		}
	}
	for (int i = 0; i < newSize; ++i) {
		for (int j = oldSize; j < newSize; ++j) {
			temp[i][j] = 0;
		}
	}

	
	matrix = temp;
	printArray(matrix, newSize);
}

void deleteMatrix(int**& matrix, int size)
{
	for (int i = 0; i < size; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	
}

int** createMatrix(int size)
{
	int** array = new int* [size];
	for (int i = 0; i < size; i++) {
		array[i] = new int[size];
		
	}
	return array;
}


