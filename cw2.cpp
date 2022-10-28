#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int v){
    int start = 0;
    int end = n-1;

    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == v)return mid;
        else if(arr[mid]>v)end = mid-1;
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter the size of the Array: ";
    cin >>  n;
    cout << "Enter the Array values: ";
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    
    sort(arr,arr+n);

    int v;
    cout << "Enter value of V: ";
    cin >> v;
    int p = binarySearch(arr,n,v);
    int count=0,vCount=0;
    for(int i=p; i<n; i++){
        if(arr[i]%2==0 && arr[i]!=v)count++;
        if(arr[i] == v)vCount++;
    }

    cout <<  " Greater even number of "<< v << " are " << count << " times" << endl;
    cout << "Number of V's are in the array: " << vCount << endl << "And their indexes are: ";
    for(int i=p; i<n; i++){
        if(arr[i] == v)cout << i << " ";
    }
}