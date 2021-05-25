# Tema 07: Tipo de Datos Estructurados

## Lectura de Caracteres en C

La forma correcta de leer cadenas es un tema que casi nunca se trata a profundidad en los libros de C, y menos aún en los cursos, así que no es raro que sea una de las cosas que más problemas ocasionan a quienes están aprendiendo este lenguaje.

La primera función de lectura de datos que se enseña es scanf. Se puede usar para leer cadenas, salvo por un detalle conocido por todos los programadores en C: no acepta cadenas con espacios. La recomendación que la mayoría hace, es que se utilice gets, pero se trata de una función insegura. Muchos la consideran el defecto más grande del lenguaje C, al grado de que ya ha sido declarada obsoleta. El problema de esta función es que lee todo lo que el usuario introduzca y lo almacena en la cadena, sin verificar si hay espacio suficiente. Es decir, si tenemos esto:

```c
	char nombre[30];
	printf("Escribe tu nombre: ");
	gets(nombre);
```

Y el usuario introduce un nombre de 30 o más caracteres, gets almacena todo en la variable nombre. Como sólo le caben 30 caracteres (29 más el caracter nulo o de fin de cadena '\0'), los restantes sobrescribirán lo que sea que esté en las posiciones de memoria más allá del byte 30 de la variable nombre. Es lo que se conoce como un desbordamiento de buffer. A partir de aquí, pueden ocurrir varias cosas, desde la menos grave, esto es, que el programa termine su ejecución de forma inesperada, hasta tener bugs muy difíciles de encontrar (por ejemplo, si se sobrescribe una variable) además de que algún malware podría aprovechar esta vulnerabilidad para poner en riesgo la seguridad del sistema operativo. Es por lo tanto una función que se debe evitar.

Aquí cabe decir que scanf en su forma típica tiene el mismo problema al usarlo con cadenas; si el usuario introduce un nombre que no tiene espacios, y es mayor a la capacidad de nuestra variable, habrá desbordamiento.

¿Cuál es la solución entonces? En realidad hay varias. Una forma de hacerlo es usando scanf con una serie de modificadores que sí permiten leer cadenas con espacios, incluso de forma segura, pero es algo complicada y propensa a errores por todo lo que hay que teclear. La función que casi siempre se recomienda es fgets, que es una buena opción si se sabe utilizar. Tiene el siguiente prototipo:

```c
	char *fgets(char *s, int n, FILE *stream);
```
	
	Sus parámetros son: 
		s - cadena donde se almacenarán los caracteres
		n - el tamaño de s
		stream - el archivo de donde se leerán los caracteres. Si
		se especifica stdin, se leerán de la entrada estándar
		(normalmente el teclado)

Hay que recalcar que el parámetro n especifica la cantidad de caracteres a leer, más el caracter de fin de cadena o caracter nulo '\0'. Es decir, esta función lee un máximo de n-1 caracteres, o hasta encontrar un caracter de nueva línea (el Enter con el que se finaliza la entrada de datos), lo que ocurra primero. Y finalmente cierra la cadena, agregando un '\0' justo después del último caracter leído. En otras palabras, siempre tendremos una cadena perfectamente formada y sin desbordamientos de buffer.

Vamos a ver un ejemplo de su uso. En este código, fgets lee un máximo de 29 caracteres de la entrada estándar:

```c
	char nombre[30];
	printf("Escribe tu nombre: ");
	fgets(nombre, 30, stdin);
```

Como se ve, es muy fácil de usar, pero debemos tener en cuenta algunos detalles que casi nunca se mencionan cuando se recomienda esta función. Cuando leemos una cadena con fgets, puede darse cualquiera de estos casos:

1. El número de caracteres introducidos por el usuario es menor a n-1. Cuando esto suceda, la cadena incluirá al final el caracter de nueva línea (cosa que no pasaría con scanf o gets). Si al ejecutar el código de ejemplo anterior, introdujéramos el nombre "Jorge", la cadena quedaría así (omito el caracter nulo):
```c
	"Jorge\n"
```

