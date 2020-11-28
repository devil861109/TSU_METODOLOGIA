#include <stdio.h>
#include <stdlib.h>

void main () {
	FILE *parch;
	char* nombref = "C:\\Trabajo\\matricula.dat";
	if ((parch = fopen (nombref, "w")) == NULL) {
  		puts ("Error al abrir el archivo en escritura");
  		exit (-1); 
	}
}
