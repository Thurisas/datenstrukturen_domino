#ifndef DOMINO_LIST_H
#define DOMINO_LIST_H

class DominoList
{
    private:
        DominoNode* head;

    public:
        setDominoList()
        {
            this->head = NULL;
        }

        addDomino(int LeftSide, int RightSide)
        {
            DominoNode* tmp = new DominoNode;

            if(this->head==NULL)
            {
                this->head = tmp;
                this->next = NULL;
            }
            else
            {
                do
                {
                    this->head = this->next;
                }
                while(this->next!=NULL)
                this->next = tmp;

            }
        }
}



#endif // DOMINO_LIST_H
