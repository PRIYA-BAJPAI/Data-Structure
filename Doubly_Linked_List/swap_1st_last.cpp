#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev,*next;
};

Node *first,*temp,*ttemp,*P;

void create_first(int x){
    first=new Node;
    first->data=x;
    first->next=first->prev=NULL;
}

void display(){
    temp=first;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

void add_node(int x){
    temp=first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ttemp=new Node;
    ttemp->prev=temp;
    ttemp->data=x;
    ttemp->next=NULL;
    temp->next=ttemp;
}

void swap_1st_last(){
    temp=first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ttemp=temp->prev;
    P=first->next;
    first->next=NULL;
    first->prev=ttemp;
    ttemp->next=first;
    temp->next=P;
    temp->prev=NULL;
    P->prev=temp;
    first=temp;
}

int main(){
    create_first(10);
    add_node(20);
    add_node(30);
    add_node(40);
    add_node(50);
    add_node(60);
    display();
    cout<<"After swapping :"<<endl;
    swap_1st_last();
    display();
    return 0;
}
