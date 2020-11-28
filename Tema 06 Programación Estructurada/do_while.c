#include<stdio.h>
#include<stdlib.h>

void main () {
	float sumaTotal = 0;
	float valor;
	char resp;
	do {
		printf ("Introducir el valor a sumar");
		scanf ("%f", &valor);
		sumaTotal += valor;
		printf ("Desea continuar sumando valores (s/n)?: ");
		scanf ("%c", &resp);
	} while (resp == 's' || resp == 'S');
	printf ("El valor de la suma es %f\n", sumaTotal);
}
