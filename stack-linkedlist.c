#include<stdio.h>
#include<stdlib.h>
//Stack is LIFO, last in first out      
//Using singly linked list either we can insert either from the beginning or from the end.
//Time Complexity= O(n)---- Beginning
//Time complexity= O(1)---- End {Bcz we need to traverse the linked list from the begg till the end}  
typedef struct Node{
    int data;
    struct Node* nextptr;
}Node;
/// @brief This structure will be used to create the linked list.
Node* head= NULL;
Node* newnode(){
    Node* temp= (Node*) malloc(sizeof(Node));
    temp-> nextptr= NULL;
    return temp;
}
void push(int data){ // Insertion at the begg
    Node* temp= newnode();
    temp->data= data;
    if(head== NULL)
        head= temp;
    else{
        temp->nextptr= head;
        head= temp;
    }
}
void pop(){ //Deletion from the begg
    Node* ptr= head;
    if(head== NULL)
        return;
    head= ptr->nextptr;
    free(ptr);
}
void printstack(){
    Node* ptr= head;
    while(ptr != NULL){
        printf("\n%d", ptr->data);
        ptr= ptr->nextptr;
    }
}
void peek(){
    printf("\n%d", *(head));
}
int main(){
    push(20);
    push(30);
    push(34);
    pop();
    push(56);
    peek();
    printstack();
}