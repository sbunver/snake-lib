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
    
    p.posX = 0;
    p.posY = 1;
    addSnakeNodeToHead(p);
    
    p.posX = 0;
    p.posY = 2;
    addSnakeNodeToHead(p); 
}

SNAKE_INTERNAL_RET Snake::addSnakeNodeToHead(SnakePoint& point)
{
    SNAKE_INTERNAL_RET ret = SNAKE_INTERNAL_RET_UNDEFINED;
    SnakeNode* node = new SnakeNode;

    if(node != 0)
    {
        node->position.posX = point.posX;
        node->position.posY = point.posY;

        if(this->head == 0)
        {
            this->head = node;
            this->tail = node; // TODO check for tail is need?
        }
        else
        {
            node->next = this->head;
            this->head = node;
        }
        
        ret = SNAKE_INTERNAL_RET_SUCCESS;
    }
    else
    {
        ret = SNAKE_INTERNAL_RET_NO_MEM;
    }

    return ret;
}

SNAKE_INTERNAL_RET Snake::calcNextStep(SnakePoint& p)
{  
    SNAKE_INTERNAL_RET ret = SNAKE_INTERNAL_RET_UNDEFINED;
    
    if(this->head != 0)
    {
        SnakePoint currentMove = moves[this->moveDirection];
        p.posX = this->head->position.posX + currentMove.posX;
        p.posY = this->head->position.posY + currentMove.posY;
        ret = SNAKE_INTERNAL_RET_SUCCESS;
    }
    else
    {
        ret = SNAKE_INTERNAL_RET_NULL_HEAD;
    }    
    
    return ret;
}

bool Snake::isBiteItself(const SnakePoint& searchPoint)
{
    bool ret = false;

    SnakeNode* index = this->head;

    while(index != 0)
    {
        if(index->position.posX == searchPoint.posX &&
            index->position.posY == searchPoint.posY)
        {
            ret = true;
        }
        index = index->next;
    }

    return ret;
}

bool Snake::isNextStepValid(SnakePoint& newPoint)
{
    bool result = false;
   
    if(newPoint.posX <= this->size && newPoint.posY <= this->size)
    {
        if(isBiteItself(newPoint) == false)
        {
            result = true;
        }
        else
        {
            result = false;
        }    
    }
    else
    {
        result = false;
    }

    return result;
}

SNAKE_RET Snake::Step()
{
    SNAKE_RET ret = SNAKE_RET_UNDEFINED;
    SNAKE_INTERNAL_RET internalRet = SNAKE_INTERNAL_RET_UNDEFINED;
    SnakePoint newPoint;

    memset(&newPoint, 0, sizeof(SnakePoint));
    internalRet = calcNextStep(newPoint);
    
    if(internalRet == SNAKE_INTERNAL_RET_SUCCESS)
    { 
        if(isNextStepValid(newPoint))
        {
            internalRet = addSnakeNodeToHead(newPoint);
            if(internalRet == SNAKE_INTERNAL_RET_SUCCESS)
            {
                // TODO shift all snake parT OF linked list
            }
            else
            {
                ret = SNAKE_RET_UNDEFINED;
                // TODO Report internal error to a function
            }        
        }
        else
        {
            ret = SNAKE_RET_GAME_OVER;
        }
    }
    else
    {
        ret = SNAKE_RET_UNDEFINED;
        // TODO Report internal error to a function
    }

    return ret;
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
