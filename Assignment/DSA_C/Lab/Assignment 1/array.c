/*
Sreejit Chaudhury
008
*/
/*
Array Assignment : 
1. index, value, size
2. create array
3. return value
4. pointer in Array
5. return size
6. passing array in fxn
7. receiving array from fxn
8. 2d array
*/

#include <stdio.h>
#include <stdlib.h>
int returnSize(int *, int *);
int returnVal(int *, int, int, int, int);
int* addItself(int *arr, int, int);
int main(){
    int r, c;
    printf("Enter number of rows : ");
    scanf("%d", &r);
    printf("Enter number of columns : ");
    scanf("%d", &c);
    int arr[r][c]; // create array without pointer
    int *arr2 = (int*)malloc(r*c*sizeof(int)); // create array with pointer
    printf("Input values for array : ");
    int i, j;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            printf("Value at %d row and %d column : ",i, j);
            int x;
            scanf("%d", &x);
            *(arr2 + (i*c) + j) = x;
            arr[i][j] = x;
        }
    }
    printf("Enter row index to return : ");
    scanf("%d", &i);
    printf("Enter column index to return : ");
    scanf("%d", &j);

    printf("%d %d %d\n",arr[i][j], *(arr2 + (i*c) + j), returnVal(arr2, r, c, i, j));
    int size = returnSize(&arr[0][0], &arr[r-1][c-1]);
    printf("%d\n", size);
    int* newarr2 = addItself(arr2, r, c);
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            printf("%d ", *(newarr2 + (i*c) + j));
        }
        printf("\n");
    }
    return 0;
}
int returnSize(int *arr, int *last){
    //printf("%p %p\n", arr, last);
    return (1 + (last - arr)) ;
}    
int returnVal(int *arr, int r, int c, int i, int j){
    return *(arr + (i*c) + j);
}
int* addItself(int *arr, int r, int c){
    int i, j;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            *(arr + (i*c) + j) += *(arr + (i*c) + j);
        }
    }
    return arr;
}
