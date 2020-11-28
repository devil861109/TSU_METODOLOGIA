#include<stdio.h>
#include<stdlib.h>

int main() {
	int num1=0, num2=0, mayor=0;
	printf("Introduzca dos números enteros\n");
	scanf("%d%d",&num1,&num2);
	mayor = (num1 >= num2 ? num1 : num2);
	printf("El número mayor es %d\n",mayor);

	return 0;
}
