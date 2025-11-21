#include<iostream>
#include<math.h>
#include<string.h>
#include<stack>
using namespace std;
struct notation{
    char data;
    notation *next;
}; 

notation *top,*temp,*ttemp;

void init(){
    top=temp=ttemp=NULL;
}

//precidence
int prioprity_operator(char ch){
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0;

}

bool isOperand(char ch){
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return true;
    }
    return false;
}

void push(char x){
    temp=new notation;
    if(temp==NULL){
        cout<<"Stack is full";
        return ;
    }
    temp->data=x;
    temp->next=top;
    top=temp;
}

char pop(){
    char x;
    if(top==NULL){
        return 0;
     }
    temp=top;
    x=temp->data;
    top=top->next;
    delete temp;
    return x;
}

char stack_top(){
    if(top==NULL){
        return 0;
    }
    return top->data;
}

void infix_Postfix(char infix[],char postfix[]){
    init();
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i];
        }else if(infix[i]=='('){
            push(infix[i]);
        }else if(infix[i]==')'){
            while(top!=NULL && stack_top()!='('){
                postfix[j++]=pop();
            }
            pop(); //to remove (
        }
        else{
            while(top!=NULL && prioprity_operator(stack_top())>=prioprity_operator(infix[i])){
                postfix[j++]=pop(); 
            }
            push(infix[i]);
        }
        i++; //always remember
    }
    //pop remaining elements
    while(top!=NULL){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

void post_evaluation(char postfix[]){
    
    int i;
    //notation s;
    int OP1,OP2,R;
    int calculate(int,int ,char);
    for(i=0;i<strlen(postfix);i++){
        if(isalnum(postfix[i])){
            push(postfix[i]);
        }else{
            OP1=pop();
            OP2=pop();
            R=calculate(OP1,OP2,postfix[i]);
            push(R);
        }
    }
    cout<<"result : "<<pop();
}

int calculate(int O1,int O2,char x){
    switch(x){
        case '+':return O2+O1;
        case '-':return O2-O1;
        case '*':return O2*O1;
        case '/':return O2/O1;
        case '^':return pow(O2,O1);
        default:return -1;
    }
}

int main(){
    char infix[50],postfix[50];
    cout<<"Enter Infix Notation :";
    cin>>infix;
    infix_Postfix(infix,postfix);
    post_evaluation(postfix);
    return 0;
}