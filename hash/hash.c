#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

struct stNode{
    int iElement;
    struct stNode* pnext;
};
struct stHT{
    int iTableSize;
    struct stNode** pstart;
};

typedef struct stNode* Node;
typedef struct stHT* HashTable;

HashTable CreateHashTable(int iTableSize)
{
    HashTable H=(HashTable)malloc(sizeof(struct stHT));
    assert(H!=NULL);
    H->iTableSize=iTableSize;
    H->pstart=(Node*)malloc(sizeof(Node)*iTableSize);

    for(int i=0;i<iTableSize;i++)
    {
        H->pstart[i]=(Node)malloc(sizeof(struct stNode));
        assert(H->pstart[i]!=NULL);
        H->pstart[i]->iElement=-5555;
        H->pstart[i]->pnext=NULL;
    }
    return H;
}

int GetHash(int n,int s) //Hash is value in bucket or category that the number lies in
{
    int key;
    key=n%s; //f(x)=x%s  best case when s is a prime number 31 is most common(overused)
    return key;
}

HashTable InsertInHashTable(HashTable H,int element)
{
    int key=GetHash(element,10);
    Node newnode=(Node)malloc(sizeof(struct stNode));
    newnode->iElement=element;
    newnode->pnext=H->pstart[key]->pnext;
    H->pstart[key]->pnext=newnode;
    printf("%d inserted successfully\n",element);
    return H;
}

void PrintHashTable(HashTable H)
{
    for(int i=0;i<H->iTableSize;i++)
    {
        if(H->pstart[i]->pnext!=NULL)
        {
            Node ptr=H->pstart[i]->pnext;
            printf("Bucket %d: ",i);
            while(ptr!=NULL)
            {
                printf("%d ",ptr->iElement);
                ptr=ptr->pnext;
            }
            printf("\n");
        }
        else
        {
            printf("Bucket %d : Empty\n",i);
        }
    }
}

int main()
{
    HashTable H=CreateHashTable(40);
    for(int j=0;j<20;j++)
    {
        // H=InsertInHashTable(H,1);
        // H=InsertInHashTable(H,62);
        // H=InsertInHashTable(H,93);
        // H=InsertInHashTable(H,15);
        H=InsertInHashTable(H,j);
    }
    PrintHashTable(H);
}


