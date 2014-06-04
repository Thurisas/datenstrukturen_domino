#ifndef DOMINO_H
#define DOMINO_H

/**
 * @brief The domino class
 *
 * A domino (stone)
 */
class domino
{
    private:
        int leftSide;
        int rightSide;



    public:
        domino();
        void setLeftSide(int);
        void setRightSide(int);
        int getLeftSide();
        int getRightSide();

        void swap();
        void setDomino(int, int);

};

domino::domino()
{
    this->setLeftSide(-1);
    this->setRightSide(-1);
}
int domino::getLeftSide()
{
    return this->leftSide;
}
int domino::getRightSide()
{
    return this->rightSide;
}
void domino::setLeftSide(int leftSide)
{
    this->leftSide = leftSide;
}
void domino::setRightSide(int rightSide)
{
    this->rightSide = rightSide;
}
void domino::setDomino(int leftSide, int rightSide)
{
    this->setLeftSide(leftSide);
    this->setRightSide(rightSide);
}
void domino::swap()
{
    int tmp = this->getLeftSide();
    this->setLeftSide(this->getRightSide());
    this->setRightSide(tmp);
}


#endif // DOMINO_H


