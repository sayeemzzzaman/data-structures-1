#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node{
    int data;
    node *next,*back;
}node; // alternative name

node *head, *temp, *temp1, *previous;

void FirstInsertion(int n){
    temp = (node*)malloc(sizeof(node));
    temp->data = n;
    temp->back = NULL;
    temp->next = head;
    head->back = temp;
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
    temp->back = previous;
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
        temp1->back = temp;
        //if(temp1->next != NULL){
            temp->next->back = temp1;
        //}
        
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
    head->back = NULL;
    free(temp);
}

void middleDeletion(int n){
    temp = head;
    for(int i=1; i<n; i++){
        temp = temp->next;
    }
    temp->back->next = temp->next;
    temp->next->back = temp->back;
    free(temp);
}

void lastDeletion(){
    //temp1 = head;
    temp = head ->next;
    while(temp->next != NULL){
        temp = temp -> next;
        //temp1 = temp1 -> next;
    }
    temp -> back -> next = NULL;
    free(temp);
    
}
int position(int v){
    int count=0,flag=0;

    temp = head;
    while(temp != NULL){
        count++;
        if(temp->data == v){
            flag=1;
            break;
        }
        temp = temp->next;
    }
    if(flag==0)return 0;
    return count;
}
int elements(){
    int count = 0;
    temp = head;
    while(temp != NULL){
        temp = temp-> next;
        count++;
    }
    return count;
    //cout << count << endl;
}

int main(){

    int a,k,choice,count=1,v;

    while(a!=-1){

        if(head!=NULL){
                cout << "Enter the value you want to insert: " << endl;
                cin >> a;
                if(a!=-1){
                    LastInsertion(a);
                    printList();
                    cout << endl;
                    count++;
                    if(count==5){
                        cout << "Enter value of V: ";
                        cin >> v;
                        int x = position(v);
                        cout << "position " << x << endl;
                        if(x==0){
                            int elem = elements();
                            MiddleInsertion(v,count/2);
                            //printList();
                        }
                        else if(x==1)firstDeletion();
                        else
                            middleDeletion(x);
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