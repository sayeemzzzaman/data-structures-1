#include<iostream>
#include<cstdlib>
#include <unordered_map>
//#include<bits/stdc++.h>
using namespace std;

struct list{
    int data;
    struct list *next;
};

typedef struct list node;
node *head, *temp, *temp1,*temp2, *previous;
int n;

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

void printList(){
    node *t;
    t = head;
    while(t != NULL){
        cout << t->data << " ";
        t = t->next;
    }
}


void customOrder(){
    unordered_map<int, int> freq;
    temp = head;
    while(temp != NULL){
        int m = temp->data;
        freq[m]++; //adding the frequencies
        temp = temp->next;
    }

    int maxFreq = -99999;
    for(auto t : freq){
      if(maxFreq<t.second)maxFreq=t.second; //maximum frequency
    }

    int arr[n],p=0;
    while(maxFreq){
        for(auto t:freq){
            if(maxFreq == t.second){ //access the highest freq first
                for(int u=1;u<=maxFreq;u++){ //loop for copying multiple same number
                    arr[p] = t.first;
                    p++;
                }
            }
        }
        maxFreq--;
    }
    //assigning the values into head again--!
    head = NULL;
    head = (node*)malloc(sizeof(node));
    head->data = arr[0];
    head->next = NULL;
    for(int i=1;i<n;i++)LastInsertion(arr[i]);
    //cout<<endl;
    //printList();
}

int main(){

    //code start--!!
    cin >> n;
    for (int i = 0; i < n; i++){
        if(head!=NULL){
            LastInsertion(1+(rand()%100));
            //printList();
            //cout << endl;
        }
        else{
            head = (node*)malloc(sizeof(node));
            head -> data = 1+(rand()%100); //generating random input
            head -> next = NULL;
            //printList();
            //cout << endl;
        }
    }
    customOrder();
    printList();

    // for testing input--!  14 9 11 3 14 3 20
    
    // head = (node*)malloc(sizeof(node));
    // head->data=14;
    // head->next = NULL;
    // LastInsertion(9);
    // LastInsertion(11);
    // LastInsertion(3);
    // LastInsertion(14);
    // LastInsertion(3);
    // LastInsertion(20);
    // // printList();
    // // cout << endl;
    // customOrder();
    // printList();
}

