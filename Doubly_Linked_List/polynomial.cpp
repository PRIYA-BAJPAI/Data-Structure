#include<iostream>
using namespace std;
struct Poly{
    int coeff;
    int pow;
    Poly *next;
};
Poly *first,*temp,*ttemp,*P;
//Write a polynomial in the form of LL
void create_first(){
    first=new Poly;
    cout<<"Enter coeff : ";
    cin>>first->coeff;
    cout<<"Enter power : ";
    cin>>first->pow;
    first->next=NULL;
}
void add(){
    temp=first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ttemp=new Poly;
    cout<<"Enter coeff : ";
    cin>>ttemp->coeff;
    cout<<"Enter power : ";
    cin>>ttemp->pow;
    ttemp->next=NULL;
    temp->next=ttemp;
}
void display(){
    temp=first;
    if(temp==NULL){
        cout<<"Polynomial is Empty";
    }
    while(temp!=NULL){
        cout<<temp->coeff<<" x^"<<temp->pow;
        temp=temp->next;
        if(temp!=NULL){
            cout<<" + ";
        }
    }
}
int main(){
    int n;
    cout<<"Enter total no. of terms : ";
    cin>>n;
    create_first();
    for(int i=1;i<n;i++){
        add();
    }
    display();
    cout<<" = 0";
    return 0;
}
