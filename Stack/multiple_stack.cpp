#include<iostream>
using namespace std;
struct stack{
    int data[6];
    int topA,topB;
};
stack *P,S1;
void init(){
    P=&S1;
    P->topA=-1;
    P->topB=6;
}
int emptyA(){
    if(P->topA==-1){
        return 1;
    }else{
        return 0;
    }
}
int emptyB(){
    if(P->topB==6){
        return 1;
    }else{
        return 0;
    }
}
int full(){
    if(P->topA+1==P->topB){
        return 1;
    }else{
        return 0;
    }
}
void pushA(int x){
    if(full()){
        return ;
    }
    P->topA++;
    P->data[P->topA]=x;
}
void pushB(int x){
    if(full()){
        return ;
    }
    P->topB--;
    P->data[P->topB]=x;
}
int popA(){
    int y;
    if(emptyA()){
        return 0;
    }
    y=P->data[P->topA];
    P->topA--;
    return y;
}
int popB(){
    int y;
    if(emptyB()){
        return 0;
    }
    y=P->data[P->topB];
    P->topB++;
    return y;
}
int main(){
    init();
    pushA(10);
    pushB(20);
    pushA(30);
    pushB(40);
    pushA(50);
    pushB(60);
    cout<<popA()<<endl;
    cout<<popA()<<endl;
    cout<<popB()<<endl;
    cout<<popB()<<endl;
    
}