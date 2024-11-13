// Ejercicio Integrador 2do Parcial
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_CHAR 50
#define MAX_EMP 60
#define NO 0
#define SI 1
#define SUELDO 0
#define CATEGORIA 1
#define SALIR 6
#define SUELDO_CAT_1 15000
#define SUELDO_CAT_2 12000
#define SUELDO_CAT_3 10000
#define SUELDO_CAT_4 8000
#define HORAS_BONIFICACION 180
#define HORAS_FILTRO 100

typedef struct {
	int cod; //Codigo unico de empleado
	char nom[MAX_CHAR]; //Nombre del empleado
	int cat; //Categoria del empleado (De 1 a 4)
	int horas; //Horas trabajadas por el empleado
	float sue; //Sueldo calculado del empleado
} registro_t;

int menu();
void cargarEmpleados(registro_t[]);
void informeDeSueldos(registro_t[]);
void filtrarEmpleadosPorHoras(registro_t[], registro_t[]);
void sueldosPorCategoria(registro_t[]);
void cantidadEmpleadosPorCategoria(registro_t[]);

int main(){
	registro_t empleados[MAX_EMP] = {-1,"",0,0,0.0};
	registro_t empleadosPocasHoras[MAX_EMP]= {-1,"",0,0,0.0};

	int opcMenu;
	srand(time(NULL));

	do {
		opcMenu = menu();
		switch(opcMenu){
		case 1:
			cargarEmpleados(empleados);
			break;
		case 2:
			informeDeSueldos(empleados);
			break;
		case 3:
			filtrarEmpleadosPorHoras(empleados, empleadosPocasHoras);
			break;
		case 4:
			sueldosPorCategoria(empleados);
			break;
		case 5:
			cantidadEmpleadosPorCategoria(empleados);
			break;
		}
	}while(opcMenu!=SALIR);

	printf("Todo bien so far");
	return 0;
}

int menu(){
	int opc, invalida = SI;
	printf("1_ Cargar Empleados\n");
	printf("2_ Informe de Sueldos\n");
	printf("3_ Filtrar Empleados por Horas Trabajadas\n");
	printf("4_ Informe de Sueldos por Categoria (No lo muestra en orden :c )\n");
	printf("5_ Informe de Cantidad de Empleados por Categoria\n");
	printf("6_ Salir\n");
	do {
		printf("Tu opcion: ");
		scanf("%d", &opc);
		if((opc>=1)&&(opc<=6)) invalida = NO;
		else printf("Ingrese una opcion valida.\n");
	} while(invalida);

	return(opc);
}
void cargarEmpleados(registro_t empleados[MAX_EMP]) {
	int cont=0, codIngresado, pedirEmpleado=SI, bonificacion=0;

	do {
		printf("Ingrese el codigo de empleado: ");
		scanf("%d", &codIngresado);
		if(codIngresado==0) pedirEmpleado = NO;
		else {
			empleados[cont].cod = codIngresado;
			printf("Ingrese el nombre del Empleado: ");
			scanf("%s", &empleados[cont].nom);
			empleados[cont].cat = (rand() % (4 - 1 + 1)) + 1;
			empleados[cont].horas = (rand() % (220 - 50 + 1)) + 50;
			switch(empleados[cont].cat) {
			case 1:
				empleados[cont].sue = empleados[cont].horas * SUELDO_CAT_1;
				if(empleados[cont].horas > HORAS_BONIFICACION) {
					bonificacion = ((empleados[cont].horas - HORAS_BONIFICACION) * SUELDO_CAT_1 * 0.10);
				}
				break;
			case 2:
				empleados[cont].sue = empleados[cont].horas * SUELDO_CAT_2;
				if(empleados[cont].horas > HORAS_BONIFICACION) {
					bonificacion = ((empleados[cont].horas - HORAS_BONIFICACION) * SUELDO_CAT_2 * 0.10);
				}
				break;
			case 3:
				empleados[cont].sue = empleados[cont].horas * SUELDO_CAT_3;
				if(empleados[cont].horas > HORAS_BONIFICACION) {
					bonificacion = ((empleados[cont].horas - HORAS_BONIFICACION) * SUELDO_CAT_3 * 0.10);
				}
				break;
			case 4:
				empleados[cont].sue = empleados[cont].horas * SUELDO_CAT_4;
				if(empleados[cont].horas > HORAS_BONIFICACION) {
					bonificacion = ((empleados[cont].horas - HORAS_BONIFICACION) * SUELDO_CAT_4 * 0.10);
				}
				break;
			}
			empleados[cont].sue = empleados[cont].sue + bonificacion;

		}
		cont++;
	} while(pedirEmpleado);
	printf("\n");
}

