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

//addition of node before first node
void add_before_first(int y){
    temp=new Node;
    temp->data=y;
    temp->next=first;
    first=temp;
}
 

int main(){
    init();
    create_first();
    add_node(20);
    add_node(30);
    add_node(40);
    add_node(50);
    display();
    printf("updated linklist : \n");
    add_before_first(60);
    display();
    return 0;
}
