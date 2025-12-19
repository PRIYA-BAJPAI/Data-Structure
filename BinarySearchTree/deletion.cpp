#include<iostream>
using namespace std;
struct BST{
    int data;
    BST *left;
    BST *right;
};
BST *root,*temp,*ttemp,*P,*Q;
void init(){
    root=temp=ttemp=P=Q=NULL;
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

void deleteNode(int x){
    temp=root;
    while(temp!=NULL && temp->data!=x){
        ttemp=temp; //ttemp is parent of temp
        if(temp->data<x){
            temp=temp->right;
        }else{
            temp=temp->left;
        }
    }
    if(temp==NULL){
        cout<<"Node not found."<<endl;
        return;
    }

    //if left and right of the node to be deleted is null
    if(temp->left==NULL && temp->right==NULL){
        if(temp==root){
            delete root;
            root=NULL;
        }else if(temp==ttemp->right){
            ttemp->right=NULL;
            delete temp;
        }else{
            ttemp->left=NULL;
            delete temp;
        }
    }else
    //right=NULL and left!=NULL
    if(temp->left!=NULL && temp->right==NULL){
        P=temp->left;
        temp->left=NULL;
        if(temp==root){
            root=P;
        }else if(temp==ttemp->right){                     
            ttemp->right=P;
            delete temp;
        }else{
            ttemp->left=P;
            delete temp;
        }
    }else
    //left=NULL and right!=NULL
    if(temp->left==NULL && temp->right!=NULL){
        P=temp->right;
        temp->right=NULL;
        if(temp==root){
            root=P;
        }else if(temp==ttemp->right){
            ttemp->right=P;
            delete temp;
        }else{
            ttemp->left=P;
            delete temp;
        }
    }else{
        //neither NULL on right nor in left
        Q=temp;
        P=temp->right;
        while(P->left!=NULL){
            Q=P;
            P=P->left;
        }
        temp->data=P->data;
        Q->left=P->right;
        P->right=NULL;
        delete P;
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
    deleteNode(10);
    cout<<endl<<"After deletion : "<<endl;
    inorder(root);
}