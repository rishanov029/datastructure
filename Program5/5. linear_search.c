#include <stdio.h>

int main(){
  int inputArray[100],elementCount,counter,num;
  printf("Enter the number of elements in an array:\n");
  scanf("%d",&elementCount);
  printf("Enter %d numbers \n",elementCount);
  for(counter = 0;counter<elementCount;counter++)
  {
   scanf("%d",&inputArray[counter]);
   }
   
   printf("Enter a num to search in array \n");
   scanf("%d",&num);
   for(counter=0;counter<elementCount;counter++)
   {
    if(inputArray[counter]==num){
    printf("Number %d found at index %d \n", num,counter);
    break;
    }
    }
    
    if(counter==elementCount)
    {
     printf("Number %d not present in input array \n",num);
     }
     return 0;
     }
