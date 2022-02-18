#include <iostream>
#include "Snake.hpp"
    
Snake::Snake()
{
    this->head = nullptr;
    this->tail = nullptr;
    
    addSnakeNode(0,0);
    addSnakeNode(1,0);
    addSnakeNode(2,0); 
}

void Snake::addSnakeNode(unsigned int x, unsigned int y)
{
    SnakeNode* node = new SnakeNode;
    node->posX = x;
    node->posY = y;

    if(this->head == nullptr)
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        this->tail->next = node;
        this->tail = this->tail->next;
    }

    return;
}

void Snake::printSnake()
{
    SnakeNode* index = this->head;
    while(index != nullptr)
    {
        std::cout<<index->posX<<" "<<index->posY<<std::endl;
        index = index->next;
    }
}
