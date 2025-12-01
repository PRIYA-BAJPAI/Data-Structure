//Reverse a number using array implementation of stack
#include<iostream>
using namespace std;
struct stack{
    int data[10];
    int top;
};
stack S;
void init(stack *P){
    // P=&S;
    P->top=-1;
}
int Empty(stack *P){
    if(P->top==-1){
        return 1;
    }else return 0;
}
int full(stack *P){
    if(P->top==9){
        return 1;
    }else return 0;
}
void push(stack *P,int x){
    if(full(P)) return ;
    P->top++;
    P->data[P->top]=x;
}
int pop(stack *P){
    int y;
    if(Empty(P)) return 0;
    y=P->data[P->top];
    P->top--;
    return y;
}
void print(stack *P){
        for(int i=P->top;i>=0;i--){
        cout<<P->data[i]<<" ";
        }
        
    }


int main(){
    stack S1,S2;
    init(&S1);
    init(&S2);

    push(&S1,10);
    push(&S1,20);
    push(&S1,30);
    push(&S1,40);
    push(&S1,50);
    cout<<"Original Array :";
    print(&S1);
    cout<<"\n";
    while(!Empty(&S1)){
    push(&S2,pop(&S1));
    }
    cout<<"Reversed Array : ";
    print(&S2);
}