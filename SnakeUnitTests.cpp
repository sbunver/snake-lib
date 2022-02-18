#include <gtest/gtest.h>
#include "Snake.hpp"

TEST(SLUnitTests, INITIAL_SNAKE)
{
    Snake s;
    s.printSnake();
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
