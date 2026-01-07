#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{ // Node of the binary search tree
    int data;
    struct Node* leftptr;
    struct Node* rightptr;
} node;
node* newnode(){
    node* temp= (node*)malloc(sizeof(node));
    temp->leftptr= NULL;
    temp-> rightptr= NULL;
}
node* insert( node* root, int data){         
    if(root==NULL)
        root= newnode() 
        root->data= data;
    else-if(data<= root->data){
        root->left= insert(root->left, data);
    }
    else root->right= insert(root->right, data);
    return root;
}
bool search(node* root ,int target){
        if(root==NULL){
            return false;
        }
        else if(root->data==target) return true;
        else if(target<=root->data){
            return search(root->left, target);
        }
        else{
            return search(root->right, target);
        }
}
int main(){
    node* root= NULL;
    root= insert(root,15);
    root= insert(root,45);
    root= insert(root, 34);
    root= insert(root,87);
    root= insert(root,67);
    root= insert(root,23);
    int target= 67;
    if(search(root,67)==true){
        printf("Number found!!\n");
    }
    else printf("Not found");
}