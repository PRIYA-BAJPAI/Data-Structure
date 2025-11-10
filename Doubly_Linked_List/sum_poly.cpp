#include<iostream>
using namespace std;
struct Poly{
    int coeff;
    int pow;
    Poly *next;
};
Poly *first,*temp,*ttemp,*P,*poly1,*poly2;

void init(){
    first=temp=ttemp=poly1=poly2=P=NULL;
}
//Write a polynomial in the form of LL
void create_first(Poly *first){
    first=new Poly;
    cout<<"Enter coeff : ";
    cin>>first->coeff;
    cout<<"Enter power : ";
    cin>>first->pow;
    first->next=NULL;
}
void add_node(Poly *first){
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
void display(Poly *first){
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
    init();
    int n,m;
    cout<<"Enter total no. of terms : ";
    cin>>n;
    create_first(poly1);
    for(int i=1;i<n;i++){
        add_node(poly1);
    }
    display(poly1);
    // cout<<" = 0";
    cout<<"Enter total no. of terms : ";
    cin>>m;
    create_first(poly2);
    for(int i=1;i<m;i++){
        add_node(poly2);
    }
    display(poly2);
    return 0;
}


//not correct