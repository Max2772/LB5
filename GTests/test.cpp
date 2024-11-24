#include "pch.h"
#include "../StaticLib/header.h"
#include <sstream> 


auto cinBuf = std::cin.rdbuf();

// readIntegerInLine()
TEST(ReadIntegerTest, INT_ValidInput1) {
    std::istringstream input("777\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), 777);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadIntegerTest, INT_ValidInput2) {
    std::istringstream input("3.1415\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), -INF);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadIntegerTest, INT_ValidInput3) {
    std::istringstream input("abc\nkdskosmgomsongonsdgn\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), -INF);
    std::cin.rdbuf(cinBuf);
}

// readDoubleInLine()
TEST(ReadDoubleTest, DOUBLE_ValidInput1) {
    std::istringstream input("777\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readDoubleInLine(), 777);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadDoubleTest, DOUBLE_ValidInput2) {
    std::istringstream input("3.1415\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readDoubleInLine(), 3.1415);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadDoubleTest, DOUBLE_InvalidInput3) {
    std::istringstream input("abc\nkdskosmgomsongonsdgn\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readDoubleInLine(), -INF);
    std::cin.rdbuf(cinBuf);
}

//findZeroesAmount()
TEST(findZeroesAmount, findZeroesAmountTest1) {
    int N = 2, K = 2;
    long double** arr = new long double* [N];
    for (int i = 0; i < N; ++i)
        arr[i] = new long double[K];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            arr[i][j] = 0;
        }
    }
    EXPECT_EQ(findZeroesAmount(N, K, arr), 4);

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
        arr[i] = NULL;
    }
    delete[] arr;
    arr = NULL;
}

TEST(findZeroesAmount, findZeroesAmountTest2) {
    int N = 1, K = 1;
    long double** arr = new long double* [N];
    for (int i = 0; i < N; ++i)
        arr[i] = new long double[K];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            arr[i][j] = 0;
        }
    }
    EXPECT_EQ(findZeroesAmount(N, K, arr), 1);

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
        arr[i] = NULL;
    }
    delete[] arr;
    arr = NULL;
}

TEST(findZeroesAmount, findZeroesAmountTest3) {
    int N = 10, K = 10;
    long double** arr = new long double* [N];
    for (int i = 0; i < N; ++i)
        arr[i] = new long double[K];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            arr[i][j] = 1.79769e308;
        }
    }
    EXPECT_EQ(findZeroesAmount(N, K, arr), 0);

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
        arr[i] = NULL;
    }
    delete[] arr;
    arr = NULL;
}

TEST(findZeroesAmount, findZeroesAmountTest4) {
    int N = 10000, K = 10000;
    long double** arr = new long double* [N];
    for (int i = 0; i < N; ++i)
        arr[i] = new long double[K];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            arr[i][j] = 0;
        }
    }
    EXPECT_EQ(findZeroesAmount(N, K, arr), 100000000);

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
        arr[i] = NULL;
    }
    delete[] arr;
    arr = NULL;
}
