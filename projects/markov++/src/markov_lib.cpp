#include <iostream>
#include <fstream>
#include <string>
#include "markov_map.cpp"

using namespace std;

MarkovMap generateMarkovMap(string filename)
{
    MarkovMap markovMap;

    string prevWord;
    string currWord;
    ifstream myfile(filename);

    if(myfile.is_open())
    {
        /* Read word-by-word and put into the markov map */
        while(myfile >> currWord)
        {
            if(prevWord != "")
            {
                markovMap[prevWord][currWord]++;
            }

            prevWord = currWord;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    return markovMap;
}