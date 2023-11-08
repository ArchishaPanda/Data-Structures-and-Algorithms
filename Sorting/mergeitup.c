#include<stdio.h>
#include<stdlib.h>

void merge(int* arr,int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;

    int L[n1];
    int R[n2];

    for(int i=0;i<n1;i++)
    {
        L[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=arr[mid+j+1];
    }

    int i=0;
    int j=0;
    int k=low;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=R[j];
            j++;
            k++;
        }
    }

    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        k++;
        j++;
    }
}
void mergesort(int* arr,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;

        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    int arr[]={38,27,3,43,9,82,10};
    mergesort(arr,0,6);
    for(int i=0;i<7;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}