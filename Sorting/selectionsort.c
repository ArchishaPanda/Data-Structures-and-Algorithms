#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void SelectionSort(int* arr,int n)
{
    
    int minindex;
    for(int i=0;i<n;i++)
    {
        int min=100000;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<=min)
            {
                min=arr[j];
                minindex=j;
            }
        }
        swap(&arr[i],&arr[minindex]);
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
    SelectionSort(arr,7);
    PrintArray(arr,7);
}