Cuando se imprima la variable, siempre se meterá una línea nueva al final. Esto significa, por ejemplo, que no será posible, al menos de forma sencilla, imprimir en una misma línea el nombre y la edad de una persona. Que esto sea aceptable o no, dependerá del uso que se le quiera dar al programa. En cualquier caso, siempre se puede verificar si la cadena contiene ese caracter, y eliminarlo, poniendo en su lugar el caracter nulo.

2. El número de caracteres introducidos es exactamente n-1. La cadena no contendrá el caracter de nueva línea, el cual se quedará en el buffer de entrada (más sobre esto en la siguiente sección).

3. El número de caracteres introducidos es mayor a n-1. fgets leerá únicamente los primeros n-1 caracteres y los asignará a la cadena, dejando en el buffer todos los caracteres no leídos. Que fgets funcione de esta manera no es casualidad ni capricho. Es útil para saber si se leyó completo el valor introducido. Si después de llamar a esta función, la cadena contiene un caracter de nueva línea al final (caso 1) significa que se leyeron todos los caracteres introducidos por el usuario, así que el buffer de entrada está limpio. Si no hay caracter de nueva línea en la cadena, significa que quedó "basura" en el buffer. Como mínimo, el '\n' (caso 2), pero podrían ser más caracteres (caso 3).

### Limpieza de buffer

Lo común en programas de consola o modo texto, es que para la entrada de datos por el teclado se use un buffer manejado por líneas. Esto significa que el programa no lee los caracteres directamente tal cual se van tecleando, sino que se guardan en un buffer o memoria intermedia, y hasta que se presiona Enter quedan disponibles para que el programa pueda leerlos mediante scanf, getchar, etc.

Las funciones de lectura de cadenas no se llevan muy bien con funciones de entrada más generales como scanf, debido a que manejan de diferente forma la lectura del buffer.

