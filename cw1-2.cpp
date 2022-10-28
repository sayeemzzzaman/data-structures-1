#include<iostream>
using namespace std;
int insertionSort(int array[], int n){
    for(int j=1; j<n; j++){
        int temp = array[j];
        int i = j-1;
        while(i>=0 && array[i]>temp){ //ascending order
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
    int even[n],odd[n];
    int p=0,q=0;
    for(int i=0; i<n; i++){
        if(array[i]%2==0){
            even[p]=array[i];
            p++;
        }
        else{
            odd[q]=array[i];
            q++;
        }
    }
    //for(int i=0; i<q; i++)cout << odd[i] << " ";

    insertionSort(even, p);
    // for(int i=0; i<p; i++){
    //     cout << even[i] << " ";
    // }
    int newArray[p+q];
    int i;
    for(i=0; i<p; i++){
        newArray[i] = even[i];
    }
    for(int j=0; j<q; j++){
        newArray[i] = odd[j];
        i++;
    }

    for(int i=0; i<p+q; i++){
        cout << newArray[i] << " ";
    }

}