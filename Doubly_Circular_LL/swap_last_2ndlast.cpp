#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next,*prev;
};

Node *first,*temp,*ttemp,*P;

void create_first(int x){
    first=new Node;
    first->next=first->prev=first;
    first->data=x;
}

void display(){
    temp=first;
    do{
        cout<<temp->data<<endl;
        temp=temp->next;
    }while(temp!=first);
}

void add_node(int x){
    temp=first->prev;
    ttemp=new Node;
    ttemp->data=x;
    ttemp->next=first;
    ttemp->prev=temp;
    temp->next=ttemp;
    first->prev=ttemp;
}

void swap_last_2ndlast(){
    temp=first->prev;
    ttemp=temp->prev;
    P=ttemp->prev;
    temp->next=ttemp;
    temp->prev=P;
    ttemp->next=first;
    ttemp->prev=temp;
    P->next=temp;
    first->prev=ttemp;
}

int main(){
    create_first(10);
    add_node(20);
    add_node(30);
    add_node(40);
    add_node(50);
    add_node(60);
    add_node(70);
    display();
    cout<<"After swapping :"<<endl;
    swap_last_2ndlast();
    display();
}