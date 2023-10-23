#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSTRING 100

typedef struct{
   char name[MAXSTRING];
   int id;
}student;

void findStudent(int id){
    int i;
    for(i=0;i<MAXSTRING;i++){
        if(student[i].id==id)
            printf("The student you were looking for is:%s",student[i].name);
}


}

int main(){
    FILE fp*=fopen("results.txt","r");






return 0;
}
