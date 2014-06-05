#ifndef DOMINO_LIST_H
#define DOMINO_LIST_H
#include <iostream>


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
        void deleteNode(dominoNode*);
        dominoNode* searchDominoNode(int);

};

dominoList::dominoList()
{
    this->setHead( NULL );
}

dominoNode* dominoList::searchDominoNode(int z)
{
    dominoNode* tmp = getHead();
    while(tmp != NULL)
    {
        if(tmp->getDominoInfo()->getLeftSide() == z) return tmp;
        else if(tmp->getDominoInfo()->getRightSide() == z)
        {
            tmp->getDominoInfo()->swap();
            return tmp;
        }
        tmp = tmp->getNext();
    }
    return NULL;
}

void dominoList::deleteNode(dominoNode* node)
{
    dominoNode* tmp = getHead();
    if(tmp != NULL)
    {
        if(tmp==node) setHead(tmp->getNext());
        else
        {
            while(tmp->getNext() != node && tmp != NULL )
            {
                tmp = tmp->getNext();
            }
            if(tmp != NULL)
            {
                tmp->setNext(tmp->getNext()->getNext());
            }
        }
    }
}

void dominoList::clearList()
{
    while(this->getHead() != NULL )
    {
        dominoNode* tmpNode  = this->getHead();
        this->setHead( this->getHead()->getNext() );
        delete tmpNode->getDominoInfo();
        delete tmpNode;
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
             << "]  ";
             tmpNode = tmpNode->getNext();
    }
    std::cout << std::endl;
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
