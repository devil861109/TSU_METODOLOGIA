#include <stdio.h>
#include <stdlib.h>

void main () {
	FILE *pf;
	char* nombref = "C:\\nomina.dat";
	pf = fopen (nombref, "r");
	if (pf == NULL){
		puts ("Error en apertura");
		exit (1);
	}
}
