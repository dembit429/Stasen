#include "matrix.h"
void testStrassenMultiplication() {

    const int n = 8; 
    int** A = createMatrix(n);
    int** B = createMatrix(n);

    fillArray(A, n);
    fillArray(B, n);

    
    int** standardResult = multiplyArrays(A, B, n,n);

    int** strassenResult = multiply(A, B, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            assert(standardResult[i][j] == strassenResult[i][j]);
        }
    }

    
    deleteMatrix(A, n);
    deleteMatrix(B, n);
    deleteMatrix(standardResult, n);
    deleteMatrix(strassenResult, n);

    cout << "Test Strassen Multiplication passed successfully!" << endl;
}
void testStrassenWithLargeMatrix() {
    const int n = 256; 
    int** A = createMatrix(n);
    int** B = createMatrix(n);

    
    fillArray(A, n);
    fillArray(B, n);

    
    clock_t start = clock();
    int** strassenResult = multiply(A, B, n);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Strassen Multiplication for a " << n << "x" << n << " matrix took " << duration << " seconds." << endl;

    
    deleteMatrix(A, n);
    deleteMatrix(B, n);
    deleteMatrix(strassenResult, n);

    cout << "Test Strassen Multiplication with Large Matrix passed successfully!" << endl;
}



void simple() {
    
    srand(time(NULL));
    int rows, cols,rows1,cols1;
    cout<<"Enter the size of the first matrix: ";
    cin >> rows; 
    cols=rows;
    int** array1 = createMatrix(rows);
    fillArray(array1, rows);
    cout<<"Enter the size of the second matrix: ";
    cin >> rows1;
    cols1 = rows1;
    int** array2 = createMatrix(rows1);
    fillArray(array2, rows1);
    

    printArray(array1, rows);
    printArray(array2, rows1);
    clock_t start = clock();
    multiplyArrays(array1, array2, rows,cols);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Multiplication took " << duration << " seconds." << endl;
    deleteMatrix(array1, rows);
    deleteMatrix(array2, rows1);
    system("pause");
}


int main()
{   
    testStrassenMultiplication();
    system("pause");
    testStrassenWithLargeMatrix();
    
    

    simple();
    srand(time(NULL));
    int n;
    cout << "Enter size: ";
    cin >> n;

    int** array1=createMatrix(n);
    int** b1=createMatrix(n);
    fillArray(array1, n);
    fillArray(b1, n);

    int q = 2;
    while (q < n)
    {
        q *= 2;
    }

    cout << "Matrix was increased to: " << q << endl;

    cout << "Matrix1: " << endl;
    addZeros(array1, n, q);
    cout << "Matrix2: " << endl;
    addZeros(b1, n, q);
    
    clock_t start = clock();
    cout << "Multiplication: " << endl;
    int** c = multiply(array1, b1, q);
    printArray(c, n);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Multiplication took " << duration << " seconds." << endl;

    deleteMatrix(array1, n);
    deleteMatrix(b1, n);

    return 0;
}
