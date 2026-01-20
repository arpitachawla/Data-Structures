#include<stdio.h>
#include<stdlib.h>
// In queue we maintain 2 pointers front and rear
//Front ptr always points to the first element in the list and rear always points to the second element
//Queue works on FIFO(First In First Out)
//Element is added from the rear(back) side and is deleted from the front side
typedef struct Node
{
    int data;
    struct Node* next;
} node;
node* front= NULL;
node* rear= NULL;
node* newnode(int data){
    node * temp= (node*) malloc(sizeof(node));
    temp->data= data;
    temp->next= NULL;
    return temp;
}
void enqueue(int data){  //Insertion at the end
    node* temp= newnode(data);
    if(rear==NULL){
        rear= temp;
        front= temp;
    }
    else{ //Traversal is only needed when I don't trust my rear pointer 
    //Rear pointer will always point to last node
        rear->next= temp;
        rear= temp;
    } 
}
void dequeue(){
    //Case-1: When the front is null
    if(front ==NULL){
        rear= NULL;
        return;
    }
    node* temp= front;
    front= front->next;
    free(temp);
    if(front==NULL){ //Cross-checking that after the deletion rear must set to 0 in case when there is no element present
            rear= NULL;
    }
}
void display(){
    node* temp= front;
    while(temp!=NULL){
        printf("%d  ", temp->data);
        temp= temp->next;
    }
}
int main(){
    int input=0;
    int data;
    while(1){
        printf("\nEnter the number for the corresponding operation::");
        printf("\n Press 1 to enqueue(insert) data inside the queue");
        printf("\n Press 2 to dequeue(delete) data inside the queue");
        printf("\n Press 3 to display the queue");
        printf("\n Press 4 to exit\n");
        scanf("%d", &input);
        if(input==1){
            printf("Enter data::");
            scanf("  %d", &data);
            enqueue(data);
        }
        else if(input==2){
            dequeue();
        }
        else if(input==3){
            display();
        }
        else if(input==4){
            break;
        }
    }
}

