#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void ShellSort(int* arr,int n)
{
    int gap=n/2;
    while(gap>=1)
    {
        for(int i=gap;i<n;i++)
        {
            int temp=arr[i];
            int j;
            for(j=i;j>=gap && arr[j]<arr[j-gap];j=j-gap)
            {
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
        gap=gap/2;
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
    int arr[5]={12,34,54,2,3};
    ShellSort(arr,5);
    PrintArray(arr,5);
}