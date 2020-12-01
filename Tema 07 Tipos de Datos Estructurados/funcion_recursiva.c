#include <stdio.h>

long int factorial (int n);

int main() {
	int n;
	printf("Introducir la cantidad entera a la que le queremos hallar el factorial: ");
	scanf("%d", &n);
	printf("%d! = %d\n", n, factorial(n));

	return 0;
}

long int factorial (int n) {
	if (n <= 1)
		return(1);
	else
		return(n * factorial (n-1));
}
