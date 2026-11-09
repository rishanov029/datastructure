#include <stdio.h>

int main(){
	int a[100];
	int m, pos, num , i;
	printf("Enter the size of array: ");
	scanf("%d",&m);
	
	printf("Enter the elements: \n");
	for(i=0;i<m;i++)
	 scanf("%d",&a[i]);
	 
	
	printf("The array of elements: \n");
	for(i=0; i < m;i++){
		printf("%d\n", a[i]);
	
	}
	printf("\n");
	printf("Enter the position: ");
	scanf("%d", &pos);
	
	
	printf("Enter the num: ");
	scanf("%d", &num);
	for (int i=m - 1; i>=pos-1; i--){
		a[i+1] = a[i];
		
	} 
	a[pos-1] = num;
	m++;
	printf("Updated array: \n");
	for(int i = 0;i< m; i++){
		printf("%d\n", a[i]);
	}
	return 0;
	
}
