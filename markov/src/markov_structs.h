/*
    @description    A linked-list node indicating a word and
                    it's frequency in some text
*/
typedef struct WordFreqNode
{

    struct WordFreqNode* next;
    char* word;
    int freq;

} WordFreqNode_t;


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
    WordFreqNode_t* head;

} MarkovNode_t;

// ==== Prints
void printWordFreqNode(WordFreqNode_t* node);
void printWordFreqList(WordFreqNode_t* head);
void printMarkovNode(MarkovNode_t* head);

// ==== Frees
void freeWordFreqLLNode(WordFreqNode_t* node);
void freeWordFreqList(WordFreqNode_t* node);
void freeMarkovNode(MarkovNode_t* node);

// ==== Constructors
WordFreqNode_t* newWordFreqNode(WordFreqNode_t* next, char* word, int freq);
MarkovNode_t* newMarkovNode(char* word, int totalPairs, WordFreqNode_t* head);

// ==== Append
void append(WordFreqNode_t* head);