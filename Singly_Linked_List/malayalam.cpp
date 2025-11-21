#include<iostream>
using namespace std;
struct Node{
    char data;
    Node *next; //Inter referential pointer(IRP)
};

Node *first , *temp , *ttemp , *P ,*first2 , *temp2;  //Global declaration

void init(){
    first=temp=ttemp=NULL;
}

//creation of 1st node
void create_first(char y){
    first=new Node;
    // cout<<"Enter the value : ";
    // cin>>first -> data;
    first->data=y;
    first -> next=NULL;
} 

void display(){
    temp=first;
    while(temp!=NULL){
        cout<<temp ->data<<" ";
        temp=temp ->next;
    }
}

//addition of node to the last
void add_node(char x){
    temp=first;
    while(temp ->next!=NULL)
        temp=temp ->next;
        ttemp=new Node;
        ttemp ->data=x;
        ttemp ->next=NULL;
        temp ->next=ttemp; 
}

void store_reverse(){
    Node *t = first;
    temp2 = NULL;   // start empty

    while(t != NULL){
        Node *newnode = new Node;
        newnode->data = t->data;

        // insert at beginning of revfirst
        newnode->next = temp2;
        temp2 = newnode;

        t = t->next;
    }
}

bool check_palindrome(){
 
    
}

int main(){
    init();
    create_first('M');
    add_node('A');
    add_node('L');
    add_node('A');
    add_node('Y');
    add_node('A');
    add_node('L');
    add_node('A');
    add_node('M');
    display();
    cout<<endl;
    check_palindrome();
    display();
    return 0;
}
