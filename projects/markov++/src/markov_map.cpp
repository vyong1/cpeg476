#include <iostream>
#include <unordered_map>
#include <iterator>
#include <string>

using namespace std;

/*

Maps from a word to the proceeding words and their frequency
[Word] = <ProceedingWord, Frequency>

*/
class MarkovMap : public unordered_map<string, unordered_map<string, int>>
{
    public:
        void add(string word, string proceedingWord)
        {

        }

        bool containsKey(string key)
        {
            if (this->find(key) == this->end())
            {
                return false;
            }

            return true;
        }

        bool containsKey(string word, string proceedingWord)
        {
            /* Check if the word exists */
            if (this->containsKey(word) == false)
            {
                return false;
            }

            /* Check if the proceeding word exists */
            if ((*this)[word].find(proceedingWord) == (*this)[word].end())
            {
                return false;
            }

            return true;
        }
};