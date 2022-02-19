#include <gtest/gtest.h>
#include "Snake.hpp"

void PrintGameBoard(char* gameBoard, unsigned int size)
{
   for(int i = 0; i < size; i++)
    {
        std::cout<<"-";
    }

    std::cout<<std::endl;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            std::cout<<gameBoard[i * size + j]<<" ";
        }

        std::cout<<std::endl;
    }

    for(int i = 0; i < size; i++)
    {
        std::cout<<"-";
    }

    std::cout<<std::endl;
}

TEST(SLUnitTests, INITIAL_SNAKE)
{
    char gameBoard[100];
    Snake s(10);
    s.GetGameBoard(gameBoard, 100);
    PrintGameBoard(gameBoard, 10);   

    s.Step();
    s.GetGameBoard(gameBoard, 100);
    PrintGameBoard(gameBoard, 10);

    s.Step();
    s.GetGameBoard(gameBoard, 100);
    PrintGameBoard(gameBoard, 10);

    s.Step();
    s.GetGameBoard(gameBoard, 100);
    PrintGameBoard(gameBoard, 10);

    s.SetSnakeDirection(SNAKE_MOVE_DOWN);
    s.Step();
    s.GetGameBoard(gameBoard, 100);
    PrintGameBoard(gameBoard, 10);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
