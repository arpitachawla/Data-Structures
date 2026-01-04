#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
int arr[MAX_SIZE];
int rear=-1;  // will be used for inserion
int front=-1; // will be used for deletion
bool isEmpty(){
    if(rear==-1 && front==-1)
        return true;
    else return false;
}
bool isFull(){
    if(rear== MAX_SIZE-1)
        return true;
    else return false;
}
void enque(int data){
    if(isFull()== true)
        return;
    if(isEmpty()==true){
         front=0;
    }
    rear++;
    arr[rear]= data;
}
void deque(){
    if(isEmpty()==true){
        return;
    }
    if(front== rear){
        front=-1;
        rear=-1;
        return;
    }
    front++;
}
int main(){
    enque(26);
    enque(78);
    deque();
    if(isEmpty())
        printf("Queue is empty");
    else
        printf("Queue is not empty");
    enque(1);
    enque(8);
    for(int i= front; i<=rear; i++){
        printf("\n%d", arr[i]);
    }
}
