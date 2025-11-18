#include<iostream>
using namespace std;
struct linked{
    int data;
    linked *next;
};

linked *top,*temp,*ttemp;

void init(){
    temp=ttemp=top=NULL;
}

void push(int x){
    temp=new linked;
    if(temp==NULL){
        return;//full condition
    }
    temp->data=x;
    temp->next=top;
    top=temp;
}

int pop(){
    int x;
    if(top==NULL){
        return 0;//empty condition
    }
    temp=top;
    x=temp->data;
    // temp->next=NULL;
    top=top->next;
    delete temp;
    return x;
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;

}
