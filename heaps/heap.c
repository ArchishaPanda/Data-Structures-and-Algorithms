#include<stdio.h>
#include<stdlib.h>

struct stHeap{
    long int iSize;
    long int iCapacity;
    long long int* pElements;
};
typedef struct stHeap* heap;

void swap(long long int *a,long long int*b)
{
    long long int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

heap CreateHeap(long long int capacity)
{
    heap H=(heap)malloc(sizeof(struct stHeap));
    H->iCapacity=capacity;
    H->iSize=0;
    H->pElements=(long long int *)calloc(capacity,sizeof(int));
    return H;
}

void Insert(int n,heap H)
{
    long int last=H->iSize;
    if(last==H->iCapacity)
    {
        printf("Heap is full\n");
        return;
    }
    H->iSize++;
    H->pElements[last]=n;
    long int i=last;
    long long int temp;
    while(H->pElements[(i-1)/2]<H->pElements[i])
    {
        temp=H->pElements[(i-1)/2];
        H->pElements[(i-1)/2]=H->pElements[i];
        H->pElements[i]=temp;
        i=(i-1)/2;
    }
}

void minheapify(heap H,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    if(left>H->iSize || right>H->iSize)
    return;
    int smallest=i;
    if(H->pElements[left]<H->pElements[i])
    {
        smallest=left;
    }
     if(H->pElements[right]<H->pElements[smallest])
    {
        smallest=right;
    }
    if(smallest!=i)
    {
        int temp=H->pElements[i];
        H->pElements[i]=H->pElements[smallest];
        H->pElements[smallest]=temp;
        minheapify(H,smallest);
    }
}

void extractmin(heap H)
{
    if(H->iSize==0)
    {
        printf("Empty heap\n");
        return;
    }
    if(H->iSize==1)
    {
        H->iSize--;
        return;
    }
    int t=H->pElements[0];
    H->pElements[0]=H->pElements[H->iSize-1];
    H->iSize=H->iSize-1;
    minheapify(H,0);
}

void decreasekey(heap H,int i,int newvalue)
{
    H->pElements[i]=newvalue;
    while(H->pElements[(i-1)/2]>H->pElements[i])
    {
        swap(&H->pElements[(i-1)/2],&H->pElements[i/2]);
        i=(i-1)/2;
    }
}

int getmin(heap H)
{
    return H->pElements[0];
}

void deletekey(heap H,int i)
{
    decreasekey(H,i,-1);
    extractmin(H);
}

int main()
{
    heap H=CreateHeap(6);
    Insert(6,H);
    Insert(5,H);
    Insert(4,H);
    Insert(3,H);
    Insert(2,H);
    Insert(1,H);
    for(int i=0;i<6;i++)
    {
        printf("%d ",H->pElements[i]);
    }

}