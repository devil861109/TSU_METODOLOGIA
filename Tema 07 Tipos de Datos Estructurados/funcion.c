#include <stdio.h>

void funcion(void); /* prototipo */

int num=5; /* variable global */

int main() {
	int num=10; /* variable local */
	printf("%d\n",num);
	funcion(); /* llamada */

	return 0;
}

void funcion(void) {
	printf("%d\n",num);
}
