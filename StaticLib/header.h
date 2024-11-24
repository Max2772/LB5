#pragma once
const int INF = 666666666;
int readIntegerInLine();
long double readDoubleInLine();
int** initMatrix(int, int);
void free2DMatrix(int**, int);
int** findZeroesLocation(int N, int K, int** arr);
int findZeroesAmount(int N, int K, int** arr);