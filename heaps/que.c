//build max-heap
#include<stdio.h>
#include<stdlib.h>

struct stheap{
    int iCapacity;
    int iSize;
    int *arr;
};
typedef struct stheap* Heap;

void swap(int *a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

Heap CreateHeap(int capacity)
{
    Heap H=(Heap)malloc(sizeof(struct stheap));
    H->iCapacity=capacity;
    H->iSize=0;
    H->arr=(int*)malloc(sizeof(int)*capacity);
    return H;
}

void heapify(Heap H,int i,int size)
{
    int left=2*i+1;
    int right=2*i+2;

    if(left>size || right>size)
    return;

    int biggest=i;
    if(H->arr[left]>H->arr[i])
    biggest=left;

    if(H->arr[right]>H->arr[biggest])
    biggest=right;

    if(biggest!=i)
    {
        swap(&H->arr[biggest],&H->arr[i]);
        heapify(H,biggest,H->iSize);
    }
}

void printHeap(Heap H)
{
    for(int i=0;i<H->iSize;i++)
    {
        printf("%d ",H->arr[i]);
    }
}

void heapsort(Heap H)
{
    for(int i=2;i>=0;i--)
    {
        heapify(H,i,H->iSize);
    }
    for(int i=H->iSize-1;i>=0;i--)
    {
        swap(&H->arr[0],&H->arr[i]);
        heapify(H,0,i);
    }  
    
}


int main()
{
    Heap H=CreateHeap(6);
    H->iSize=6;
    H->arr[0]=10;
    H->arr[1]=20;
    H->arr[2]=15;
    H->arr[3]=17;
    H->arr[4]=9;
    H->arr[5]=21;
    
    heapsort(H);
    printHeap(H);
}