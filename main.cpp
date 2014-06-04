#include <fstream>
#include <iostream>

#include "domino.h"
#include "domino_node.h"
#include "domino_list.h"
#include "ring.h"
#include "ring_list.h"

using namespace std;

int main(int argc, char *argv[])
{
    if ( argc == 2 ) {
                cout << "Datei " << argv[1] << " wird eingelesen"<< endl;


        char* filename = argv[1];
        int numberOfDominos = 0;

        dominoNode* tmpNode = NULL;

        domino* tmpDomino = NULL;
        int tmpLeftSide = -1;
        int tmpRightSide = -1;

        dominoList* myDominoList = new dominoList;

        ifstream dominoInpute( filename );

        if( dominoInpute.is_open())
        {
            dominoInpute >> numberOfDominos;

            for( int i = numberOfDominos; i > 0; i--)
            {
                tmpDomino = new domino;

                dominoInpute >> tmpLeftSide;
                dominoInpute >> tmpRightSide;

                tmpDomino->setLeftSide(tmpLeftSide);
                tmpDomino->setRightSide(tmpRightSide);

                tmpNode = new dominoNode;
                tmpNode->setDominoInfo(tmpDomino);

                myDominoList->addDominoNode(tmpNode);

            }
            dominoInpute.close();

            myDominoList->printList();



            myDominoList->clearList();
        }
        else
        {
            cout << "Unable to open file";
            return 1;
        }

    } else {
        cout << "Wrong number of parameters given" << endl;
        return 1;
    }

    return 0;
}




