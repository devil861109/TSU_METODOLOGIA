#include<stdio.h>
#include<stdlib.h>

void main ( ) {
   float salariobase [12]; /*define un arreglo de 12 elementos reales*/
   int i;
   for (i = 0; i < 12; i++) { /*Inicializa el arreglo con los salarios leidos*/
      printf (“Introducir salario: ”);
      scanf (“%f”, &salariobase[i]);
   }
   printf (“Listado de salarios\n”);
   for (i = 0; i < 12; i++) /*Accesa a los elementos del arreglo y los imprime*/
      printf (“%.2f\n”, salariobase[i]);
}
