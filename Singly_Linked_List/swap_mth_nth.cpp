#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next; //Inter referential pointer(IRP)
};

Node *first , *temp , *ttemp , *P , *Q ,*R;  //Global declaration

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

//Swapping mth and nth node
void swap_mn(int m,int n){
    temp=first;
    int i=1;
    while(i<m && temp!=NULL){
        P=temp;
        temp=temp->next;
        i++;
    }
    int j=1;
    ttemp=first;
    while(j<n && ttemp!=NULL){
        Q=ttemp;
        ttemp=ttemp->next;
        j++;
    }
    if(temp==ttemp)   //swapping of single element not possible
    return;
    if(P!=NULL){
        P->next=ttemp;
    }else{
        first=ttemp;
    }
    if(Q!=NULL){
        Q->next=temp;
    }else{
        first=temp;
    }
    R=temp->next;
    temp->next=ttemp->next;
    ttemp->next=R;
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
    swap_mn(4,2);
    display();
    return 0;
}

