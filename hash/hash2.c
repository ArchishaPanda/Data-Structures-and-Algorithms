//Q2

//Hash a string

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<string.h>

struct stNode{
    char* str;
    struct stNode* pnext;
};
struct stHT{
    int iTableSize;
    struct stNode** pstart;
};

typedef struct stNode* Node;
typedef struct stHT* HashTable;

int power(int a,int b)
{
    int product=1;
    for(int k=0;k<b;k++)
    {
        product=product*a;
    }
    return product;
}

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
        H->pstart[i]->str="0";
        H->pstart[i]->pnext=NULL;
    }
    return H;
}

int GetHash(char* str,int p) //Hash is value in bucket or category that the number lies in
{
    int key=0;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        key=key+((str[i]-'a'+1)*power(p,i));
        printf("%d\n",power(p,i));
    }

    return key;
}
HashTable InsertInHashTable(HashTable H,char* str)
{
    int key=GetHash(str,2);
    Node newnode=(Node)malloc(sizeof(struct stNode));
    newnode->str=str;
    newnode->pnext=NULL;

    if(H->pstart[key]->pnext==NULL)
    {
        H->pstart[key]->pnext=newnode;
    }
    else
    {
        newnode->pnext=H->pstart[key]->pnext;
        H->pstart[key]->pnext=newnode;
    }
    printf("Inserted %s",str);
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
                printf("%s ",ptr->str);
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
    HashTable H=CreateHashTable(100);
    H=InsertInHashTable(H,"abc");
    H=InsertInHashTable(H,"def");
    PrintHashTable(H);

}