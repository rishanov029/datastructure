#include <stdio.h>
#define MAX_SIZE  10
void getArray(int arr[],int size);
int main()
{
 int arr[MAX_SIZE];
 int i;
 getArray(arr,MAX_SIZE);
 printf("Array outside functioon is:\n");
 for(i=0;i<MAX_SIZE;i++){\
 printf("%d",arr[i]);
 }
 return 0;
 }
 void getArray(int arr[],int size)
 {
 int i;
 printf("Enter the elements in array:\n");
 for(i=0;i<size;i++)
 {
 scanf("%d",&arr[i]);
 }
 printf("Array inside function:\n");
 for(i=0;i<size;i++)
 {
 printf("%d",arr[i]);
 }
 }
