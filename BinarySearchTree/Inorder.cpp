#include<iostream>
using namespace std;
struct BST{
    int data;
    BST *left;
    BST *right;
};
BST *root,*temp,*ttemp,*P;
void init(){
    root=temp=ttemp=P=NULL;
}
void create_root(int x){
    root=new BST;
    root->data=x;
    root->left=root->right=NULL;
}
void add_node(int x){
    temp=root;
    while(temp!=NULL){
        ttemp=temp;
        if(temp->data>x){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    P=new BST;
    P->data=x;
    P->left=P->right=NULL;
    if(ttemp->data>x){
        ttemp->left=P;
    }else{
        ttemp->right=P;
    }
}
void inorder(BST *P){
    if(P!=NULL){
        inorder(P->left);
        cout<<P->data<<" ";
        inorder(P->right);
    }
}
int main(){
    init();
    create_root(100);
    add_node(50);
    add_node(200);
    add_node(10);
    add_node(70);
    add_node(150);
    add_node(300);
    add_node(2);
    add_node(30);
    add_node(65);
    add_node(90);
    add_node(180);
    add_node(15);
    add_node(150);
    add_node(20);
    
    inorder(root);
}