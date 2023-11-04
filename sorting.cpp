#include<bits/stdc++.h>

using namespace std;

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void swap(int *a,int *b)
{
    int temp;
    temp=*b;
    *b=*a;
    *a=temp;
}

void selectionSort(int arr[],int n)
{
    for(int i=0;i<n;i++){

    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={7,2,5,3,6,4};
    int n=6;


    printArray(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);


    return 0;
}
