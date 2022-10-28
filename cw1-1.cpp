#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findIndex(int array[], int n, int v){
    for(int i=0; i<n; i++){
        if(array[i] == v){
            return i;
        }
    }
}
int insertionSort(int array[], int n){

    for(int j=1; j<n; j++){
        int temp = array[j];
        int i = j-1;
        while(i>=0 && array[i]<temp){ //ascending order
            
            array[i+1] = array[i];       //for descending order array[i]<temp
            i = i-1;
            
        }
        array[i+1] = temp;
    }
}
int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    int v;
    cin >> v;
    int index = findIndex(array,n,v); //9 2 6 0 1 5 == v=0 == 3
    insertionSort(array,n);

    int temp = array[index]; // array[3] == 0
    int k;
    for(int p=0; p<n; p++){
        if(v==array[p])k=p;
    }
    
    array[index] = v;
    array[k] = temp;

    insertionSort(array,index);
    sort(array+index+1,array+n,greater<int>());
    for(int p=0; p<n; p++){
        cout << array[p] << " ";
    }
}