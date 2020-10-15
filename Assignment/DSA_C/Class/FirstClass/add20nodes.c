/*
Sreejit Chaudhury, 008
*/

# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    struct Node *head;
    struct Node *currNode;
    int i = 0;
    for(i; i < 20; i++){
        int newData;
        printf("Enter data of %d node : ", i+1);
        scanf("%d", &newData);
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->data = newData;
        newNode->next = NULL;
        if(i == 0){
            head = newNode;

        }
        else{
            currNode->next = newNode;
        }
        currNode = newNode;
    }

    printf("Output : ");
    currNode = head;
    i = 1;
    while(currNode != NULL){
        printf("Data stored at Node %d : %d\n", i, currNode->data);
        i ++;
        currNode = currNode->next;
    }
    return 0;
}