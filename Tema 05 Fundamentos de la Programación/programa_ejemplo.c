#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, ne = 0;
	float edad, sumaEdad = 0;
	float peso, sumaPeso = 0, mediaEdad = 0, mediaPeso = 0;
	printf("Introducir cantidad de estudiantes a procesar: ");
	scanf("%d",&n);
	while (ne < n) {
		ne++;
		printf("Introducir EDAD del estudiante %d: ",ne);
		scanf("%f",&edad);
		printf("Introducir PESO del estudiante %d: ",ne);
		scanf("%f",&peso);
		sumaEdad = sumaEdad + edad;
		sumaPeso = sumaPeso + peso;
	}
	mediaEdad = sumaEdad/n;
	mediaPeso = sumaPeso/n;
	printf("La edad promedio es %2.2f\n",mediaEdad);
	printf("El peso promedio es %2.2f\n", mediaPeso);
	
	return 0;
}
