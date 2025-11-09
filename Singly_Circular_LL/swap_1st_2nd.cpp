#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *first,*temp,*ttemp,*P;

void create_first(int x){
    first=new Node;
    first->data=x;
    first->next=first;
}

void display(){
    temp=first;
    do{
        cout<<temp->data<<endl;
        temp=temp->next;
    }while(temp!=first);
}

void add_node(int x){
    temp=first;
    while(temp->next!=first){
        temp=temp->next;
    }
    ttemp=new Node;
    temp->next=ttemp;
    ttemp->data=x;
    ttemp->next=first;
}

void swap_1st_2nd(){
    temp=first;
    while(temp->next!=first){
        temp=temp->next;
    }
    ttemp=first->next;
    P=ttemp->next;
    first->next=P;
    ttemp->next=first;
    temp->next=ttemp;
    first=ttemp;
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
    swap_1st_2nd();
    display();
    return 0;
}