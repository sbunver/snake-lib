#ifndef SNAKE_H
#define SNAKE_H

struct SnakeNode
{
    unsigned int posX;
    unsigned int posY;
    SnakeNode* next;
};

class Snake
{
    public:
    Snake();
    void printSnake();
    private:
    void addSnakeNode(unsigned int x, unsigned int y);
    SnakeNode* head;
    SnakeNode* tail;
};

#endif
