#ifndef DOMINO_NODE_H
#define DOMINO_NODE_H

/**
 * @brief The dominoNode class
 *
 * A dominonode, with dominoInfo = domino(stone)
 */
class dominoNode
{
private:
    domino* dominoInfo;
    dominoNode* next;
public:
    dominoNode();
    void setNext(dominoNode*);
    dominoNode* getNext();
    void setDominoInfo(domino*);
    domino* getDominoInfo();
};



dominoNode::dominoNode()
{
    this->setNext(NULL);
    this->setDominoInfo(NULL);
}
void dominoNode::setDominoInfo(domino * dominoInfo)
{
    this->dominoInfo = dominoInfo;
}

domino* dominoNode::getDominoInfo()
{
    return this->dominoInfo;
}

void dominoNode::setNext(dominoNode * next)
{
    this->next = next;
}
dominoNode* dominoNode::getNext()
{
    return this->next;
}

#endif // DOMINO_NODE_H
