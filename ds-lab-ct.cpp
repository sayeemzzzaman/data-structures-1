#include<iostream>
using namespace std;

int arr[100], top=-1, cap;

void push(int n){
    if(top+1 == cap){}//cout << "Stack Overflow" << endl;
    else arr[++top] = n;
}

int pop(){
    int m;
    if(top==-1){}//cout << "Stack Underflow" << endl;
    else{
        m = arr[top];
        arr[top--] = -1;
        //top--;
    }
    return m;
}

void printStack(){
    if(top==-1)cout << "Empty Stack" << endl;
    for(int i=0; i<=top; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    cout << "Enter the capacity: ";
    cin >> cap;
    int k=4,max=-99999;
    int i=cap;
    int arr[cap];
    for(int m=0;m<cap;m++){
        // cout << "Enter your choice: " << endl << "1 to push" << endl << "2 to pop" << endl << "3 to print" << endl << "0 to exit" << endl;

        // int choice;
        // cin >> choice;
       // if(choice==1){
            cout << "Enter the value you want to push: ";
            int pushValue;
            cin >> pushValue;
            push(pushValue);
            arr[m] = pushValue;
        // }
        // else if(choice==2)pop();
        // else if(choice==3)printStack();
        // else if(choice==0)break;

    }
    //while(k--){
    pop();
    pop();
    int l = pop();
    push(l);
    max = top+1;
    //cout << top+1 << endl;
    cout << "pop() pop() pop() push()" << endl;
    //printStack();
    //}
    while(top!=-1)pop();
    for(int m=0; m<cap;m++){
        push(arr[m]);
    }
    //printStack();
    pop();
    pop();
    pop();
    pop();
    if(max<top+1)max = top+1;
    //cout << max;
    while(top!=-1)pop();
    for(int m=0; m<cap;m++){
        push(arr[m]);
    }
    l = pop();
    push(l);
    pop();
    pop();
    if(max<top+1)max = top+1;
    while(top!=-1)pop();
    for(int m=0; m<cap;m++){
        push(arr[m]);
    }
    l = pop();
    push(l);
    l = pop();
    push(l);

    cout << max;
}