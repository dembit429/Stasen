#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <random> 
#include <chrono> 
#include <cassert>


using namespace std;

void printArray(int** array, int size);
void fillArray(int** array,int size);
int** multiplyArrays(int** array1, int** array2,int size,int size1);
//-----------------------------------------------------
int** create(int** a, int l, int m, int n);
int** add(int** a, int** b, int n);
int** sub(int** a, int** b, int n);
void combine(int** c, int** c11, int i, int j, int n);
int** multiply(int** a, int** b, int n);

//-----------------------------------------------------
void addZeros(int**& matrix, int oldSize, int newSize);
void deleteMatrix(int**& matrix, int size);
int** createMatrix(int size);
