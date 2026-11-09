#include <stdio.h>

void main(){
	int integer[2][3][2];
	printf("Enter 12 values: \n");
	for(int i=0;i<2;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<2;++k){
				scanf("%d", &integer[i][j][k]);
				
				}
		}
	}
	
	printf("\nDisplaying values: \n");
	for(int i=0;i<2;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<2;++k){
				printf("Integer [%d][%d][%d] = %d\n",i,j,k, integer[i][j][k]);
				
				}
		}
	}
	
}

