#include<stdio.h>
#include<stdlib.h>

//Aqui va el prototipo
int factorial(int n);

int main () {
	int valor, fact;
	int cont = 0;
	do {
		printf ("Introducir un numero entero positivo (para salir 0)");
		scanf("%d", &valor);
		if (valor>0) {
			fact = factorial (valor);
			printf ("El factorial de %d es %d \n", valor, factorial);
			cont++;
		}
	} while (valor>0);
	printf ("Han sido calculados %d valores \n", cont);
	
	return 0;
}

int factorial(int n) {
	if (n>1) {
		return n*factorial(n-1);
	} else {
		return 1;
	}
}
