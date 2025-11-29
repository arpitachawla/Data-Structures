#include<stdio.h>
#include<stdlib.h>
//Creating a singly linked list and even transversing it insertion at end, beg
typedef struct node1 {
    int data;
    struct node1 *link;
} node;
node* head;
node* newnode();
void insertEnd(int x);
void insertBeg(int x);
void print();
int main() {
    head= NULL;
    int x,n;
    scanf("%d", &n); // Taking the value of n
    for(int i=0; i<n; i++){
        printf("Enter the data to enter:\n");
        scanf("%d", &x);
        insertBeg(x);
    }
    print();
}
node* newnode(){
    node *temp= (node*) malloc(sizeof(node));
    return temp;
}
void insertEnd(int x){
    node *temp= newnode();
    temp->data=x;
    temp->link=NULL;
    if(head == NULL) head= temp;
    else{
        node* ptr= head;
        while(ptr->link!= NULL){
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}
void print(){
    node * temp1= head;
    while(temp1!= NULL){
        printf("%d\n", temp1->data);
        temp1= temp1->link;
    }
}
void insertBeg(int x){
    node * temp= newnode();
    temp->data=x;
    temp->link=head;
    head= temp;
}

