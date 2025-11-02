#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next; //Inter referential pointer(IRP)
};
Node *first , *temp , *ttemp;  //Global declaration

void init(){
    first=temp=ttemp=NULL;
}

void create_first(){
    first=new Node;
    first -> next=NULL;
    cout<<"Enter the value : ";
    cin>>first -> data;
} 

void display(){
    temp=first;
    while(temp!=NULL){
        cout<<temp ->data;
        temp=temp ->next;
    }
}

int main(){
    init();
    create_first();
    display();
    return 0;
}

