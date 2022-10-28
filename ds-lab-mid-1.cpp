#include<iostream>
using namespace std;

int present(int array[], int k){
    for(int i=0;i<5;i++){
        if(array[i]==k)return i;
    }
    return 0;
}

int main(){
    int array[5];
    for(int i=0;i<5;i++){
        cin >> array[i];
    }
    int k;
    cout << "Enter the value of k ";
    cin >> k;
    if(present(array,k)!=0){
        int index = present(array,k);
        for(int i=index-1; i>=0; i--){
            if(array[i]%2==0){
                cout << "Previous Lower Even Number is: " << array[i] << endl;
            }
        }
    }
    else{
        for(int i=0;i<4;i++){
            int flag=0;
            if(array[i]%2==0 && array[i+1]%2==0){
                cout << "Index is " << i+1+1 << endl;
                flag=1;
                break;
            }
            if(i==3){
                int middle = 5/2;
                cout << "inserting as a middle element & the index is "<< middle+1 << endl;
                break;
            }
        }
    }
}