#include<stdio.h>
#include<stdlib.h>

void main () {
	int edadJuan = 20;
	int edadJose = 18;
	if (edadJuan < edadJose) {
		printf("Juan es mas joven que Jose");
	} else {
		if (edadJuan == edadJose)
			printf("Juan tiene la misma edad que Jose");
		else
			printf("Juan es mayor que Jose");
	}
}
