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
