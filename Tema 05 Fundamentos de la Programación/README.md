# Tema 05: Fundamentos de la Programación

C, la base de TODO.

## Estructura típica de un Programa en C

```c
#include -> Directivas del preprocesador

#define -> Macros del preprocesador
```

### Declaraciones Globales

* Prototipos de Funciones
* Variables
* Estructuras
* Etc...

### Función Principal Main

Puede ser:
```c
int main()
void main()
```

A veces puede traer parámetros por defecto
```c
int main(int argc, char *argv[])
```

### Cuerpo de main

```c
int main(int argc, char *argv[]) {
	Declaraciones locales
	Sentencias
}
```

### Definición de otras funciones
```c
tipo_retorno func1(...) {
	...
}
```

### Headers de sistema
```c
#include <stdio.h>
#include <stdlib.h>
```

### Headers propios
```c
#include "my_library.h"
```

### NOTA
Las librerías o bibliotecas de sistema van con < >
Las librerías o bibliotecas de programador van con " "

## Ejemplo de Programa en C

```c
int factorial(int n) {
	if (n>1) {
		return n*factorial(n-1);
	} else {
		return 1;
	}
}

int main () {
	int valor, fact;
	int cont = 0;
	do {
		printf ("Introducir un numero entero positivo (para salir 0)");
		scanf("%d", &valor);
		if (valor>0) {
			fact = factorial (valor);
			printf ("El factorial de %d es %d \n", valor, factorial);
			cont++;
		}
	} while (valor>0);
	printf ("Han sido calculados %d valores \n", cont);
	return 0;
}
```

## Compilar el programa en consola

```bash
gcc programa.c -o programa.exe
gcc programa.c -o programa.sh
gcc programa.c -o programa
```

## Tipos de Datos

| Tipo               | No. Byte                | Rango                                                                 | Precisión |
| ------------------ | ----------------------- | --------------------------------------------------------------------- | --------- |
| char               | 1                       | -128 a 127                                                            |           |
| unsigned char      | 1                       | 0 a 255                                                               |           |
| signed char        | 1                       | -128 a 127                                                            |           |
| int                | 2 o 4 (32 o 64 bits)    | -32,768 a 32,767 o -2,147,483,648 a 2,147,483,647                     |           |
| unsigned int       | 2 o 4                   | 0 a 65,535 o 0 a 4,294,967,295                                        |           |
| short              | 2                       | -32,768 a 32,767                                                      |           |
| unsigned short     | 2                       | 0 a 32,767                                                            |           |
| long               | 4 o 8 (32 o 64 bits)    | -9223372036854775808 a 9223372036854775807 o -2147483648 a 2147483647 |           |
| unsigned long      | 4 o 8                   | 0 a 4294967295 o 0 a 18446744073709551615                             |           |
| float              | 4                       | 1.2E-38 a 3.4E+38                                                     | 6         |
| double             | 8                       | 2.3E-308 to 1.7E+308                                                  | 15        |
| long double        | 10                      | 3.4E-4932 to 1.1E+4932                                                | 19        |

## Identificadores y tipos

El lenguaje C es sensible a mayúsculas y minúsculas (case sensitive), de modo que no es lo mismo para el compilador el identificador cuenta que otro denominado Cuenta.

Los compiladores reservan determinados términos ó palabras claves (keywords), para el uso sintáctico del lenguaje, tales como: asm, auto, break, case, char, do, for, etc. Si bien estas palabras están definidas para el ANSI C, los distintos compiladores extienden esta definición a otros términos, por lo que es aconsejable leer la tabla completa de palabras reservadas del compilador que se vaya a usar, para no utilizarlas en nombres de variables.

Para crear una variable en un lugar determinado del un programa escribiremos primero el tipo de variable y luego el identificador con el que queremos nombrar la variable, seguido todo de un ';'. A esto se le denomina definir una variable. La forma general de la definición es:
```c
tipo lista_identificadores;
```
Por ejemplo:
```c
int numero;	/* crea la variable numero, de tipo número entero */
char letra;	/* crea la variable letra, de tipo carácter*/
float a, b;	/* crea dos variables a y b, de tipo número de coma flotante */
```

Las variables se pueden inicializar, es decir, establecer un valor inicial, en el momento de creación. Para ello, detrás del identificador ponemos el carácter '=' seguido del valor inicial. Los valores iniciales pueden ser cualquier constante válida para el tipo de variable que creemos. Por ejemplo:
```c
int numero = 0;		/* crea la variable entera numero
			 y la inicializa a 0*/
char letra = 'p';	/* crea la variable carácter letra
			 y la inicializa a 'p' */
float a=57.1, b=1.2E-5;	/* crea las variables a y b,
			 de tipo número de coma flotante, y los inicializa
			 a 57.1 y 0.000012, respectivamente*/
```

