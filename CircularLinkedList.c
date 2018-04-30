#include <stdio.h>
#include <stdlib.h> 
typedef struct node{
    
    int data;
    struct node *next;
    struct node *prev;
    
}Node;

Node *Top=NULL;
Node *Bottom=NULL;

void enque(Node *s,int d){
    
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(Top==NULL){
        
        Top=temp;
        Bottom=temp;
        Bottom->next=Top;
        Top->prev=Bottom;
    }else{
        Bottom->next=temp;
        temp->prev=Bottom;
        Bottom=temp;
        temp->next=Top;
        
        
    }
    
}


int main() {
	
	Node *st;
	enque(st,1);
	enque(st,2);
	enque(st,3);
	enque(st,4);
	enque(st,5);
    int del;
    del=5;
    
    Node *temp;
    temp=Top;
    
    while(temp->data!=del){
        
        temp=temp->next;
        
    }
    
    if(temp==Top){
        
        Top=temp->next;
        
    }else{
        
        if(temp==Bottom){
            
            Bottom=temp->prev;
        }
        
    }
    Node *pre,*nex;
    pre=temp->prev;
    pre->next=temp->next;
    nex=temp->next;
    nex->prev=pre;

    
    temp->next=NULL;
    temp->prev=NULL;
    free(temp);
    temp=Top;
    while(temp!=Bottom){
        
        printf("%d\n",temp->data);
        temp=temp->next;
        
    }
    printf("%d\n",temp->data);
	return 0;
}