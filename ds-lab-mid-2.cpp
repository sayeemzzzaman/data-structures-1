#include<iostream>
#include<stdlib.h>
using namespace std;

struct list{
    int data;
    struct list *next,*back;
}; // alternative name

typedef struct list node;
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
int present(int n){
    //int flag=0;
    temp = head;
    while(temp->next != NULL){
        if(temp->data == n){
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}

int main(){

    int a,k,choice,count=0,takingInput=0;
    char c;

    while(a!=-1){
        cout << "Enter 1 to Insert or Enter 2 to Delete" << endl;
        cin >> choice;
        if(head!=NULL){
            if(choice == 1){
                cout << "Enter the value you want to insert: " << endl;
                cin >> a;
                // cout << "Enter the position where you want to insert: " << endl;
                // cin >> k;
                if(a!=-1){
                    LastInsertion(a);
                    count++;
                    takingInput++;
                    //FirstInsertion(a);
                    // if(k==1){
                    //     FirstInsertion(a);
                    // }else
                    // MiddleInsertion(a,k);
                    printList();
                    cout << endl;
                    if(takingInput==5){
                        cout << "Enter character value: ";
                        cin >> c;
                        
                        if('A'<= c && 'H' >= c){
                            int n,m;
                            cout << "Enter the value of n & m: ";
                            cin >> n >> m;
                            if(present(n)){
                                MiddleInsertion(m,n);
                                printList();
                                cout << endl;
                                count++;
                                takingInput++;
                            }
                            else{
                                MiddleInsertion(n,m);
                                printList();
                                cout << endl;
                                count++;
                                takingInput++;
                            }
                        }
                        else{
                            middleDeletion(count-2);
                            takingInput--;
                            count--;
                            printList();
                            cout << endl;
                        }
                    }
                }
            }
            else if(choice == 2){
                //firstDeletion();
                int n;
                cout << "Enter the delete position: ";
                cin >> n;
                if(n==1){
                    count--;
                    takingInput--;
                    //cout << count << "count" << endl;
                    firstDeletion();
                }
                else if(count==n){
                    takingInput--;
                    lastDeletion();
                    count--;
                    
                }
                else{
                    takingInput--;
                    middleDeletion(n);
                    count--;
                }
                    
                //lastDeletion();
                printList();
                cout << endl;
            }
        }
        else{
            head = (node*) malloc(sizeof(node));
            cout << "Enter the head value you want to insert: " << endl;
            cin >> a;

            count++;
            takingInput++;
            head->data = a;
            head->next = NULL;
            head->back = NULL;
            printList();
            cout << endl;
        }
    }
    //cout << "count2" << count << endl;
    //if(count==0)cout<< "Empty List" << endl;
    
    
    printList();
    

}