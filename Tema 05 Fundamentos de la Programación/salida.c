#include<stdio.h>
#include<stdlib.h>

int main() {
	int a = 7;
	float b = 8.2;
	char c = 's';
	
	printf("%d", a);
	//Se visualiza un 7, que es el contenido de la variable a.
	printf("%d", a+b);
	//Se visualiza un 15, ya que es la suma de a + b mostrada como valor entero.
	printf("%f", a+b);
	//Se visualiza un 15.2, ya que es la suma de a + b mostrada como valor real.
	printf("%c", c);
	//Se visualiza la letra 's' que es el contenido de la variable c.
	printf("%c %d %f", c,a,b);
	//Se visualiza s 7 8.2 que son los valores de las variables c, a y b respectivamente.
	printf("HOLA");
	//Se visualiza la palabra HOLA.

	return 0;
}
