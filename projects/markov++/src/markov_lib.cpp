#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "markov_map.cpp"

using namespace std;

MarkovMap generateMarkovMap(string filename, int order)
{
    MarkovMap markovMap;
    ifstream myfile(filename);

    vector<string> words;
    string currWord;

    if(myfile.is_open())
    {
        /* Read word-by-word and put into the markov map */
        while(myfile >> currWord)
        {
            words.push_back(currWord);

            if(words.size() == order + 1)
            {
                string key = "";
                for(int i = 0; i < words.size() - 1; i++)
                {
                    key = key + words[i] + " ";
                }
                key = key.substr(0, key.length() - 1);
                
                markovMap[key][words[order]]++;
                
                words.erase(words.begin());
            }
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    return markovMap;
}