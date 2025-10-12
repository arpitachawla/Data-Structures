#include<stdio.h>
#define MAX_SIZE 100
int A[MAX_SIZE];  //Global pointer so that i can use this one everywhere in every function
int top=-1; //Global variable to point at the top of the stack
void push(int x){
    if(top==MAX_SIZE-1){
        printf("STACK OVERFLOW\n");
        return;
    } 
    else {
        top= top+1;
        A[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("Nothing to remove::\n Stack underflow");
    }
    else{
        top=top-1;
    }
}
int isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int peek(){
    return A[top];
}
void print(){
    for(int i=0; i<=top; i++){
        printf("%d\n", A[i]);
    }
}
int main(){
    int y;
    push(2); 
    print();
    push(9);
    print();
    push(13);
    print();
    pop();
    print();
    y= peek();
    printf("%d", y);
}
