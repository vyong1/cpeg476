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
    @description    A node in a markov chain
*/
typedef struct MarkovNode
{

    // The word associated with the node
    char* word;
    // Represents the sum of the frequencies in the
    // linked list in this struct
    int totalPairs;
    // The head to a linked list of word frequencies
    WordFreqLLNode_t* head;

} MarkovNode_t;