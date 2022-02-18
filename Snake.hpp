#ifndef SNAKE_H
#define SNAKE_H

enum SNAKE_MOVE
{
    SNAKE_MOVE_UP,
    SNAKE_MOVE_RIGHT,
    SNAKE_MOVE_DOWN,
    SNAKE_MOVE_LEFT,
    SNAKE_MOVE_COUNT
};

struct SnakePoint
{
    int posX;
    int posY;
};

struct SnakeNode
{
    SnakePoint position;
    SnakeNode* next;
};

class Snake
{
    public:
    Snake();
    void Step();
    void printSnake();
    private:
    void addSnakeNodeToHead(SnakePoint& point);
    SnakeNode* head;
    SnakeNode* tail;
};

#endif
