#include <iostream>
#include <unordered_map>
#include <iterator>
#include <vector>
#include <string>

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
            return it->first;
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

        string generateTweet(int charLimit)
        {
            vector<string> tweetWords;
            string s = "";

            /* Generate some seed data */
            tweetWords.push_back((*this).getRandomWord());

            /* Build up the tweet */
            int i = 0;
            while((s + tweetWords[i] + " ").length() < charLimit)
            {
                tweetWords.push_back((*this).getNextWord(tweetWords[i]));
                s = s + tweetWords[i] + " ";
                i++;
            }
            return s;
        }
};