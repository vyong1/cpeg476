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

    string filename = argv[1];
    int order = stoi(argv[2]);

    srand(time(NULL));

    MarkovMap markovMap = generateMarkovMap(filename, order);

    // markovMap.print();

    string tweet = markovMap.generateTweet(TWEET_CHAR_LIMIT, order);
    cout << tweet << endl;
}