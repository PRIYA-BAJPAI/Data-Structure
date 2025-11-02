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

//reversing a singly linked list 
void reverse(){
    while(first!=NULL){
        ttemp=first->next;
        first->next=temp;
        temp=first;
        first=ttemp;
    }
    first=temp;
}
 
int main(){
    init();
    create_first();
    add_node(20);
    add_node(30);
    add_node(40);
    add_node(50);
    add_node(60);
    add_node(70);
    add_node(80);
    display();
    printf("updated linklist : \n");
    reverse();
    display();
    return 0;
}
