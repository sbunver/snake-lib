#include <gtest/gtest.h>
#include "Snake.hpp"

TEST(SLUnitTests, INITIAL_SNAKE)
{
    Snake s(10);
    s.printSnake();
    s.Step();
    s.printSnake();
    s.Step();
    s.printSnake();
    s.Step();
    s.printSnake();
    s.SetSnakeDirection(SNAKE_MOVE_DOWN);
    s.Step();
    s.printSnake();
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
