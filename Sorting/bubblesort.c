#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void bubblesortrecursive(int* arr,int n)
{
    int sorted=1;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(&arr[i],&arr[i+1]);
            sorted=0;
        }
    }
    if(sorted==0)
    {
        bubblesortrecursive(arr,n);
    }
}

void PrintArray(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[7]={4,3,6,1,5,2,7};
    bubblesortrecursive(arr,7);
    PrintArray(arr,7);
}
