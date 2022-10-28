#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node; // alternative name

node *head, *temp, *temp1, *previous;

void FirstInsertion(int n){
    temp = (node*)malloc(sizeof(node));
    temp->data = n;
    temp->next = head;
    head = temp;
}

void LastInsertion(int n){

    previous = head;
    while(previous->next != NULL){
        previous = previous->next;
    }

    temp = (node*)malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;
    previous->next = temp;
}

void MiddleInsertion(int a, int k){
    int count=0;

    temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    if(k<=count){
        temp = head;
        for(int i=1; i<k-1; i++){
            temp = temp->next;
        }
        temp1 = (node*)malloc(sizeof(node));
        temp1 ->data = a;
        temp1 ->next = temp->next;
        temp -> next = temp1;
    }
    else {
        cout << "Invalid Position" << endl;
    }
    
}

void printList(){
    node *t;
    t = head;
    while(t != NULL){
        cout << t->data << " ";
        t = t->next;
    }
}

void firstDeletion(){
    temp = head;
    head = head -> next;
    free(temp);
}

void middleDeletion(int n){
    temp = head;
    for(int i=1; i<n-1; i++){
        temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = temp->next->next;
    free(temp1);
}

void lastDeletion(){
    temp1 = head;
    temp = head ->next;
    while(temp->next != NULL){
        temp = temp -> next;
        temp1 = temp1 -> next;
    }
    free(temp);
    temp1 -> next = NULL;
}

int main(){

    int a,k,choice,count=1,v;

    while(a!=-1){

        if(head!=NULL){
                cout << "Enter the value you want to insert: " << endl;
                cin >> a;
                if(a!=-1){
                    FirstInsertion(a);
                    count++;
                    if(count==3){
                        cout << "Enter value of V: ";
                        cin >> v;
                        if(v%2==0)
                        middleDeletion(count-1);
                        else if(v%2!=0){
                            MiddleInsertion(v,2);
                        }
                        printList();
                        return -1;
                    }
                }
        }
        else{
            head = (node*) malloc(sizeof(node));
            cout << "Enter the head value you want to insert: " << endl;
            cin >> a;
            head->data = a;
            head->next = NULL;
            printList();
            cout << endl;
        }
    }
    
    
    printList();
    

}