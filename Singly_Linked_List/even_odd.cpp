#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next; //Inter referential pointer(IRP)
};

Node *first , *temp , *ttemp , *P;  //Global declaration

void init(){
    first=temp=ttemp=NULL;
}

//creation of 1st node
void create_first(){
    first=new Node;
    cout<<"Enter the value : ";
    cin>>first -> data;
    // first->data;
    first -> next=NULL;
} 

void display(){
    temp=first;
    while(temp!=NULL){
        cout<<temp ->data<<endl;
        temp=temp ->next;
    }
}

//addition of node to the last
void add_node(int x){
    temp=first;
    while(temp ->next!=NULL)
        temp=temp ->next;
        ttemp=new Node;
        ttemp ->data=x;
        ttemp ->next=NULL;
        temp ->next=ttemp; 
}

//A LL contains all the natural nos from 1-10 split this LL into separate list so that one list contains all the even nos and the another list contains all the odd nos.
void odd_even(){
    temp=first->next;
    P=temp;
    ttemp=first;
    while(P->next!=NULL && ttemp->next->next!=NULL){
        ttemp->next=ttemp->next->next;
        ttemp=ttemp->next;
        P->next=P->next->next;
        P=P->next;    
    }    
    ttemp=first;
    P=temp;
    //print
    cout<<"Even numbers are : \n";
    while(P!=NULL){
        cout<<P->data<<" ";
        P=P->next;
    }
    cout<<endl;
    cout<<"Odd numbers are : \n";
    while(ttemp->next!=NULL){
        cout<<ttemp->data<<" ";
        ttemp=ttemp->next;
    }
    ttemp->next=NULL;
}    
 
int main(){
    init();
    create_first();
    add_node(2);
    add_node(3);
    add_node(4);
    add_node(5);
    add_node(6);
    add_node(7);
    add_node(8);
    add_node(9);
    add_node(10);
    display();
    odd_even();
    return 0;
}
