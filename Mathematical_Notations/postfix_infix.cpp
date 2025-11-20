#include<iostream>
#include<cstring>
using namespace std;

struct notation{
    string data;
    notation *next;
}; 

notation *top,*temp,*ttemp;

void init(){
    top=temp=ttemp=NULL;
}


bool isOperand(char ch){
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return true;
    }
    return false;
}

void push(string x){
    temp=new notation;
    if(temp==NULL){
        cout<<"Stack is full";
        return ;
    }
    temp->data=x;
    temp->next=top;
    top=temp;
}

string pop(){
    string x;
    if(top==NULL){
        return 0;
     }
    temp=top;
    x=temp->data;
    top=top->next;
    delete temp;
    return x;
}

string postfix_infix(char postfix[]){
    init();
    int i=0,j=0;
    string str1,str2,str3,str4,str5;
    while(postfix[i]!='\0'){
        if(isOperand(postfix[i])){
            push(string(1,postfix[i]));  //string of size 1
            i++;
        }
        else{
            
                str1=pop();
                str2=pop();
                str3=postfix[i];
                str4=str3+str1;
                str5=str2+str4;
                push(str5);
                i++;
            }
    }
    return pop();
}
int main(){
    char postfix[50];
    cout<<"Enter postfix Notation :";
    cin>>postfix;
    string infix=postfix_infix(postfix);
    cout<<"Infix :"<<infix;
    return 0;
}

