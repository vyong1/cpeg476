#include <iostream>
#include <unordered_map>
#include <iterator>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

/*

Maps from a word to the proceeding words and their frequency
[Word] = <ProceedingWord, Frequency>

*/
class MarkovMap : public unordered_map<string, unordered_map<string, int>>
{
    public:
        void print()
        {
            for( auto it = (*this).begin(); it != (*this).end(); it++ )
            {
                cout << "{" << it->first << "} => ";
                unordered_map<string, int> proceedingMap = (it->second);

                for( auto it2 = proceedingMap.begin(); it2 != proceedingMap.end(); it2++ )
                {
                    cout << "[" << it2->first << " | " << it2->second << "]->";
                }
                cout << endl;
            }
        }

        string getRandomWord()
        {
            auto it = (*this).begin();
            advance(it, rand()%(*this).size());
            string word = it->first;
            return word.substr(0, word.find(" "));
        }

        string getNextWord(string currentWord)
        {
            int total = 0;
            unordered_map<string, int> proceedingMap = (*this)[currentWord];

            for (auto it = proceedingMap.begin(); it != proceedingMap.end(); it++)
            {
                total = total + it->second;
            }

            // Return a random word if there are no instances of any proceeding words
            if(total == 0)
            {
                return (*this).getRandomWord();
            }

            int selected = rand()%(total) + 1;
            int freqSum = 0;

            for (auto it = proceedingMap.begin(); it != proceedingMap.end(); it++)
            {
                freqSum = freqSum + it->second;

                if(selected == freqSum || freqSum > selected)
                {
                    return it->first;
                }
            }
            
            // At the last node, assume it's the word chosen
            return proceedingMap.end()->first;
        }

        string generateTweet(int charLimit, int order)
        {
            vector<string> tweetWords;
            string s = "";

            /* Generate some seed data */
            for(int i = 0; i < order + 1; i++)
            {
                tweetWords.push_back((*this).getRandomWord());
                s = s + tweetWords[i] + " ";
            }

            /* Build up the tweet */
            int i = order;
            while((s + tweetWords[i] + " ").length() < charLimit)
            {
                string key = "";
                for(int j = i - order; j < i; j++)
                {
                    key = key + tweetWords[j] + " ";
                }
                key = key.substr(0, key.length() - 1);

                tweetWords.push_back((*this).getNextWord(key));

                s = s + tweetWords[i] + " ";
                i++;
            }
            return s;
        }
};