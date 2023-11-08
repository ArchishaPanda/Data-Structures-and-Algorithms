#include<stdio.h>
#include<stdlib.h>

enum Type{
    Legitimate,
    Empty,
    Deleted
};

struct stNode{
    int iElement;
    enum Type flag;
};
typedef struct stNode* Node;

struct stHT{
    Node pstart;
    int iTableSize;
    int NumberOfElements;
};
typedef struct stHT* HashTableOA;

HashTableOA CreateHashTable(int iTableSize)
{
    HashTableOA H=(HashTableOA)malloc(sizeof(struct stHT));
    if(H==NULL)
    {
        printf("Memory is full");
        exit(0);
    }
    H->iTableSize=iTableSize;
    H->NumberOfElements=0;
    H->pstart=(Node*)malloc(sizeof(Node)*iTableSize);
    if(H->pstart==NULL)
    {
        printf("Memeory is full");
        exit(0);
    }
    for(int i=0;i<iTableSize;i++)
    {
        H->pstart[i].flag=Empty;
        H->pstart[i].iElement=-1;
    }
    return H;
}

int GetHash(int n,HashTableOA H)
{
    int size=H->iTableSize;
    int key;
    key=n%size;
    return key;
}

HashTableOA Insert(HashTableOA H,int n)
{
    
   int key=GetHash(n,H);
   Node position=&H->pstart[key];
   int i,iIndex;

    if(H->NumberOfElements>=H->iTableSize/2)
    {
        HashTableOA H1=CreateHashTable(H->iTableSize*2);
        Insert(H1,n);
        for(int i=0;i<H->iTableSize;i++)
        {
            if(H->pstart[i].flag==Legitimate)
            {                
                Insert(H1,H->pstart[i].iElement);
            }
        }
        return H1;
    }
   for(i=0;i<H->iTableSize/2;i++)
   {
        if(position->flag==Empty || position->flag==Deleted)
        {
            position->iElement=n;
            position->flag=Legitimate;
            printf("Inserted %d\n",n);
            H->NumberOfElements++;
            return H;
        }
        else
        {
            iIndex=(key+i*i)%H->iTableSize;
            position=&H->pstart[iIndex];
        }
   }  

}

Node Find(HashTableOA H,int n)
{
    Node position=NULL;
    int i,iIndex;
    int k=GetHash(n,H);
    position=&H->pstart[k];

    for(int i=1;i<=H->iTableSize/2;i++)
    {
        if(position->flag==Empty)
        {
            return NULL;
        }
        if(position->flag==Legitimate && position->iElement==n)
        {
            return position;
        }
        else
        {
            iIndex=(k+i*i)%H->iTableSize;
            position=&H->pstart[iIndex];
        }
    }
    return position;
}

void PrintHashTable(HashTableOA H)
{
    for(int i=0;i<H->iTableSize;i++)
    {
        printf("%d\n",H->pstart[i].iElement);
    }
}

int main()
{
    HashTableOA H=CreateHashTable(5);
    H=Insert(H,5);
    H=Insert(H,13);
    H=Insert(H,23);
    H=Insert(H,33);
    H=Insert(H,43);
    PrintHashTable(H);

}
