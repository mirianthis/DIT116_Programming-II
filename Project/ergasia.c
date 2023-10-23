#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTRING 100

typedef struct STUDENTS
{
    int studentID;
    char studentName[MAXSTRING];
    struct STUDENTS *next;
}st;


st* Search(int studentID,st* list);
st* AddStudent(st* list,int id);
void FindStudent(st* list);
void PrintStudents(st *list);
void Save(st *list);
st* Load(st* list,int id,char name[]);
st* DeleteStudent(st* list);
st* UpdateStudent(st* list);


st* Search(int studentID,st* list)
{

    st *p;
    p=list;
    while(p!=NULL){
      if(p->studentID==studentID){
        return p;
      }
      p=p->next;
    }
    return NULL;
}

st* AddStudent(st* list,int id)
{


st* temp;
if((temp=(st*)malloc(sizeof(st)))==NULL){
  printf("couldn't allocate memory for temp!\n");
  exit(1);
}
printf("Student ID:");
scanf("%d",&id);
st* p;
if( (p = Search(id,list) )!= NULL )
{
  printf("\n");
    printf("The Student ID you provided already exist! Try a different one!\n");
    free (temp);
    return list;
}



temp->studentID=id;
printf("Student Name:");
scanf("%s",temp->studentName);
temp->next=NULL;
if(list==NULL){
list=temp;
}
else
{
  st* p;
  p=list;

  while(p->next!=NULL)
  {

    p=p->next;
  }
  p->next=temp;

}
free(temp);
printf("\nYou have added a new Student!\n");
    return list;
}



void FindStudent(st* list)
{
    int studentID;
    st *p;


    if(list==NULL){
      printf("The list is empty!");
    }
    else{
      printf("Enter ID: ");
      scanf("%d", &studentID);

    if( (p = Search(studentID,list) )!= NULL )
    {
        printf("studentName: %s\n", p->studentName);
    }

    else
    {
        printf("student not found.\n");
    }
  }
}


void PrintStudents(st *list)
{
    st *p;
    if(list==NULL){
      printf("\n");
      printf("The list is empty!\n");
    }
    else{
    printf("Student Number\t |\tStudent Name\n");
    printf("====================================\n");
p=list;
while(p!=NULL){
        printf("%d\t\t |\t%s\n", p->studentID, p->studentName);
        p=p->next;
      }
      printf("====================================\n");
    }
}


void Save(st *list)
{
    FILE* fp;

    if((fp = fopen("results.txt", "w"))==NULL){
      printf("couldn't open file!");
      exit(1);
    }

    st* cur = list;

    while (cur != NULL)
    {

        fprintf(fp, "%d\n", cur->studentID);
        fprintf(fp, "%s\n", cur->studentName);
        cur = cur->next;
    }
    fclose(fp);
    free(cur);
}

st* Load(st* list,int id,char name[]){

  st* temp;

  if((temp=(st*)malloc(sizeof(st)))==NULL){
    printf("couldn't allocate memory for temp!\n");
    exit(1);
  }

  temp->studentID=id;
  strcpy(temp->studentName,name);
  temp->next=NULL;

  if(list==NULL){
  list=temp;
  }
  else
  {
    st* p;
    p=list;

    while(p->next!=NULL)
    {

      p=p->next;
    }
    p->next=temp;
    temp->next=NULL;
  }


return list;

}


st* DeleteStudent(st* list){
if(list==NULL){
  printf("The list is empty!\n");
  return list;
}
int id;
st* loc;
printf("Give me the Student's ID:");
scanf("%d",&id);
int location=1;
loc=list;
int cnt=0;
int i=1;
st* temp;
st* first;
st* exist;
first=list;
exist=list;

while(exist!=NULL){
  if(exist->studentID==id){
    cnt=1;
  }
exist=exist->next;
}

if(cnt==0){
  printf("\n");
  printf("The Student ID you provided doesn't exist, try again!\n");
  printf("\n");
  return list;
}

while(loc->studentID != id &&loc->next != NULL){
  loc=loc->next;
  location++;

}

if(first->next==NULL){
temp=list;
  list=NULL;
  free(temp);
  printf("\nYou have succesfully deleted a Student\n");
  return list;
}


 if(location==1){
  temp=list;
  list=temp->next;
  temp->next=NULL;
  free(temp);
}
else {
  st* p;
  st* q;
  p=list;
  while(i<(location-1)){
    p=p->next;
    i++;
  }
  q=p->next;
  p->next=q->next;
  q->next=NULL;
  free(q);
}
printf("\nYou succesfully deleted a Student\n");
  return list;
}

