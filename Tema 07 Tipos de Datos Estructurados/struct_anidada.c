#include <stdio.h>

struct materia {
    char nombre[25];
    float calif;
};

struct alumno{
    char matricula[25];
    char nombre[25];
    struct materia calificaciones[5];
};

int main() {
    struct alumno grupoA[2];

    //agregar valores
    for (int i = 0; i < 5; ++i) {
        printf("Dame matricula de alumno: ");
        scanf("%s", grupoA[i].matricula);
        printf("Dame nombre de alumno: ");
        scanf("%s", grupoA[i].nombre);
        printf("Dame calificaciones de alumno:\n");
        for (int j = 0; j < 5; ++j) {
            printf("\tMateria: ");
            scanf("%s", grupoA[i].calificaciones[j].nombre);
            printf("\tCalificacion: ");
            scanf("%f", &grupoA[i].calificaciones[j].calif);
        }
    }

    //imprimir valores
    for (int i = 0; i < 5; ++i) {
        printf("Matricula de alumno: %s\n", grupoA[i].matricula);
        printf("Nombre de alumno: %s\n", grupoA[i].nombre);
        printf("Calificaciones de alumno:\n");
        for (int j = 0; j < 5; ++j) {
            printf("\tMateria: %s\n", grupoA[i].calificaciones[j].nombre);
            printf("\tCalificacion: %f\n", grupoA[i].calificaciones[j].calif);
        }
        puts("");
    }
    return 0;
}
