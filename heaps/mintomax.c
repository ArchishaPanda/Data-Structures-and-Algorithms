#include<stdio.h>

void swap(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void maxheapify(int* arr,int size,int i)
{
    int left=2*i+1;
    int right=2*i+2;

    if(left>size || right>size)
    {
        return;
    }

    int biggest=i;
    if(arr[left]>arr[i])
    biggest=left;

    if(arr[right]>arr[biggest])
    biggest=right;

    if(biggest!=i)
    {
        swap(&arr[biggest],&arr[i]);
        maxheapify(arr,size,biggest);
    }
}

void convertmaxheap(int *arr,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        maxheapify(arr,n,i);
    }
}

void printarray(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[] = { 9, -5, -3, -2, -1, 7, 6, -14 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // printf("Min Heap array : ");
    // printarray(arr, N);

    // Function call
    convertmaxheap(arr, N);

    printf("\nMax Heap array : ");
    printarray(arr, N);

    return 0;
}