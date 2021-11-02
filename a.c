#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 10

void f(char arr[]){
	printf("arr_size:%d\n",sizeof(arr));
}
int main(){
	char arrA[ARR_SIZE];
	char *arrB = (char*) malloc( sizeof(char) * ARR_SIZE );
	printf("arr_size:[%d &%d]\n",sizeof(arrA), sizeof(arrB) );
	f(arrA);
	f(arrB);


	char *p = (char*)malloc(10);
}