Existen tres sitios donde se pueden definir variables:

fuera de todas las funciones (variables globales).

dentro de las funciones (variables locales)

en la definición de parámetros de funciones (parámetros formales)

El tipo de datos carácter consta de un único carácter y se suele representar por su carácter en código ASCII situado entre apóstrofes. Por ejemplo:
```c
'p' /* la letra p minúscula */
'1' /* el numero 1 */
' ' /* el carácter en blanco */
```
Hay otras formas de representar caracteres, que se emplean cuando es un carácter que no se puede introducir directamente desde el teclado. Para ello debemos conocer su código ASCII. Para representar el carácter de numero ascii 27, (el código para el carácter ESCAPE), basta colocar el número ascii en el sistema octal precedido de la barra atrás, y todo ello entre apóstrofes, tal y como hacemos para los demás caracteres:
```c
'\27' /* representa el código ESCAPE, de ASCII 27 */
```
En C hay algunos caracteres especiales que se usan frecuentemente. Estos caracteres tiene una representación especial. Algunos de ellos son:

| Código  | Significado              | Valor ASCII (decimal) | Valor ASCII (hexadecimal) |
| ------- | ------------------------ | --------------------- | ------------------------- |
| '\n'	  | nueva línea              | 10	                 | 0x0A                      |
| '\r'	  | retorno de carro         | 13	                 | 0x0D                      |
| '\f'	  | nueva página (form feed) | 2	                 | x0C                       |
| '\t'	  | tabulador horizontal     | 9	                 | 0x09                      |
| '\b'	  | retroceso (backspace)    | 8	                 | 0x08                      |
| '\''	  | comilla simple           | 39	                 | 0x27                      |
| '\"'	  | comillas                 | 4	                 | 0x22                      |
| '\\ '	  | barra invertida          | 92	                 | 0x5C                      |
| '\? '	  | interrogación            | 63	                 | 0x3F                      |
| '\nnn'  | cualquier carácter (donde nnn es el código ASCII expresado en octal)         |
| '\xnn'  | cualquier carácter (donde nn es el código ASCII expresado en hexadecimal)    |

## Tamaño de las variables

sizeof(int);
sizeof(char);
sizeof(long double);

## Variables

Una variable es un objeto nombrado capaz de contener un dato que puede ser modificado durante la ejecución de programa. En C, las variables tienen tipo, que significa que es necesario especificar el tipo de dato que se le asigna a una variable (int, float etc.). Las variables se almacenan en la memoria RAM y el espacio de memoria que ocupan (en bytes) depende de su tipo.
```c
/* dos líneas de programa consecutivas. En la primera línea del programa
se define el tipo de variable */ 

int a = 1000; // Variable a es de tipo int y equivale a 1000
a = 15;       // a equivale a 15
```

## Constantes

Para expresar una constante con un nombre, la constante debe ser declarada previamente. Las constantes que se declaran en un programa escrito en lenguaje C reciben un tratamiento diferente al de la mayoría de los lenguajes de programación. En C, para representar a las constantes, se utilizan constantes simbólicas. Una constante simbólica representa (sustituye) a una secuencia de caracteres, en vez de representar a un valor (dato almacenado en memoria).

Para declarar una constante simbólica, en lenguaje C, se utiliza una nueva directiva del preprocesador:
```c
#define <constante> <secuencia_de_caracteres>
```
La directiva #define indica al preprocesador que debe sustituir, en el código fuente del programa, todas las ocurrencias del <nombre_de_la_constante> por la <secuencia_de_caracteres>, antes de la compilación.

Una constante tiene las mismas características que una variable excepto el hecho de que su valor asignado no puede ser cambiado durante la ejecución de programa. A diferencia de las variables, las constantes se almacenan en la memoria Flash del microcontrolador para guardar el mayor espacio posible de memoria RAM. El compilador las reconoce por el nombre y el prefijo const. En mikroC, el compilador reconoce automáticamente el tipo de dato de una constante, así que no es necesario especificar el tipo adicionalmente.
```c
/* dos líneas de programa consecutivas */ 
const A = 1000 // el valor de la constante A está definido
A = 15;        // ¡ERROR! no se puede modificar el valor de la constante
```

Cada variable o constante debe tener un identificador que lo distingue de otras variables y constantes. Refiérase a los ejemplos anteriores, a y A son identificadores.