void informeDeSueldos(registro_t empleados[MAX_EMP]) {
	int cont = 0;

	do {
		printf("\nCodigo de Empleado: %d\n", empleados[cont].cod);
		printf("Nombre del Empleado: %s\n", empleados[cont].nom);
		printf("Categoria del Empleado: %d\n", empleados[cont].cat);
		printf("Horas del Empleado: %d\n", empleados[cont].horas);
		printf("Sueldo del Empleado: $%f\n\n", empleados[cont].sue);
		cont++;
	} while(empleados[cont].cod!=0);
	printf("\n");
}

void filtrarEmpleadosPorHoras(registro_t empleados[MAX_EMP], registro_t empleadosPocasHoras[MAX_EMP]) {
	int contEmpleados = 0, contEmpleadosPocasHoras = 0;

	do {
		if(empleados[contEmpleados].horas < HORAS_FILTRO) {
			empleadosPocasHoras[contEmpleadosPocasHoras].cod = empleados[contEmpleados].cod;
			strcpy(empleados[contEmpleados].nom, empleadosPocasHoras[contEmpleadosPocasHoras].nom);
			empleadosPocasHoras[contEmpleadosPocasHoras].cat = empleados[contEmpleados].cat;
			empleadosPocasHoras[contEmpleadosPocasHoras].horas = empleados[contEmpleados].horas;
			empleadosPocasHoras[contEmpleadosPocasHoras].sue = empleados[contEmpleados].sue;
			contEmpleadosPocasHoras++;
		}
		contEmpleados++;
	} while(empleados[contEmpleados].cod!=0);

	informeDeSueldos(empleadosPocasHoras);
	printf("\n");
}

void sueldosPorCategoria(registro_t empleados[MAX_EMP]) {
	float acumCat[4] = {0.0};
	int categorias[4] = {1,2,3,4};
	float auxF;
	int cont=0, auxI, i=0;

	do {
		switch(empleados[cont].cat) {
		case 1:
			acumCat[0] = acumCat[0] + empleados[cont].sue;
			break;
		case 2:
			acumCat[1] = acumCat[1] + empleados[cont].sue;
			break;
		case 3:
			acumCat[2] = acumCat[2] + empleados[cont].sue;
			break;
		case 4:
			acumCat[3] = acumCat[3] + empleados[cont].sue;
			break;
		}
		cont++;
	} while(empleados[cont].cod!=0);

	for(i=0; i<4; i++) {
		for(int j=i+1; j<4-1; j++) {
			if(acumCat[i]<acumCat[j]) {
				auxF = acumCat[i];
				acumCat[i] = acumCat[j];
				acumCat[j] = auxF;

				auxI = categorias[i];
				categorias[i] = categorias[j];
				categorias[j] = auxI;
			}
		}
	}

	for(i=0; i<4; i++) {
		printf("La categoria %d acumulC3 $%f\n", categorias[i], acumCat[i]);
	}
	printf("\n");
}

void cantidadEmpleadosPorCategoria(registro_t empleados[MAX_EMP]) {
	int cantCategorias[4] = {0,0,0,0};
	int cont=0;

	do {
		switch(empleados[cont].cat) {
		case 1:
			cantCategorias[0]++;
			break;
		case 2:
			cantCategorias[1]++;
			break;
		case 3:
			cantCategorias[2]++;
			break;
		case 4:
			cantCategorias[3]++;
			break;
		}
		cont++;
	} while(empleados[cont].cod!=0);

	for(int i=0; i<4; i++) {
		printf("La categoria %d tiene %d empleados\n", (i+1), cantCategorias[i]);
	}
	printf("\n");
}
