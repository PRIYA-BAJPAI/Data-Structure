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

int main(){
    create_first(10);
    display();
    return 0;
}
