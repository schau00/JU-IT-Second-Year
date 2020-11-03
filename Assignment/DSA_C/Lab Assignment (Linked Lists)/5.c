/*
SREEJIT CHAUDHURY
008
*/


/*
Concatenate two circular linked lists.
*/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* link;

link concat(link, link);
link createList(link, int);
void printList(link);

int main(){
    srand(time(NULL));
    link head1 = NULL, head2 = NULL;
    head1 = createList(head1, 5);
    head2 = createList(head2, 7);
    printf("List 1 : ");
    printList(head1);
    printf("List 2 : ");
    printList(head2);
    head1 = concat(head1, head2);
    printf("List 1 after concatenating List 2 at end : ");
    printList(head1);
    head2 = concat(head2,head1);
    printf("List 2 after concatenating List 1 at end : ");
    printList(head2);
    return 0;
    
}

link createList(link head, int len){
    // create a link list of length len containing random integers between 0 - 99
    link temp = NULL;
    int i = 0;
    for(i; i < len; i++){
        link newNode = (link)malloc(sizeof(struct Node));
        newNode -> data = rand()%100;
        newNode -> next = NULL;
        if(i == 0){
            head = newNode;
            temp = newNode;
            head -> next = head;
        }
        else{
            temp -> next = newNode;
            temp = newNode;
            temp -> next = head;
        }
    }
    return head;
}

void printList(link head){
    link temp = head;
    while(temp -> next != head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
    return;
}

link concat(link h1, link h2){
    //appends h2 at end of h1
    link temp = h1;
    while(temp->next != h1){
        temp = temp -> next;
    }
    link temp2 = h2;
    while(temp2 ->next != h2){
        link newNode  = (link)malloc(sizeof(struct Node));
        newNode -> data = temp2 -> data;
        newNode -> next  = NULL;
        temp -> next = newNode;
        temp = temp->next;
        temp2 = temp2 -> next;
    }
    link newNode  = (link)malloc(sizeof(struct Node));
        newNode -> data = temp2 -> data;
        newNode -> next  = NULL;
        temp -> next = newNode;
        temp = temp -> next;
        temp -> next = h1;
    return h1;
}