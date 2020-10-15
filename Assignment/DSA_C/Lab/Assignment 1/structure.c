/*
Sreejit Chaudhury 
008
/*
1.Create
2.Structure pointer (.,->)
3.Passing structure to function
4.Receiving structure from function
*/
# include <stdio.h>
# include <stdlib.h>

struct job{
    int salary;
    char level;
};
struct job* increasSal(struct job*, int);
int main(){
    struct job sde;
    sde.salary = 25;
    sde.level = 'D';
    printf("SDE Salary : %d Level : %c\n", sde.salary, sde.level);
    struct job *ceo = (struct job *)malloc(sizeof(struct job));
    ceo ->salary = 100;
    ceo ->level =  'A';
    ceo = increasSal(ceo, 50);
    printf("CEO new Salary : %d\n",ceo->salary);
    free(ceo);
    return 0;
}

struct job* increasSal(struct job* anyJob, int amm){
    anyJob ->salary += amm;
    return anyJob;
}