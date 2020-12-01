#include<stdio.h>
#include<stdlib.h>

struct persona{
	char nombre[25];
	int edad;
	float salario;
} empleado[5];

void main ( ) {
	/* guardar arreglo */
	for (int i =0; i < 5; i++) {
		printf ("Introducir nombre: ");
		gets(empleado[i].nombre);
		printf ("Introducir edad: ");
		scanf ("%d", &empleado[i].edad);
		printf ("Introducir salario: ");
		scanf ("%f", &empleado[i].salario);
	}

	/* imprimir arreglo */
	for (int i =0; i < 5; i++) {
		printf ("Nombre %s\n", empleado[i].nombre);
		printf ("Edad %d\n", empleado[i].edad);
		printf ("Salario %.2f\n", empleado[i].salario);
	}

}
