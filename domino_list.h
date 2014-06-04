#ifndef DOMINO_LIST_H
#define DOMINO_LIST_H
#include <iostream>
#include "domino_node.h"
#include "domino.h"

class dominoList
{
    private:
        dominoNode* head;

    public:
        dominoList();

        dominoNode* getHead();
        void setHead(dominoNode*);

        void addDominoNode(dominoNode*);
        void printList();
        void clearList();

};

dominoList::dominoList()
{
    this->setHead( NULL );
}

void dominoList::clearList()
{
    while(this->getHead() != NULL )
    {
        dominoNode* tmpNode  = this->getHead();
        this->setHead( this->getHead()->getNext() );
        delete tmpNode->getDominoInfo();
        delete tmpNode;

        std::cout << "deleted domino";
    }
}

void dominoList::setHead(dominoNode * head)
{
    this->head = head;
}

dominoNode* dominoList::getHead()
{
    return this->head;
}


void dominoList::printList()
{
    dominoNode* tmpNode = this->getHead();
    while(tmpNode != NULL)
    {
        std::cout << "["
             << tmpNode->
                getDominoInfo()->getLeftSide()
             << ":"
             << tmpNode->getDominoInfo()->getRightSide()
             << "]"
             << std::endl;
        tmpNode = tmpNode->getNext();
    }
}


/**
 * @brief dominoList::addDominoNode
 *
 * insert sinlge domino at tail, pls notice that only one single domino will be added no list!
 *
 * @param newDominoNode
 */
void dominoList::addDominoNode(dominoNode* newDominoNode)
{

    if( this->getHead() == NULL)
    {
        this->setHead( newDominoNode );
        this->getHead()->setNext( NULL );
    }
    else
    {
        dominoNode* tmpNode = this->getHead();

        while(tmpNode->getNext() != NULL )
        {
            tmpNode = tmpNode->getNext();
        }

        tmpNode->setNext( newDominoNode );
        newDominoNode->setNext( NULL );
    }
}

#endif // DOMINO_LIST_H
