#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    /* data */
    int data;
    struct Node *next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data){
    Node* newNode = createNode(data);
    if (head==NULL){
        head = newNode;
    }
    else{
        Node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

Node* deleteNode(Node* head, int data){
    if (head == NULL){
        printf("There is nothing to delete!");
        return NULL;
    }
    
        Node* current = head;
        Node* prev = NULL;
        while(current->next!=NULL && current->data!=data){
            prev = current;
            current = current->next;
        }
        if (current == NULL){
            printf("Element not found\n");
        }
        if (prev == NULL){
            head = current->next;
        }else{
            prev->next = current->next;
        }
        free(current);
        printf("Element has been deleted\n");
        return head;
    
}

void display(Node* head){
    if (head == NULL){
        printf("List is empty!\n");
        return;
    }
    Node* current = head;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    int n, data;
    Node* head = NULL;
    do{
        printf("Enter choice: \n1. Insert Element \n2. Delete element \n3. Display the list\n4.Exit\n");
        
        scanf("%d",&n);
        
        switch (n)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            head = insertNode(head, data);
            break;
        
        case 2:
            printf("Enter value: ");
            scanf("%d", &data);
            head = deleteNode(head, data);
            break;

        case 3:
            display(head);
            break;

        case 4:
        printf("Exiting\n");
            break;

        default:
            printf("Enter a number from the choices given\n");
            break;
        }
        
    }while(n!=4);
    return 0;
}
