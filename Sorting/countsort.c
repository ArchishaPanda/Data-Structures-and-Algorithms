#include<stdio.h>
#include<stdlib.h>

void PrintArray(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void countsort(int* arr,int size,int max)
{
    int freq[max+1];
    int cum[max+1];
    cum[0]=freq[0];
    int* ans=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<=max;i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        freq[arr[i]]++;
    }
    
    for(int i=1;i<=max;i++)
    {
        cum[i]=cum[i-1]+freq[i];
    }
    for(int i=0;i<size;i++)
    {
        int a=cum[arr[i]]--;
        ans[a-1]=arr[i];
    }
    PrintArray(ans,size);
}

int main()
{
    int arr[]={9,1,5,2,4,8,3,6};
    countsort(arr,8,9);
}