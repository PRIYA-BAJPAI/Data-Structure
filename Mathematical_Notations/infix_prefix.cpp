#include<iostream>
#include<string>
using namespace std;

struct notation{
    string data;
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

string stack_top(){
    if(top==NULL){
        return 0;
    }
    return top->data;
}

void infix_prefix(char infix[],string prefix[]){
    init();
    int i=0,j=0;
    string str1,str2,str3,str4,str5;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            prefix[j++]=string(1,infix[i]); //string of length 1 having data infix[i]
        }else if(infix[i]=='('){
            push("(");
        }else if(infix[i]==')'){
            while(top!=NULL && stack_top()!="("){
                str1=prefix[j-1];
                str2=prefix[j-2];
                j=j-2;
                str3=pop();
                str4=str2+str1;
                str5=str3+str4;
                prefix[j++]=str5;
            }
            pop(); //to remove (
        }
        else{
            while(top!=NULL && prioprity_operator(stack_top()[0])>=prioprity_operator(infix[i])){
                str1=prefix[j-1];
                str2=prefix[j-2];
                j=j-2;
                str3=pop();
                str4=str2+str1;
                str5=str3+str4;
                prefix[j++]=str5;
            }
            push(string(1,infix[i]));
        }
        i++; //always remember
    }
    //pop remaining elements
    while(top!=NULL){
        str1=prefix[j-1];
        str2=prefix[j-2];
        j=j-2;
        str3=pop();
        str4=str2+str1;
        str5=str3+str4;
        prefix[j++]=str5;
    }
    prefix[j]=""; //last element (empty)
}

int main(){
    char infix[50];
    string prefix[50];
    cout<<"Enter Infix Notation :";
    cin>>infix;
    
    cout<<"prefix :";
    infix_prefix(infix,prefix);
    for(int k=0;prefix[k] !="";k++){
        cout<<prefix[k];
    }
   
    return 0;
}

