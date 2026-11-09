#include<stdio.h>
struct student{
char name[10];
int roll;
};
void show(struct student st);
void main()
{
struct student std;
printf("\nenter student record \n");
printf("\n student name \t");
scanf("%s",std.name);
printf("n enter student rollno. \t");
scanf("%d",&std.roll);
show(std);
}
void show(struct student st){
printf("\n student name is %s ",st.name);
printf("\n roll is %d",st.roll);
}

