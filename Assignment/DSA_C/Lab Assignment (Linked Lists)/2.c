
/*
SREEJIT CHAUDHURY
008
*/


/*
Insert a node into a sorted singly linked lists at the correct position
*/


#include  <stdio.h>
#include  <stdlib.h>
# include <time.h>

struct Node {
    int data;
    struct Node * next;
};

typedef struct Node* link;

link createSortedList(link,int);
link insertNode(link,int);
void printList(link);

int main(){
    srand(time(NULL));
    link head = NULL;
    int length = (rand() % 10) + 1;
    head = createSortedList(head,length);
    printf("List initially : ");
    printList(head);
    head = insertNode(head,rand()%((length+ 2)* 10));
    printf("List after insertion : ");
    printList(head);
    return 0;
}

link createSortedList(link head,int len){
    int num = 10;
    int i = 0;
    link temp = NULL;
    for(i; i< len; i++){
        link newNode = (link)malloc(sizeof(struct Node));
        newNode -> data = num + (i * 10);
        newNode -> next = NULL;
        if(temp == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp -> next = newNode;
            temp = temp -> next;
        }
    }
    return head;
}

void printList(link head){
    link temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp -> next;
    }
    printf("\n");
}

link insertNode(link head, int data){
    printf("Data to insert : %d \n", data);
    link newNode = (link)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(head == NULL || head->data >= data){
        newNode->next = head;
        head = newNode;
    }
    else{
        link temp = head;
        int check = -1;
        while(temp -> next != NULL){
            if(temp->next->data >= data){
                newNode -> next = temp -> next;
                temp -> next = newNode;
                check = 1;
                break;
            }
            temp = temp -> next;
        }

        if(check == -1){
            temp -> next = newNode;
        }
        
    }
    return head;
}