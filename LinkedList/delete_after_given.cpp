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

//deletion of node after given data
void delete_after_given(int x){
    temp=first;
    while(temp->data!=x){
        temp=temp->next;
    }
    ttemp=temp->next;
    P=ttemp->next;
    temp->next=P;
    ttemp->next=NULL;
    delete ttemp;
}

int main(){
    init();
    create_first();
    add_node(20);
    add_node(30);
    add_node(40);
    add_node(50);
    display();
    printf("updated LL : \n");
    delete_after_given(50);
    display();
    
    
    return 0;
}
