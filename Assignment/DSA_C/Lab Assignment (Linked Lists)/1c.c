/*
SREEJIT CHAUDHURY
008
*/
/*
1.Implement the following functions for circular linked list. 
– isEmpty
– getLength
– insert
– delete
– Lookup

*/

# include  <stdio.h>
# include  <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node* link;

int isEmpty(link);
int getLength(link);
link insert(link,int);
link delete(link,int);
void lookup(link, int); 

int main(){
    link head = NULL;
    int input = 100;
    while(input != 0){
        printf("Insert : \n1 to check if list is empty\n2 to check the length of the current list\n3 to insert a node\n4 to delete a node\n5 to lookup the list\nany other number to exit the loop\n");
        printf("Insert  a value : ");
        scanf("%d",&input);
        if(input == 1){
            if(isEmpty(head) == 1){
                printf("List is currently empty\n");
            }
            else{
                printf("List is currently not empty\n");
            }
        }
        else if(input == 2){
            printf("Current length of list : %d\n",getLength(head));
        }
        else if(input == 3){
            int data;
            printf("Enter data to insert : ");
            scanf("%d",&data);
            head = insert(head,data);
        }
        else if(input == 4){
            int data;printf("Enter data to delete : ");
            scanf("%d",&data);
            head = delete(head,data);
        }
        else if(input == 5){
            int data;
            printf("Enter data to lookup : ");
            scanf("%d",&data);
            printf("Lookup : ");
            lookup(head, data);

        }
        else{
            printf("Exiting loop\n");
            break;
        }
        printf("\n");
    }
    return 0;
}

int isEmpty(link head){
    if(head == NULL){
        return  1;
    }
    else{
        return 0;
    }
}
int getLength(link head){

    //printf("%d\n",head->data);
    if(head == NULL){
        return 0;
    }
    else if(head->next == head){
        return 1;
    }
    link temp = head->next;
    int len = 1;
    while(temp != head ){
        //printf("%d\n",temp->data);
        
        len++;
        temp = temp->next;
    }

    return len;
}

link insert(link head, int data){
    link newNode = (link)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        head -> next = head;
        
    }
    else{
        link temp = head;
        while(temp -> next != head){
            temp = temp -> next;
            //printf("%d ",temp -> data);
        }
        temp -> next = newNode;
        newNode->next  = head;
    
    }
    printf("%d is inserted in list\n",data);
    return head;
}


link delete(link head,int data){
    
    if(head == NULL){
        printf("Empty list. Nothing to delete.\n");
    }
    else if(head -> data == data){
        link delNode = head;
        if(getLength(head) == 1){
            head = NULL;
        }
        else{
            link temp = head->next;
            while(temp->next != head){
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        }
        free(delNode);

    }
    else{
        link temp = head;
        while(temp->next != head){
            if(temp->next->data == data){
                break;
            }
            temp = temp->next;
        }
        if(temp->next == head){
            printf("Node containing data %d is not present in list\n",data);
        }
        else {
            link delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
            printf("Node containing data %d is deleted",data);
        }
    }
    return head;
}
void lookup(link head, int data){
    link temp = head->next;
    int count = 1, check = -1;
    if(head->data == data){
        check = count;
    }
    else{
        count ++;
        while(temp != head){
            if(temp->data == data){
                check = count;
                break;
            }
            temp = temp->next;
            count ++;
        }
    }
    if(check != -1){
        printf("Searched data present in node at index %d", check);
    }
    else{
        printf("Searched data not present in list");
    }
    
    printf("\n");
}
