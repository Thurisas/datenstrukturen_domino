#ifndef RING_LIST_H
#define RING_LIST_H

/**
 * @brief The ringList class
 *
 * A simplechained list of ring(list)s
 */
class ringList
{
    private:
        ringNode* head;

    public:
        ringList();
        void setHead(ringNode*);
        ringNode* getHead();
        void addRingNode(ringNode*);
        void clearList();
        void printList();

};

ringList::ringList()
{
    this->setHead(NULL);
}
void ringList::setHead(ringNode* head)
{
    this->head = head;
}
ringNode* ringList::getHead()
{
    return this->head;
}
void ringList::addRingNode(ringNode* newRingNode)
{
    if( this->getHead() == NULL)
    {
        this->setHead( newRingNode );
        this->getHead()->setNext( NULL );
    }
    else
    {
        ringNode* tmpNode = this->getHead();

        while(tmpNode->getNext() != NULL )
        {
            tmpNode = tmpNode->getNext();
        }

        tmpNode->setNext( newRingNode );
        newRingNode->setNext( NULL );
    }
}

void ringList::printList()
{
    ringNode* tmpNodeRing = this->getHead();
    while(tmpNodeRing != NULL)
    {
        dominoNode* tmpNodeDomino = tmpNodeRing->getHead();
        do
        {
            std::cout << "["
                << tmpNodeDomino->getDominoInfo()->getLeftSide()
                << ":"
                << tmpNodeDomino->getDominoInfo()->getRightSide()
                << "]  ";
            tmpNodeDomino = tmpNodeDomino->getNext();
        }
        while(tmpNodeDomino != tmpNodeRing->getHead());
      std::cout << std::endl;
      tmpNodeRing = tmpNodeRing->getNext();
    }
}

/**
 * @brief ringList::clearList
 *
 * destructs the hole list of ring(list)s with dominos, dominoNodes and ringNodes to release the memory
 *
 */

void ringList::clearList()
{
    while(this->getHead() != NULL )
    {
        ringNode* tmpRingNode  = this->getHead();
        this->setHead( tmpRingNode->getNext());

        dominoNode* tmpDominoNode = tmpRingNode->getHead()->getNext();
        while(tmpDominoNode->getNext() != tmpRingNode->getHead()) tmpDominoNode = tmpDominoNode->getNext();
        tmpDominoNode->setNext(NULL);


        while(tmpRingNode->getHead() != NULL )
        {
            dominoNode* tmpNode  = tmpRingNode->getHead();
            tmpRingNode->setHead( tmpRingNode->getHead()->getNext() );
            delete tmpNode->getDominoInfo();
            delete tmpNode;
        }

        delete tmpRingNode;
    }
}

#endif // RING_LIST_H
