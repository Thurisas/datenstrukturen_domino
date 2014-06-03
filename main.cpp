#include <fstream>
#include <iostream>
 void ReadFile(char* filename[])
{
    ifstream datei;
    datei.open(filename[1], ios_base::in);

}
using namespace std;
int main(int argc, char *argv[])
{
    cout << "Datei" << argv[1] << "wird eingelesen"<< endl;


}
