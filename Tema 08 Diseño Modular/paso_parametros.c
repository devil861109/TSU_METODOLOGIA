#include <stdio.h>

struct videojuego {
    char nombre[20];
    float precio;
};

/* prototipos */
void imprimeNombre(char nombre[25]);
void cargaVector(int array[], int n);
void imprimeVector(int array[], int n);
void cargaMatriz(int mat[2][2]);
void imprimeMatriz(int mat[2][2]);
struct videojuego agregaJuego(struct videojuego game) ;
void imprimeJuego(struct videojuego game);

int main() {
    int arreglo_enteros[5];
    int arreglo_matriz[2][2];
    char nombre_propio[25];
    struct videojuego juego;

    printf("Dame tu nombre:");
    scanf("%s", nombre_propio);
    //invocacion de la funcion
    imprimeNombre(nombre_propio);
    //invocacion de la funcion
    cargaVector(arreglo_enteros, 5);
    imprimeVector(arreglo_enteros, 5);
    //invocacion de la funcion
    cargaMatriz(arreglo_matriz);
    imprimeMatriz(arreglo_matriz);
    //invocacion de la funcion
    juego = agregaJuego(juego);
    imprimeJuego(juego);

    return 0;
}

/* declaracion de la funcion */
void imprimeNombre(char nombre[25]) {
    printf("El nombre pasado por parametros es: %s\n",nombre);
}

void cargaVector(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("dame valor: ");
        scanf("%d", &array[i]);
    }
}

void imprimeVector(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d\n", array[i]);
    }
}

void cargaMatriz(int mat[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("dame valor: ");
            scanf("%d", &mat[i][j]);
        }
    }
}

void imprimeMatriz(int mat[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d", mat[i][j]);
        }
        puts("");
    }
}

struct videojuego agregaJuego(struct videojuego game) {
    printf("Nombre: ");
    scanf("%s", game.nombre);
    printf("Precio: ");
    scanf("%f", &game.precio);
    return game;
}

void imprimeJuego(struct videojuego game) {
    printf("Nombre: %s\n", game.nombre);
    printf("Precio: %f\n", game.precio);
}