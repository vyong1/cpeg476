#include <iostream>
#include <fstream>

using namespace std;

void myRead(string filename)
{
    ofstream myfile;
    myfile.open (filename);
    myfile << "Writing this to a file.\n";
    myfile.close();
}