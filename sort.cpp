#include<bits/stdc++.h>

using namespace std;

void insertionSort(int a[],int n)
{
    for(int i=0;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(arr[j]>key&&j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void binarysearch(int a[],int n,int key)
{
    int low=0,high=n-1;
}
