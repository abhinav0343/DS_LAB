#include<stdio.h>
#include<stdlib.h>
struct student
{
    float marks;
    char name[50];
    int roll;
};
 int main()
 {
    int n;
    printf("enter the number of students\n");
    scanf("%d",&n);
    struct student aih[n];
    printf("enter the details of the students\n");
    for(int i=0;i<n;i++)
    {
      getchar(); //clears new line buffer 
      printf("enter the name of the student\n");
      fgets(aih[i].name,sizeof(aih[i].name),stdin);
      printf("enter the roll number of the student\n");
      scanf("%d",&aih[i].roll);
      printf("enter the marks of the student\n");
      scanf("%f",&aih[i].marks);
    }
    printf("====================================\n");
    printf("details of the students \n");
    for(int i=0;i<n;i++)
    {
        printf("name of the student : %s",aih[i].name);
        printf("Roll number : %d\n",aih[i].roll);
        printf("marks of the student : %f\n",aih[i].marks);
        printf("====================================\n");
    }
    return 0;
 }