#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int GetPivotPosition(int *arr,int low,int high)
{
    int pivot=high;
    int i=low-1;
   for(int j=low;j<high;j++)
   {
    if(arr[j]<arr[pivot])
    {
        i++;
        swap(&arr[j],&arr[i]);
    }
   }
    swap(&arr[i+1],&arr[pivot]);
    return i+1;
}
void quicksort(int* arr,int low,int high)
{
    if(low<high)
    {
        int pi=GetPivotPosition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main()
{
    int arr[7]={5,1,4,3,7,2,6};
    quicksort(arr,0,6);
    for(int i=0;i<7;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}