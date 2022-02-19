#include <iostream>
#include "Snake.hpp"

SnakePoint moves[SNAKE_MOVE_COUNT] = 
{
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};
    
Snake::Snake(unsigned int gameSize)
{
    this->head = 0;
    this->tail = 0;
    this->moveDirection = SNAKE_MOVE_RIGHT;
    this->size = gameSize;
    
    // Add first 3 body part of snake
    SnakePoint p;
    p.posX = 0;
    p.posY = 0;
    
    addSnakeNodeToHead(p);
    
    p.posX = 1;
    p.posY = 0;
    addSnakeNodeToHead(p);
    
    p.posX = 2;
    p.posY = 0;
    addSnakeNodeToHead(p); 
}

void Snake::addSnakeNodeToHead(SnakePoint& point)
{
    SnakeNode* node = new SnakeNode;
    node->position.posX = point.posX;
    node->position.posY = point.posY;

    if(this->head == 0)
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        node->next = this->head;
        this->head = node;
    }

    return;
}

void Snake::calcNextStep(SnakePoint& p)
{  
    SnakePoint currentMove = moves[this->moveDirection];
    
    if(this->head != 0)
    {
        p.posX = this->head->position.posX + currentMove.posX;
        p.posY = this->head->position.posY + currentMove.posY;
    }
    else
    {
        // TODO log for null head
    }    
    
    return;
}

bool Snake::isNextStepValid(SnakePoint& newPoint)
{
    bool result = false;
   
    if(newPoint.posX <= this->size && newPoint.posY <= this->size)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

void Snake::Step()
{
    SnakePoint newPoint;
    memset(&newPoint, 0, sizeof(SnakePoint));
    
    calcNextStep(newPoint); // TODO get return value as error
    if(isNextStepValid(newPoint))
    {   
        // TODO add new head cell to head of snake
        // TODO shift all snake parT OF linked list
    }
}

void Snake::printSnake()
{
    SnakeNode* index = this->head;
    while(index != 0)
    {
        std::cout<<index->position.posX<<" "<<index->position.posY<<std::endl;
        index = index->next;
    }
}
