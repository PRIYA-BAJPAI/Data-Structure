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
    if(temp->next==first){
        cout<<temp->data<<endl;
        return;
    }
    cout<<temp->data<<endl;
    temp=temp->next;
}

int main(){
    create_first(10);
    display();
}