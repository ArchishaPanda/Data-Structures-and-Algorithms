#include<stdio.h>
#include<stdlib.h>
void swap(int*a,int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void PercDown(int* arr,int n,int i)
{
    int w=2*i+1;
    if(w>=n)
    return;

    while(w<n)
    {
        if(w+1>=n)
        return;
        if(w+1<n)
        {
            if(arr[w+1]>arr[w])
            w=w+1;

            if(arr[i]>arr[w])
            return;
            
            swap(&arr[i],&arr[w]);
            i=w;
            w=2*i+1;
        }
    }
}

void heapsort(int* arr,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        PercDown(arr,n,i);
    }

    for(int i=n-1;i>=0;i--)
    {
        if(arr[0]>arr[i])
        swap(&arr[i],&arr[0]);
        PercDown(arr,i,0);
    }
}
int main()
{
    int arr[]={38,27,3,43,9,82,10};
    heapsort(arr,7);
    for(int i=0;i<7;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}