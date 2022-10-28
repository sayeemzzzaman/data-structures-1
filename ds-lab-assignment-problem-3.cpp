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
void seperateOddEven(int direction){
    temp = head;
    int even[1000],odd[1000],ev=0,od=0;
    while(temp!=NULL){
        if(temp->data % 2==0){
            even[ev] = temp->data;
            ev++;
        }
        else {
            odd[od] = temp->data;
            od++;
        }
        temp = temp->next;
    }
    if(direction==2){
        for(int i=0; i<ev; i++){
            cout << even[i] << " ";
        }
        for(int i=0; i<od; i++){
            cout << odd[i] << " ";
        }
    }
    else if(direction==1){
        for(int i=0; i<od; i++){
            cout << odd[i] << " ";
        }
        for(int i=0; i<ev; i++){
        cout << even[i] << " ";
        }
    }
    
}

int main(){

    int n,direction,count=0;
    cin >> n  >> direction;
    while(true){
        if(head!=NULL){
            if(count==n)break;
                LastInsertion(1+(rand()%100));
                count++;
        }
        else {
            head = (node*)malloc(sizeof(node));
            head->data = 1+(rand()%100);
            head->next = NULL;
            count++;
            //printList();
        }
    }
    //printList();
    //cout << endl;
    seperateOddEven(direction);
}