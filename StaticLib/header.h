#pragma once
const int INF = 666666666;
int readIntegerInLine();
long double readDoubleInLine();
long double** initMatrix(int, int);
void free2DMatrixInteger(int**, int);
void free2DMatrixDouble(long double**, int);
int** findZeroesLocation(int N, int K, long double** arr);
int findZeroesAmount(int N, int K, long double** arr);