La función scanf funciona así: después de revisar el especificador de formato que le enviamos (%d, %f, etc.) lee y descarta todos los espacios en blanco que haya en el buffer de entrada* (esto incluye tabulaciones y caracteres de nueva línea) y a continuación lee los valores introducidos (o espera a que se introduzcan, si aún no se ha hecho) y los almacena. En cambio, gets y fgets no descartan nada, sino que leen lo que haya hasta que encuentran un caracter de nueva línea (o, en el caso de fgets, hasta leer el máximo de caracteres indicados). Y es ahí donde aparece el problema, porque scanf deja en el buffer de entrada el caracter de nueva línea, a diferencia de gets (y fgets, si se da el caso 1 de la sección anterior). 

	- Si el especificador de formato tiene %c, %[, o %n, scanf no descartará los espacios iniciales.

Vamos a ver un ejemplo de lo que ocurre cuando se utilizan estas funciones. Todo esto se explicará desde el punto de vista del programador y del programa, ya que internamente el sistema operativo puede realizar algunas tareas más, (por ejemplo, convertir el Enter a '\n') pero no son relevantes aquí.

Si ejecutamos un programa con este código:

```c
	int num1, num2;
	char nombre[30];
	printf("Escribe un numero: ");
	scanf("%d", &num1);
	printf("Escribe otro numero: ");
	scanf("%d", &num2);
	printf("Escribe tu nombre: ");
	fgets(nombre, 30, stdin);
```

El primer scanf analizará el especificador de formato que le mandamos, que en este ejemplo es %d, así que primero descartará cualquier espacio que haya en el buffer de entrada (en este caso, ninguno) y después intentará leer un valor entero desde el buffer de entrada. Como en este momento el buffer está vacío, la ejecución se detendrá, a la espera de que se introduzca un valor. Si escribimos 50 y presionamos Enter, en el buffer se tendrá algo así:
```c
	50\n
```

En este momento, scanf leerá el '5' y el '0', que son caracteres válidos para un entero, y a continuación encontrará el '\n', que no es un caracter válido para un entero, así que terminará de leer, y asignará el valor 50 a num1, dejando el buffer así:
```c	
	\n
```

A continuación se ejecutará el segundo scanf, que, de nuevo, verificará el especificador de formato (%d), por lo que descartará el '\n' que hay actualmente en el buffer, y a continuación esperará a que introduzcamos un valor. Si ahora escribimos 25 y presionamos Enter, el buffer quedará así:
```c
	25\n
```

Y scanf leerá el '2' y el '5', y se detendrá al encontrar el otro '\n'. Entonces asignará el valor 25 a num2, y el buffer quedará así:
```c
	\n
```

Hasta aquí todo funciona bien, ya que se ha utilizado únicamente scanf, pero la siguiente instrucción de entrada es fgets y es entonces donde aparece el problema. Puesto que fgets lee lo que haya en el buffer sin descartar nada, se encontrará directamente con un '\n' (justo el caracter que le indica que deje de leer), así que lo asignará a la cadena, y saltará a la siguiente instrucción, sin habernos dejado escribir nada. La solución pasa por limpiar el buffer de entrada después de un scanf, si la siguiente instrucción es una lectura de cadena con gets o fgets. Hay quienes sugieren utilizar para esto:
```c
	fflush(stdin)
```

Pero es incorrecto. Como el propio estándar del lenguaje C dice, fflush es una función para vaciar flujos de salida (stdin es de entrada, obviamente). Si lo usamos con flujos de entrada, el resultado queda indefinido. En Linux y sistemas tipo Unix no funciona. En Windows suele funcionar, pero no podemos contar con eso, porque realmente estamos usando la función de forma incorrecta. Imaginemos que mediante alguna extraña técnica pudiéramos usar printf para leer datos en vez de imprimirlos, ¿tendría justificación hacer semejante disparate sólo porque "a mí me funciona"?

La manera recomendada de limpiar la entrada estándar es la siguiente:
```c
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
```

Este código es como un fflush(stdin) pero correcto y estándar. Lo que hace es leer un caracter hasta que encuentra un caracter de nueva línea o de fin de archivo (EOF). En realidad, cuando estamos leyendo desde la entrada estándar, no deberíamos encontrarnos nunca con un fin de archivo, así que se podría omitir esta parte, pero es preferible dejarlo tal cual, ya que es posible redirigir a stdin el contenido de un archivo, que obviamente sí tiene fin. El código anterior funciona en ambos casos.

### Función

Nuestra función de ejemplo tiene el siguiente prototipo:

```c
int leestring(char *cad, int n);
```

Acepta dos parámetros: la variable donde almacenaremos la cadena, y su tamaño (incluyendo el caracter nulo). Es decir, que la invocaríamos de esta forma:
```c
	char nombre[30];
	printf("Escribe un nombre: ");
	leestring(nombre, 30);
```

Además, devuelve un valor de tipo entero, que servirá para verificar si hubo un error.

Podemos separar su funcionamiento en tres partes:

1. Comprobación del buffer
2. La lectura en sí de la cadena
3. Limpieza de buffer

#### Comprobación del buffer

Puesto que queremos una función que se pueda usar de forma más o menos general, primero hay que verificar si el buffer está limpio, o si hay un '\n' dejado por scanf y, en ese caso, limpiarlo:
```c
	int i, c;
	/* Comprobación */
	c=getchar();
	if (c == EOF) {
		cad[0] = '\0';
		return 0;
	}
	if (c == '\n')
		i = 0;
	else {
		cad[0]=c;
		i = 1;
	}
```

Tenemos dos variables: i, que es el típico contador usado en los ciclos for, y c, que es donde guardaremos los caracteres individuales que vayamos leyendo y después se irán agregando a la cadena cad.

Empezamos leyendo sólo el primer caracter que haya en la entrada. Si es EOF, significa que no hay nada por leer, así que cerramos la cadena, dejándola "vacía" y salimos de la función retornando un valor de 0 ó falso, para indicar que hubo un error. Si el valor leído es '\n', significa que había un caracter de nueva línea dejado por un scanf o función similar. Simplemente inicializamos i a 0, para indicar que los siguientes caracteres que leamos los iremos asignando a partir del primer caracter de la cadena.

Si no había un '\n', significa que el caracter que leímos es el primer caracter de la cadena introducida. En este caso, lo guardamos en la posición 0 de cad, e inicializamos i a 1, porque en este caso, como ya tenemos el primer caracter de la cadena, continuaremos agregando caracteres a partir del segundo. 

### Lectura de la cadena

Pasamos ahora a la lectura de la cadena:
```c
	for (; i < n-1 && (c=getchar())!=EOF && c!='\n'; i++)
		cad[i] = c;
	cad[i] = '\0';
```

El for empieza con un ; porque estamos omitiendo la inicialización del contador, ya que fue inicializado en el punto anterior.

Este código lee un caracter a la vez, lo agrega a cad, y se repite hasta que encuentre un fin de línea, fin de archivo, o haya leído la cantidad máxima de caracteres que se le indicó. Luego, cierra la cadena agregando un '\0' al final. Todo esto es muy similar a la forma en que los compiladores suelen implementar la función fgets, sólo que en lugar de getchar usan getc o fgetc.

### Limpieza del buffer

Finalmente, limpiamos el buffer si es necesario:
```c
	if (c != '\n' && c != EOF)
		while ((c = getchar()) != '\n' && c != EOF);
```

La variable c contiene el último caracter leído. Recordemos que había 3 formas de salir del for: que hayamos encontrado un '\n', un EOF, o que hayamos llegado al máximo de caracteres que debemos leer. Si se da cualquiera de los dos primeros casos, significa que leímos todo lo que había en el buffer, por lo que no hay nada que limpiar. En el tercer caso, el usuario escribió más caracteres de los debidos, que aún están en el buffer, por lo que hay que quitarlos, para lo cual usamos el método que vimos poco más arriba.

Juntándolo todo, tenemos la función:
```c
	int leestring (char *cad, int n) {
		int i, c;
		c=getchar();
		if (c == EOF) {
			cad[0] = '\0';
			return 0;
		}
		if (c == '\n')
			i = 0;
		else {
			cad[0] = c;
			i = 1;
		}
		for (; i < n-1 && (c=getchar())!=EOF && c!='\n'; i++)
			cad[i] = c;
		cad[i] = '\0';
		if (c != '\n' && c != EOF)
			while ((c = getchar()) != '\n' && c != EOF);
		return 1;
	}
```

## Notas finales y sugerencias

Aunque puesta aquí sólo a manera de ejemplo, la función está lista para ser usada tal cual en sus programas. Como usa sólo código estándar, debe funcionar en cualquier plataforma que tenga una implementación de C.

Por simplicidad, funciona únicamente para leer de la entrada estándar, pero fácilmente se podría modificar para que trabaje también con archivos. Para eso habría que agregar un tercer argumento: FILE *stream, y reemplazar los getchar() por fgetc(stream).

Finalmente, muchos programadores consideran que, si se quiere tener un programa lo más correcto y tolerante a fallas posible (en cuanto a lectura de datos), se deberían leer todas las variables (incluso de tipo int, float, etc.) en una cadena temporal, usando, por ejemplo, fgets (o incluso nuestra función de ejemplo) y después extraer de esta cadena los datos a leer, mediante sscanf, que funciona igual a scanf, pero en vez de leer los datos del teclado, los lee desde la cadena que le especifiquemos. Esto se deja como un ejercicio para quien quiera implementarlo.
