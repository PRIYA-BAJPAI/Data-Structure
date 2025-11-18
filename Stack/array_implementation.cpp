#include<iostream>
using namespace std;
struct stack{
    int data[5];
    int top;
};
stack *P,S1;
void init(){
    P=&S1;
    P->top=-1;
}
int empty(){
    if(P->top==-1){
        return 1;
    }else{
        return 0;
    }
}
int full(){
    if(P->top==4){
        return 1;
    }else{
        return 0;
    }
}
void push(int x){
    if(full()){
        return ;
    }
    P->top++;
    P->data[P->top]=x;
}
int pop(){
    int y;
    if(empty()){
        return 0;
    }
    y=P->data[P->top];
    P->top--;
}
int main(){
    init();
     push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
}