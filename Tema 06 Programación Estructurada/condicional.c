#include<stdio.h>
#include<stdlib.h>

void main () {
	int n, m;
	printf ("Introducir el dividendo: ");
	scanf ("%d", &n);
	printf ("Introducir el divisor: ");
	scanf ("%d", &m);
	if (n%m == 0) {
    	printf ("%d es divisible por %d\n", n, m);
	}
}
