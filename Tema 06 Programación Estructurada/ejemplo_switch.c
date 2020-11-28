#include<stdio.h>
#include<stdlib.h>

void main () {
	int seleccion;
	printf ("Introduzca: \n");
	printf ("1: para cambio de NIP \n");
	printf ("2: para operaciones entre cuentas propias \n");
	printf ("3: para operaciones con cuentas de terceros \n");
	printf ("4: para operaciones con cuentas de otros bancos \n");
	printf ("5: para pago de servicios \n");
	scanf ("%d", &seleccion);
	switch (seleccion) {
		case 1:
			cambioNIP ( );
			break;
		case 2:
			opCuentasPropias ( );
			break;
		case 3:
			opCuentasTerceros ( );
			break;
		case 4:
			opCuentasOtrosBancos ( );
			break;
		case 5:
			pagoServicios ( );
			break;
		default: 
			printf("Rango no admitido");
			break;
	}
}
