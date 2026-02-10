#include <stdio.h>
#include <stdlib.h>

//Structure
struct NODE {
    int data;
    struct NODE *prev;
    struct NODE *next;
};
//CreateNode

struct NODE* createNode(int value){
    struct NODE *newNode = (struct NODE*) malloc(sizeof(struct NODE));

    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
//InsertEnd

struct NODE* insertEnd(struct NODE *head,int value){
    struct NODE *newNode = createNode(value);

    if(head ==NULL){
        return newNode;
    }
    struct NODE *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;
    return head;
}

//display
void display(struct NODE *head){

    struct NODE *temp = head;
    printf("NULL <->");
    while(temp!=NULL){
        printf("%d <->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
//reverse
struct NODE* reverseList(struct NODE *head){
    if(head == NULL){
        return head;
    }
    struct NODE *prev = NULL,*next = NULL;
    struct NODE * temp = head;
    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next; 
    }

    return prev;

}


//main
int main(){
    struct NODE *head = NULL;

    int n,value;

    printf("How many nodes? ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the value: ");
        scanf("%d",&value);
        head = insertEnd(head,value);
    }
    
    printf("Doubly Linked list\n");
    display(head);
    head = reverseList(head);
    printf("Reversed List\n");
    display(head);
    return 0;
}
