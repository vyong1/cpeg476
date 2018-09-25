#include <iostream>
#include <unordered_map>
#include <iterator>
#include <string>
#include "markov_map.cpp"
#include "markov_lib.h"

using namespace std;

void playWithUnorderedMap();

int main(int argc, char** argv)
{
    if(!(argc == 2))
    {
        cout << "Expected 1 argument. Received " << argc - 1<< ". Exiting..." << endl;
        return 1;
    }

    /* Assume that argv[1] is a filename */
    myRead(argv[1]);
}

void playWithUnorderedMap()
{
    unordered_map<int, string> myMap;

    myMap[1] = "one";
    myMap[5] = "five";
    myMap[12] = "twelve";

    for( unordered_map<int, string>::iterator it = myMap.begin(); it != myMap.end(); it++ )
    {
        cout << it->first << " " << it->second << endl;
    }
}