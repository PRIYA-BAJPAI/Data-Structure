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
void reverse(char s[]){
    int n=strlen(s);
    for(int i=0;i<n/2;i++){
        char t=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=t;
    }
}
string prefix_postfix(char prefix[]){
    init();
    reverse(prefix);
    int i=0,j=0;
    string str1,str2,str3,str4,str5;
    while(prefix[i]!='\0'){
        if(isOperand(prefix[i])){
            push(string(1,prefix[i]));  //string of size 1
            i++;
        }
        else{
            
                str1=pop();
                str2=pop();
                str3=prefix[i];
                str4=str1+str2;
                str5=str4+str3;
                push(str5);
                i++;
            }
        
        //i++; //always remember
    }
    return pop();
}
int main(){
    char prefix[50];
    cout<<"Enter prefix Notation :";
    cin>>prefix;
    string postfix=prefix_postfix(prefix);
    cout<<"postfix :"<<postfix;
    return 0;
}

