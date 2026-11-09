#include<stdio.h>
#include<stdlib.h>
#define Size 5
int Top=-1,array[size];
void Push();
void Pop();
void show();
int main()
{
int choice;
while(1)
{
printf("\n operation performed by stack");
printf("\n1 push the element \n2 pop the element \n3 show \n4 end");
printf("\n\n enter the choiche");
scanf("%d",&choice);
switch(choice)
{
case 1:Push();
break;
case 2:Pop();
break;
case 3:show();
break;
case 4:exit(0);
default:printf("\n invalid choice!!");
}}}
void Push()
{
int x;




