/*
    @description    A linked-list node indicating a word and
                    it's frequency in some text
*/
typedef struct wordFreqLLNode
{
    char* word;
    int freq;
} wordFreqLLNode_t;

/*
    @description    A map from a word to a linked-list
                    of word frequencies of words
                    that follow word
*/
typedef struct wordPairMap
{
    char* word;
    wordFreqLLNode_t* head;
} wordPairMap_t;