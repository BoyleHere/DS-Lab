#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* insert(Node* head, int data);
Node* insertBefore(Node* head, int data, int data2);
//Node* insertAfter(Node* head, int data, int data2);
//Node* delete(Node* head, int data);
Node* reverse(Node* head);
//Node* sort(Node* head);
//Node* deleteAlt(Node* head);
//Node* insertSorted(Node* head, int data);
void display(Node* head);

int main(){
    Node* head = NULL;
    int ch, data, data2;
    do
    {
        printf("1.insert\n2. Insert after\n3. insert before\n4. delete\n5.reverse\n6.sort\n7. delete alt\n8.insert in sorted\n9. display\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element: \n");
            scanf("%d",&data);
            head = insert(head, data);
            //display(head);
            break;
        case 2:
         /*   printf("Enter element to insert: ]n");
            scanf("%d",&data);
            printf("Enter the element after which you want to insert: \n");
            scanf("%d",&data2);
            insertAfter(head, data, data2);
            display(head);*/
            break;
        case 3:
            printf("Enter element to insert: \n");
            scanf("%d",&data);
            printf("Enter the element before which you want to insert: \n");
            scanf("%d",&data2);
            head = insertBefore(head, data, data2);
            //display(head);
            break;
        case 4:
        /*    printf("Enter element to delete: \n");
            scanf("%d", &data);
            delete(head, data);
            display(head);*/
            break;
        case 5:
            printf("reversing...\n");
            reverse(head);
            //display(head);
            break;
        case 6:
            /*printf("sorting...\n");
            sort(head);
            display(head);*/
            break;
        case 7:
            /*printf("deleting alt...\n");
            deleteAlt(head);
            display(head);*/
            break;
        case 8:
            /*printf("Enter element to insert in sorted list: \n");
            scanf("%d",&data);
            insertSorted(head, data);
            display(head);*/
            break;
        case 9:
            display(head);
            break;
        
        default:
        printf("Enter correct option!\n");
            break;
        }
    } while (ch!=10);
    
    return 0;
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Node* insert(Node* head, int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }else{
        Node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
    
}


Node* insertBefore(Node* head, int data, int data2){
    if(head == NULL){
        printf("Inserting normally as no other element is present!\n");
        return insert(head, data);
    }else{
        Node* current = head;
        while(current->next!=NULL && current->data!=data2){
            current = current->next;
        }
        if(current->data==data2){
            Node* prev = head;
            while(prev->next!=current){
                prev = prev->next;
            }
            prev->next = createNode(data);
            prev->next->next = current;
        }else if (current->next==NULL){
            printf("Given element is not present! Inserting at end.\n");
            return insert(head,data);
        }
        return head;
    }
}


//Node* insertAfter(Node* head, int data, int data2);


//Node* delete(Node* head, int data);


Node* reverse(Node* head){
    Node* temp2 = NULL;
    Node* temp = NULL;
    while (head != NULL){
        temp2 = head->next;
        head ->next = temp;
        temp = head;
        head = temp2;
    }
    //head = temp;
    return head;
}
//Node* sort(Node* head);


//Node* deleteAlt(Node* head);


//Node* insertSorted(Node* head, int data);


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


