#ifndef SNAKE_H
#define SNAKE_H

enum SNAKE_RET
{
    SNAKE_RET_UNDEFINED,
    SNAKE_RET_GAME_OVER,
    SNAKE_RET_CONTINUE
};

enum SNAKE_INTERNAL_RET
{   
    SNAKE_INTERNAL_RET_UNDEFINED,
    SNAKE_INTERNAL_RET_NULL_HEAD,
    SNAKE_INTERNAL_RET_NEG_POS, // TODO check negative positions
    SNAKE_INTERNAL_RET_NO_MEM,
    SNAKE_INTERNAL_RET_SUCCESS
};

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
    Snake(unsigned int gameSize);
    SNAKE_RET Step();
    void SetSnakeDirection(SNAKE_MOVE newDirection);
    void GetGameBoard(char* gameBoard, unsigned int gameBoardSize);
    private:
    SNAKE_INTERNAL_RET addSnakeNodeToHead(SnakePoint& point);
    bool isNextStepValid(SnakePoint& newPoint);
    SNAKE_INTERNAL_RET calcNextStep(SnakePoint& p);
    bool isBiteItself(const SnakePoint& searchPoint);
    SNAKE_INTERNAL_RET deleteLastNode();
    bool isMouseEaten(const SnakePoint& newPoint);
    void reportSnakeInternalError(SNAKE_INTERNAL_RET err);
    SNAKE_INTERNAL_RET getSnakeInternalError();
    SnakeNode* head;
    SnakeNode* tail;
    SNAKE_MOVE moveDirection;
    unsigned int size;
    SnakePoint mouse;
    SNAKE_INTERNAL_RET internalErr;
};

#endif
