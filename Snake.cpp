#include <iostream>
#include <stdlib.h>
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
    this->mouse.posX = 0;
    this->mouse.posY = 5;
    
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
   
    if(newPoint.posX < this->size && newPoint.posY < this->size)
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

SNAKE_INTERNAL_RET Snake::deleteLastNode()
{
    SNAKE_INTERNAL_RET ret = SNAKE_INTERNAL_RET_UNDEFINED;
    
    if(this->head != 0)
    {
        SnakeNode* index = this->head;
        
        while(index != 0)
        {
            if(index->next->next == 0)
            {
                delete index->next;
                index->next = 0;
                ret = SNAKE_INTERNAL_RET_SUCCESS;
            }
            index = index->next;
        }
    }
    else
    {
        ret = SNAKE_INTERNAL_RET_NULL_HEAD;
    }

    return ret;    
}

bool Snake::isMouseEaten(const SnakePoint& newPoint)
{
    bool ret = false;

    if(newPoint.posX == this->mouse.posX &&
        newPoint.posY == this->mouse.posY)
    {
        ret = true;
        this->mouse.posX = rand() % size;
        this->mouse.posY = rand() % size;
    }
    else
    {
        ret = false;
    }

    return ret;
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
                if(!isMouseEaten(newPoint))
                {
                    internalRet = deleteLastNode();
                    if(internalRet == SNAKE_INTERNAL_RET_SUCCESS)
                    {
                        ret = SNAKE_RET_CONTINUE;
                    }
                    else
                    {
                        ret = SNAKE_RET_UNDEFINED;
                        // TODO Report internal error to a function
                    }
                }
                else
                {
                    // No need to delete last node, mouse is eaten
                    ret = SNAKE_RET_CONTINUE;
                }    
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
    std::cout<<"Mouse : "<<this->mouse.posX<<" "<<this->mouse.posY<<std::endl;
    std::cout<<std::endl;
}
