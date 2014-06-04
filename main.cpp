#include <fstream>
#include <iostream>

using namespace std;

void readFile( char* filename[] )
{
    ifstream datei;
    datei.open(filename[1], ios_base::in);
}

int main( int argc, char *argv[] )
{
    cout << "Datei" << argv[1] << "wird eingelesen"<< endl;


    //TODO: read domino stones
    //TODO: ... and store to simplechained list



}
