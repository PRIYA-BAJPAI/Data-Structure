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

int main(){
    create_first(10);
    display();
    return 0;
}