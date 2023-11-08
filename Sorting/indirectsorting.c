#include<stdio.h>

int* indirect_sort(int* arr, int size){
     int* P[size];
     for(int i=0; i<size; i++){
          P[i] = &arr[i];
     }

     for(int i=0; i<size; i++){
          int j=i;
          while(j!=0 && *P[j] < *P[j-1]){
               int* temp = P[j];
               P[j] = P[j-1];
               P[j-1] = temp;
               j--;
          }
     }

     for(int i=0; i<size; i++){
          if(P[i] == &arr[i]){
               continue;
          }
          int temp = arr[i];
          int next_j;
          int j=i;
          int x;
          while(P[j]!=&arr[j]){
               arr[j] = *P[j];
               next_j = P[j] - &arr[0];                // gets the next address to work on
               P[j]=&arr[j];                           // update the p[j] to &arr[j]
               
               x=j;
               j=next_j;
          }    
          *P[x] = temp;
          P[x] = &arr[x];
     }
     return arr;
}

int main(){
     int arr[10] = {10,3,52,8,-1,4,9,70,81, 800};
     // int arr[3] = {50,30,40};
     int* Arr = indirect_sort(arr, 10);
     for(int i=0; i<10; i++){
          printf("%d ", arr[i]);
     }
     printf("\n");

}