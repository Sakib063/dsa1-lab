#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

void sp(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sortArray(int a[],int n)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                sp(&a[i],&a[j]);
            }
        }
    }
}

bool binarySearchRecursion(int a[],int high,int low,int key)
{
    int mid=high+low/2;
    if(a[mid]==key)return true;
    else if(a[mid]>key){
        bool f=binarySearchRecursion(a,mid-1,low,key);
        return f;
    }
    else if(a[mid]<key){
        bool f=binarySearchRecursion(a,high,mid+1,key);
        return f;
    }
    return false;
}


int main()
{
    int arr[]={1,3,-3,6,-9,-7};
    int n=sizeof(arr)/sizeof(arr[0]);
    sortArray(arr,n);
    //printArray(arr,n);
    int key=5;
    bool fnd=binarySearchRecursion(arr,n-1,0,key);
    if(fnd==false){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found"<<endl;
    }

}
