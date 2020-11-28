#include<stdio.h>
#include<stdlib.h>

void main () {
	int i;
   	double number, sum = 0.0;
   	for (i = 1; i <= 10; ++i) {
    	printf("Enter a n%d: ", i);
      	scanf("%lf", &number);
      	// if the user enters a negative number, break the loop
      	if (number < 0.0) {
         	continue;
      	}
      	sum += number; // sum = sum + number;
   	}
   	printf("Sum = %.2lf", sum);
}
