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

void left_rotation(int x){
    P=root;
    ttemp=NULL;
    while(P!=NULL && P->data!=x){
        ttemp=P;
        if(x>P->data){
            P=P->right;
        }else{
            P=P->left;
        }
    }
    if(P==NULL ){
        cout<<x<<" not found"<<endl;
        return;
    }
    Q=P->right;
    temp=Q->left;
    Q->left=P;
    P->right=temp;
    if(ttemp==NULL){
        root=Q;
    }else if(P==ttemp->left){
        ttemp->left=Q;
    }else{
        ttemp->right=Q;
    }
}

void inorder(BST *P){
    if(P!=NULL){
        inorder(P->left);
        cout<<P->data<<" ";
        inorder(P->right);
    }
}

void preorder(BST *P){
    if(P!=NULL){
        cout<<P->data<<" ";
        preorder(P->left);
        preorder(P->right);
    }
}

void postorder(BST *P){
    if(P!=NULL){
        postorder(P->left);
        postorder(P->right);
        cout<<P->data<<" ";
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
    left_rotation(100);
    cout<<endl<<"After rotation : "<<endl;
    cout<<"inorder : ";
    inorder(root);
    cout<<endl;
    cout<<"preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"postorder : "; 
    postorder(root);
}