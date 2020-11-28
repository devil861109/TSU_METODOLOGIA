#include <stdio.h>
#include <stdlib.h>

#define DIM 30

typedef struct {
    char apellidoP[16], apellidoM[16], nombre[31], sexo[2];
    int anoNac;
} persona;

int main( ) {
    persona v[DIM]; int k=0; FILE* f;
    if ((f=fopen("test.txt", "r")) == NULL) {
        perror("El archivo no existe!"); exit(1);
    }
    while(fscanf(f,"%s%s%s%s%d\n",v[k].apellidoP, v[k].apellidoM, v[k].nombre, v[k].sexo, &v[k].anoNac) != EOF)
        k++;
    printf("%s\n%s\n%s\n%s\n%d\n",v[0].apellidoP, v[0].apellidoM, v[0].nombre, v[0].sexo, v[0].anoNac);
    return 0;
}