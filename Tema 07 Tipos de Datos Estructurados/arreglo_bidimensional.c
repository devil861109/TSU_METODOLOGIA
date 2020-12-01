#include <stdio.h>

int main() {
	int i, j, numeros[3][4];
	
	/* guardamos la matriz */
	for (i=0;i<3;i++) {
		for (j=0;j<4;j++) {
			scanf("%d",&numeros[i][j]);
		}
	}
	
	/* imprimimos la matriz */
	for (i=0;i<3;i++) {
		for (j=0;j<4;j++) {
			printf("%d",numeros[i][j]);
		}
	}

	return 0;
}
