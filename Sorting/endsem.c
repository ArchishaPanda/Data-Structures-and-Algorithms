#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void SelectionSort(int* arr,int n)
{    
    for(int i=0;i<n;i++)
    {
        int minindex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        swap(&arr[minindex],&arr[i]);
    }
}
void merge(int* arr,int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;

    int L[n1];
    int R[n2];

    for(int i=0;i<n1;i++)
    {
        L[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i]=arr[i+mid+1];
    }

    int i=0;
    int j=0;
    int k=left;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            arr[k++]=L[i++];
        }
        else
        {
            arr[k++]=R[j++];
        }
    }

    while(i<n1)
    {
        arr[k++]=L[i++];
    }
    while(j<n2)
    {
        arr[k++]=R[j++];
    }
}
void mergesortdriver(int *arr,int left,int right)
{
    if(left<right)
{
    int mid=(left+right)/2;
    mergesortdriver(arr,left,mid);
    mergesortdriver(arr,mid+1,right);
    merge(arr,left,mid,right);
}
}
void heapify(int* arr,int size,int index)
{
    int left=2*index+1;
    int right=2*index+2;
    int largest=index;

    if(left<size && arr[left]>arr[right])
    largest=left;

    if(right<size && arr[right]>arr[largest])
    largest=right;

    if(largest!=index)
    {
        swap(&arr[largest],&arr[index]);
        heapify(arr,size,largest);
    }
}
void heapsort(int* arr,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void countsort(int* arr,int n)
{
    int* freq=(int*)calloc(5,sizeof(int));
    int cfreq[n];
    int new[n];

    for(int i=0;i<n;i++)
    {
        freq[arr[i]]=freq[arr[i]]+1;
    }
    for(int i=1;i<n;i++)
    {
        cfreq[i]=cfreq[i-1]+freq[i];
    }

    for(int i=0;i<n;i++)
    {
        cfreq[arr[i]]--;
        freq[arr[i]]--;
        new[cfreq[i]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",freq[i]);
    }
    printf("\n");
}
void insertion(int* arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int cur=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>cur)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=cur;
    }
}
int main()
{
    int arr[5]={1,4,2,3,0};
    insertion(arr,5);
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
}