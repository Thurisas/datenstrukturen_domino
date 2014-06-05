#ifndef RING_NODE_H
#define RING_NODE_H

/**
 * @brief The ringList class
 *
 * A ring(list) of sorted dominos
 */

class ringNode
{
    private:

        dominoNode* head ;    //information of this node = one ring of sorted dominos
        ringNode* next;

    public:
        ringNode();
        void setHead(dominoNode*);
        dominoNode* getHead();    //getHead()<=>getInfo()

        void setNext(ringNode*);
        ringNode* getNext();

        bool buildRing(dominoList*);
        void printList();
};

ringNode::ringNode()
{
    this->setHead(NULL);
    this->setNext(NULL);
}

void ringNode::setHead(dominoNode* head)
{
    this->head = head;
}

dominoNode* ringNode::getHead()
{
    return this->head;
}

void ringNode::setNext(ringNode* next)
{
    this->next = next;
}

ringNode* ringNode::getNext()
{
    return this->next;
}

bool ringNode::buildRing(dominoList* myDominoList)
{

    if( myDominoList->getHead() == NULL) return false;

    else
    {
        dominoNode* tmpNode = myDominoList->getHead();
        myDominoList->deleteNode(tmpNode);
        setHead(tmpNode);
        tmpNode->setNext(NULL);
        int saveLeftSide = tmpNode->getDominoInfo()->getLeftSide();
        int rightSide = tmpNode->dominoNode::getDominoInfo()->getRightSide();
        while(saveLeftSide!=rightSide)
        {


            tmpNode->setNext(myDominoList->searchDominoNode(rightSide));
            myDominoList->deleteNode(tmpNode->getNext());
            tmpNode->getNext()->setNext(getHead());
            tmpNode = tmpNode->getNext();
            rightSide = tmpNode->getDominoInfo()->getRightSide();
        }
        return true;
    }
}


#endif // RING_NODE_H
