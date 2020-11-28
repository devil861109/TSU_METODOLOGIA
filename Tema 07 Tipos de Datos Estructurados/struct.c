#include<stdio.h>
#include<stdlib.h>

struct persona{
	char nombre[25];
	int edad;
	float salario;
} empleado;

void main ( ) {
	printf ("Introducir nombre: ");
	gets (empleado.nombre);
	printf ("Introducir edad: ");
	scanf ("%d", &empleado.edad);
	printf ("Introducir salario: ");
	scanf ("%f", &empleado.salario);
	/*Recuperando informacion de la variable empleado*/
	printf ("Nombre %s\n", empleado.nombre);
	printf ("Edad %d\n", empleado.edad);
	printf ("Salario %.2f\n", empleado.salario);
}
