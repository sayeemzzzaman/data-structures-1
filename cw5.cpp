#include<iostream>
using namespace std;

int arr[100], top=-1, cap;

void enqueue(int n){
    if(top+1 == cap)cout << "Queue Overflow" << endl;
    else{
        if(top==-1){arr[0] = n;top++;}
        else{
            for(int i=top; i>=0; i--){
            arr[i+1] = arr[i];
            }
            arr[0] = n;
            top++;
        }
        
    }
}

void dequeue(){
    if(top==-1)cout << "Queue Underflow" << endl;
    else{
        arr[top] = -1;
        top--;
    }
}

void printQueue(){
    if(top==-1)cout << "Empty Queue" << endl;
    for(int i=0; i<=top; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    cout << "Enter the capacity: ";
    cin >> cap;
    int t=cap;
    while(t--){ 
        int v;
        cin >> v;
        enqueue(v);
        printQueue();
    }
    char c;
    cout << " Enter the character: " << endl;
    cin >> c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        int value = c;
        enqueue(value);
    }
    else dequeue();

    printQueue();
    
    
}