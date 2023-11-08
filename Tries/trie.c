#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode *Trie;
typedef struct TrieNode
{
    Trie children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

Trie Insert(Trie T, char *word, int length);
Trie CreateNode(char *word, int length);
bool Search(Trie T, char *word, int length);
void PrintTrie(Trie T);
Trie DeleteNode(Trie T, char *word, int length);
Trie DelRec(Trie T, char *word, int length);
bool PrefixFinder(Trie T, char *word, int length);
void autocomplete(Trie T, char *word, int length);



void autocomplete(Trie T, char *word, int length)
{
    Trie traveller = T;
    for (int i = 0; i < length; i++)
    {
        int index = word[i] - 'a';
        if (traveller->children[index] == NULL)
            return;
        traveller = traveller->children[index];
    }
    printall(traveller);
}

char** printall(Trie T)
{
    if(T == NULL)
        return;
    
    Trie traveller = T;
    for(int i=0; i<ALPHABET_SIZE; i++)
    {
        if(traveller->children[i] != NULL)
        {
            if(traveller->isEndOfWord)
            {
                
            }
        }
    }
}

bool PrefixFinder(Trie T, char *word, int length)
{
    Trie traveller = T;
    // printf("%s\n", word);
    for (int i = 0; i < length; i++)
    {
        int index = word[i] - 'a';
        if (traveller->children[index] == NULL)
            return false;
        traveller = traveller->children[index];
    }
    return true;
}

Trie DeleteNode(Trie T, char *word, int length)
{
    Trie traveller = T;
    for (int i = 0; i < length; i++)
    {
        int index = word[i] - 'a';
        if (traveller->children[index] == NULL)
            return T;
        traveller = traveller->children[index];
    }
    traveller->isEndOfWord = false;

    DelRec(T, word, length);

    return T;
}

Trie DelRec(Trie T, char *word, int length)
{
    if (T == NULL || length == 0)
        return T;
    Trie traveller = T;
    int index = word[0] - 'a';
    if (traveller->children[index] == NULL)
        return T;
    DelRec(T->children[index], word + 1, length - 1);
    free(T->children[index]);
    T->children[index] = NULL;

    return T;
}

void PrintTrie(Trie T)
{
    if (T == NULL)
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (T->children[i] != NULL)
        {
            printf("%c ", 96 + i);
            PrintTrie(T->children[i]);
        }
    }
}

Trie CreateNode(char *word, int length)
{
    Trie T = (Trie)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++)
        T->children[i] = NULL;
    T->isEndOfWord = false;

    return T;
}

Trie Insert(Trie T, char *word, int length)
{
    Trie traveller = T;
    for (int i = 0; i < length; i++)
    {
        int index = word[i] - 'a';
        if (traveller->children[index] == NULL)
            traveller->children[index] = CreateNode(word, i + 1);
        traveller = traveller->children[index];
    }
    traveller->isEndOfWord = true;
    return T;
}

bool Search(Trie T, char *word, int length)
{
    Trie traveller = T;
    for (int i = 0; i < length; i++)
    {
        int index = word[i] - 'a';
        if (traveller->children[index] == NULL)
            return false;
        traveller = traveller->children[index];
    }
    if (traveller != NULL && traveller->isEndOfWord == true)
        return true;
}

int main()
{
    Trie T = CreateNode("", 0);
    // T = Insert(T, "ant", 3);
    // T = Insert(T, "and", 3);
    // bool a = Search(T, "ant", 3);
    // bool b = Search(T, "baa", 3);

    // printf("%d ", a);
    // printf("%d\n", b);

    // DeleteNode(T, "ant", 3);

    // a = Search(T, "ant", 3);
    // printf("%d\n", a);

    int num;
    scanf("%d", &num);
    char word[1000];

    for (int loop = 0; loop < num; loop++)
    {
        scanf("%s", word);

        T = Insert(T, word, strlen(word));
    }

    // bool a = Search(T, "aa", 1);
    // printf("%d\n", a);
    // T = DeleteNode(T, "aa", 1);
    // a = Search(T, "aa", 1);
    // printf("%d\n", a);

    scanf("%s", word);
    bool a = PrefixFinder(T, word, strlen(word));
    printf("%d\n", a);

    return 0;
}