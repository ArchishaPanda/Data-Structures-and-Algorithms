#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int BinarySearch(int a[], int item,int low, int high)
{
    if (high <= low)
    {   
        if(item > a[low]) 
            return (low + 1);
        else 
            return low;
    }
 
    int mid = (low + high) / 2;
 
    if (item == a[mid])
        return mid + 1;
 
    if (item > a[mid])
        return BinarySearch(a, item, mid + 1, high);
    return BinarySearch(a, item, low,mid - 1);
}
void InsertionSortIterative(int* arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            swap(&arr[j],&arr[j-1]);
            j--;
        }
    }
}

void InsertionSortRecursive(int *arr,int n)
{
    if(n==0)
    return;

    if(n==1)
    return;

    InsertionSortRecursive(arr,n-1);
    int j=n-1;
    while(j>0 && arr[j]<arr[j-1])
    {
        swap(&arr[j],&arr[j-1]);
        j--;
    }

}

void BinaryInsertionSort(int* a,int n)
{
    //We do binary search to reduce the number of comparisions done to find right position to insert the element
     int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
 
        // find location where selected should be inserted
        loc = BinarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
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
    int arr[7]={7,6,5,4,3,2,1};
    BinaryInsertionSort(arr,7);
    PrintArray(arr,7);
}