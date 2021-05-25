# Tema 09: Apuntadores

Llamados también punteros. Un Apuntador es una variable que contiene una dirección de memoria, la cual corresponderá a un dato o a una variable que contiene el dato. Cada variable que se utiliza en una aplicación ocupa una o varias posiciones de memoria. Estas posiciones de memoria se accesan por medio de una dirección.

El Operador de Dirección ( & ) regresa la dirección de una variable.
El Operador de Indirección ( * ), toma la dirección de una variable y regresa el dato que contiene esa dirección.

## Declaración de Puntero

Tipo_dato *nombre de apuntador;
Tipo_dato : Especifica el tipo de objeto apuntado y puede ser cualquier tipo (int, float, char, etc).
Nombre de apuntador: Es el identificador (nombre asignado) del apuntador.

## Ejemplos de declaración

```c
	int *ptr, cont;
	float *res;
	short *bandera;
	char *mensaje;
```

## Ejemplo apuntador

```c
#include "stdio.h"
#include "conio.h"

int main () {
	int var=1, *apun;
	apun = &var; // Inicialización del apuntador
	printf("\n Acceso directo, var = %d", var);
	printf("\n Acceso indirecto, var = %d", *apun);
	// Se despliega la dirección de la variable de dos maneras
	printf("\n La dirección de var = %d", &var);
	printf("\n LA dirección de var = %d", apun);
	return 0;
}
```
