#include<iostream>
#include<stdlib.h>
using namespace std;

struct list{
    int data;
    struct list *next;
};

typedef struct list node;
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
int freq(int value){
    temp=head;
    int count = 0;
    while(temp!=NULL){
        if(temp->data==value)count++;
        temp = temp->next;
    }
    return count;
}

void notMoreThanTwo(int value){
    if(head==NULL){
        head = (node*)malloc(sizeof(node));
        head->data=value;
        head->next=NULL;
        printList();
        cout << endl;
    }
    else{
        int fq = freq(value);
        if(fq==0){
            FirstInsertion(value);
            cout << value << " inserted" << endl;
        }
        else if(fq==1){
            LastInsertion(value);
            cout << value << " inserted" << endl;
        }
        else if(fq==2){
            cout << head->data << " deleted" << endl;
            firstDeletion();
        }
        // cout << "list->";
        // printList();
        // cout << endl;
    }
}

int main(){

    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        int randomValue = 1+(rand()%100);
        //cout << " randvalue" << randomValue << endl;
        notMoreThanTwo(randomValue);
    }
}