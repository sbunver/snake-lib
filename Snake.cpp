#include <iostream>
#include "Snake.hpp"

SnakePoint moves[SNAKE_MOVE_COUNT] = 
{
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};
    
Snake::Snake()
{
    this->head = nullptr;
    this->tail = nullptr;
    
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

    if(this->head == nullptr)
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

void Step()
{
    // TODO calculate next head cell according to move direction
    // TODO if next head cell is valid
    // TODO add new head cell to head of snake
    // TODO shift all snake parT OF linked list
}

void Snake::printSnake()
{
    SnakeNode* index = this->head;
    while(index != nullptr)
    {
        std::cout<<index->position.posX<<" "<<index->position.posY<<std::endl;
        index = index->next;
    }
}
