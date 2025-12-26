#include<iostream>
using namespace std;
struct BST{
    int data;
    int height;//
    BST *left;
    BST *right;
};
BST *root,*temp,*ttemp,*P,*Q;
void init(){
    root=temp=ttemp=P=Q=NULL;
}

int height(BST *root){
    if(root == NULL) return 0;
    return root->height;
}

int getBalance(BST *root){
    if(root==NULL){
        return 0;
    }
    return height(root->left)-height(root->right);//
}

int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

void right_rotation(int x){
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
    if(P==NULL || P->left == NULL){
        cout<<x<<" not found"<<endl;
        return;
    }
    Q=P->left;
    temp=Q->right;
    Q->right=P;
    P->left=temp;
    P->height=max(height(P->left),height(P->right))+1;//
    Q->height=max(height(Q->left),height(Q->right))+1;//
    if(ttemp==NULL){
        root=Q;
    }else if(P==ttemp->left){
        ttemp->left=Q;
    }else{
        ttemp->right=Q;
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
    if(P==NULL || P->right==NULL){
        cout<<x<<" not found"<<endl;
        return;
    }
    Q=P->right;
    temp=Q->left;
    Q->left=P;
    P->right=temp;
    P->height=max(height(P->left),height(P->right))+1;//
    Q->height=max(height(Q->left),height(Q->right))+1;//
    if(ttemp==NULL){
        root=Q;
    }else if(P==ttemp->left){
        ttemp->left=Q;
    }else{
        ttemp->right=Q;
    }
}

BST *create_node(int x){
    BST *n=new BST;
    n->data=x;
    n->left=n->right=NULL;
    n->height=1;
    return n;
}

void insert(int x){
    if(root==NULL){
        root=create_node(x);
        return;
    }
    temp=root;
    ttemp=NULL;
    while(temp!=NULL){
        ttemp=temp;
        if(x<temp->data){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    P=create_node(x);
    if(x<ttemp->data){
        ttemp->left=P;
    }else{
        ttemp->right=P;
    }
    Q=root;
    while(Q!=NULL){
        Q->height=1+max(height(Q->left),height(Q->right));
        int bal=getBalance(Q);
        if(bal==2){
            if(getBalance(Q->left)==1){
                right_rotation(Q->data);
            }else{
                left_rotation(Q->left->data);
                right_rotation(Q->data);
            }
            break;
        }
        if(bal==-2){
            if(getBalance(Q->right)==-1){
                left_rotation(Q->data);
            }else{
                right_rotation(Q->right->data);
                left_rotation(Q->data);
            }
            break;
        }
        if(x<Q->data){
        Q=Q->left;
    }else{
        Q=Q->right;
    }
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
    insert(8);
    insert(5);
    insert(6);
    insert(1);
    insert(3);
    insert(7);
    insert(30);
    insert(15);
    insert(10);
    insert(90);
    insert(35);
    insert(12);
    cout<<"Inorder -> ";
    inorder(root);
    cout<<"\nPreorder -> ";
    preorder(root);
    cout<<"\nPostorder -> ";
    postorder(root);
}