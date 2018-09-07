/*
    @description    A linked-list node indicating a word and
                    it's frequency in some text
*/
typedef struct WordFreqLLNode
{
    char* word;
    int freq;
} WordFreqLLNode_t;

/*
    @description    A map from a word to a linked-list
                    of word frequencies of words
                    that follow word
*/
typedef struct WordPairMap
{
    char* word;
    WordFreqLLNode_t* head;
} WordPairMap_t;