#include<iostream>
using namespace std;
struct stack{
    int data[10];
    int top;
};
stack *P,S;
void init(){
    P=&S;
    P->top=-1;
}
int Empty(){
    if(P->top==-1){
        return 1;
    }else return 0;
}
int full(){
    if(P->top==9){
        return 1;
    }else return 0;
}
void push(int x){
    if(full()) return ;
    P->top++;
    P->data[P->top]=x;
}
void print(){
        for(int i=P->top;i>=0;i--){
        cout<<P->data[i]<<endl;
        }
        
    }


int main(){
    init();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    print();
}