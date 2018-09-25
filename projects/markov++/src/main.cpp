#include <iostream>
#include <unordered_map>
#include <iterator>
#include <string>
#include <time.h>
#include "markov_map.cpp"
#include "markov_lib.h"

#define TWEET_CHAR_LIMIT 280

using namespace std;

int main(int argc, char** argv)
{
    if(!(argc == 3) || argv[1] == "-h")
    {
        cout << "Usage: ./markov.out <filename> <markov order>" << endl;
        return 1;
    }

    srand(time(NULL));

    /* Assume that argv[1] is a filename, and read it into a markov map */
    MarkovMap markovMap = generateMarkovMap(argv[1], stoi(argv[2]));

    // markovMap.print();

    string tweet = markovMap.generateTweet(TWEET_CHAR_LIMIT);
    cout << tweet << endl;
}