#include "pch.h"
#include "../MyLib/header.h"
#include <sstream> 

auto cinBuf = std::cin.rdbuf();

TEST(ReadIntegerTest, INT_ValidInput) {
    std::istringstream input("777\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), 777);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadIntegerTest, INT_ValidInput1) {
    std::istringstream input("3.1415\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), -INF);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadIntegerTest, INT_InvalidInput2) {
    std::istringstream input("abc\nkdskosmgomsongonsdgn\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), -INF);
    std::cin.rdbuf(cinBuf);
}
TEST(SolveProblemTest, solveProblem1) {
    long long res = -7;
    EXPECT_EQ(solveProblem(1), res);
}

TEST(SolveProblemTest, solveProblem2) {
    long long res = 8;
    EXPECT_EQ(solveProblem(3), res);
}

TEST(SolveProblemTest, solveProblem3) {
    long long res = 5823283;
    EXPECT_EQ(solveProblem(100), res);
}