st* UpdateStudent(st* list){
if(list==NULL){
  printf("The list is empty!\n");
  return list;
}
st* check;
st* rep;
int stid,id;
int ans;
int choice;
char name[MAXSTRING];
printf("\n");
printf("provide the Student's ID you want to change to continue:");
scanf("%d",&stid);

check=list;
ans=0;
while(check!=NULL){
  if(check->studentID==stid)
  ans=1;
  check=check->next;
}
if(ans==1)
 {
  ans=0;
  printf("\n");
  printf("\n");
printf("If you want to change only the ID press '1'\n");
printf("If you want to change only the Name press '2'\n");
printf("If you want to change both ID and Name press '3'\n");
scanf("%d",&choice);
switch(choice){

case 1:{
  printf("\n");

printf("Give me the new ID:");
scanf("%d",&id);
check=list;
while(check!=NULL){
  if(check->studentID==id){
  ans=1;
}
  check=check->next;
}
if(ans==1){
printf("\n");
  printf("\nThe Student ID you provided already exist, try again!\n");
printf("\n");
}
else{
      rep=Search(stid,list);
      rep->studentID=id;
      printf("\n");
      printf("\nYou succesfully changed the Student ID!\n");
      printf("\n");
      return list;
    }
    break;
  }
case 2:{
  printf("Give me the new Name:");
  scanf("%s",name);
  rep=Search(stid,list);
  strcpy(rep->studentName,name);
  printf("\n");
  printf("\nYou succesfully changed the Student Name!\n");
  printf("\n");
  return list;
  break;
}
  case 3:{

    printf("Give me the new ID:");
    scanf("%d",&id);
    check=list;
    while(check!=NULL){
      if(check->studentID==id){
      ans=1;
    }
      check=check->next;
    }
    if(ans==1){
printf("\n");
      printf("\nThe Student ID you provided already exist, try again!\n");
printf("\n");
}
    else{
      printf("Give me the new Name:");
      scanf("%s",name);
          rep=Search(stid,list);
          rep->studentID=id;
          strcpy(rep->studentName,name);
          printf("\n");
          printf("You succesfully changed both Student ID and Name!");
          printf("\n");
          return list;
        }
break;
  }
}
}
else{
printf("\n");
printf("\nThe Student ID you provided doesnt exist! Try again!\n");
printf("\n");
}
return list;


}

int main(void)
{
  printf("WELCOME");
  int uniqe=0;
  st* list;
  int stid;
  list=NULL;
    int code;
    FILE* fp;


    if (!(fp = fopen("results.txt", "r")))
    {
      printf("\n");
        printf( "The file does not exist, I am creating a text file with the name: result \n");
       fp=fopen("results.txt","w");
       fclose(fp);
       fp=fopen("results.txt","r");
    }


    int counter=0;
    int id;
    char name[100];

    while((fscanf(fp,"%d\n%s",&id,name))!=EOF){

    list=Load(list,id,name);
    counter++;
    }

    fclose(fp);

if(list==NULL){
  printf("\n");
  printf("There isn't any student registered in the list yet,\nadd a new students by pressing '1'\n");
  printf("\n");
}

    for (;;)
    {
        printf("Enter the code: \n");
        printf("1 -ADD NEW STUDENT DETAILS- \n");
        printf("2 -SEARCH STUDENT DETAILS- \n");
        printf("3 -DISPLAY REPORT OF ALL STUDENTS- \n");
        printf("4 -DELETE STUDENT DETAILS- \n");
        printf("5 -CHANGE STUDENTS DETAILS- \n");
        printf("6 -EXIT- \n");
        scanf(" %d", &code);

        switch (code)
        {
            case 1:
              list = AddStudent(list,stid);
Save(list);
list=NULL;
if (!(fp = fopen("results.txt", "r")))
{
  printf("\n");
    printf( "The file does not exist, I am creating a text file with the name: result \n");
   fp=fopen("results.txt","w");
   fclose(fp);
   fp=fopen("results.txt","r");
}


int counter=0;
int id;
char name[100];

while((fscanf(fp,"%d\n%s",&id,name))!=EOF){

list=Load(list,id,name);
counter++;
}

fclose(fp);
                break;

            case 2:
            FindStudent(list);
                break;

            case 3:
            printf("\n");
                PrintStudents(list);
                break;


            case 4:
            {
           list=DeleteStudent(list);
Save(list);


                break;
          }

          case 5:
          {
            list=UpdateStudent(list);
Save(list);

            break;
          }

            case 6:
            {

              exit(1);
            }

            default:
                printf("False code\n");
        }

        printf("\n");
    }
    free(list);

return 0;
}
