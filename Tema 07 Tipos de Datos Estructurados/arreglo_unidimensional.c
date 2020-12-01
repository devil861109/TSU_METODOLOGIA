#include <stdio.h>

int main() {
	int i, numeros[5];
	
	/* guardamos la matriz */
	for (i=0;i<5;i++) {
		scanf("%d",&numeros[i]);
	}
	
	/* imprimimos la matriz */
	for (i=0;i<3;i++) {
		printf("%d",numeros[i]);
	}

	return 0;
}
