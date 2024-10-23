#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define HORAS_EXTRAS 180

#define MIN_HR 50
#define MAX_HR 220

#define MAX_CAT 4
#define MIN_CAT 1

#define MAX_CHAR 30
#define MAX_EMP 60
#define CODIGO_SALIR 0
const int SUELDO_CAT[]={15000,12000,10000,8000};

typedef struct{
        float valores[MAX_CAT];
        int categoria[MAX_CAT];
}sueldos_t;

typedef struct {
    int cod;         // Código unico del empleado  
    char nombre[MAX_CHAR];    // Nombre del empleado
    int cat;         // Categoría del empleado (de 1 a 4)
    int horas;       // Horas trabajadas por el empleado
    float sue;       // Sueldo calculado del empleado
}registro_t;

typedef enum{
    CARGAR=1,
    INF_SUELDOS_TOT,
    FILT_HORAS_TRA,
    INF_SUELDOS_CAT,
    INF_EMP_CAT,
    SALIR
}opcion_t;

void borrar (void);
int menu (void);
void cargar_empleados(registro_t [],int *);
bool validar_codigo(registro_t [],int,int);
void imprimir_empleados(registro_t [],int);
int numero_aleatorio(int,int);
void pausa(void);
void filtrar(registro_t [],registro_t [],int);
void sueldos_categoria(registro_t [],int);
void empleados_categoria(registro_t [],int);
void ordenar (sueldos_t * ,int );

int main (void){
    opcion_t op;
    registro_t empleados[MAX_EMP]={0};
    registro_t empleados_filtrados[MAX_EMP]={0};

    int cantEmple=0;
    srand(time(NULL));
    do{
        op=menu();
        switch (op){
            case CARGAR:cargar_empleados(empleados,&cantEmple);
                        break;
            case INF_SUELDOS_TOT:
                        imprimir_empleados(empleados,cantEmple);
                        break;
            case FILT_HORAS_TRA:
                        filtrar(empleados,empleados_filtrados,cantEmple);
                        break;
            case INF_SUELDOS_CAT:
                        sueldos_categoria(empleados,cantEmple);
                        break;
            case INF_EMP_CAT:
                        empleados_categoria(empleados,cantEmple);
                        break;
           
        }
    }while(op!=SALIR);
    return 0;
}

int menu (void){
    opcion_t op;
    borrar();
    printf("\n***********************\n");
    printf("MENU\n");
    printf("\n 1_Cargar datos");
    printf("\n 2_Informe total de sueldos");
    printf("\n 3_Informe empleados por horas trabajadas");
    printf("\n 4_Informe sueldos por categoria");
    printf("\n 5_Informe empleados por categoria");
    printf("\n 6_Salir\n");
    scanf("%d",&op);
    return (op);
}

void cargar_empleados(registro_t empleados[],int * cantEmple){
    int cod_aux=0;
    do{
        if((*cantEmple)<MAX_EMP){
            printf("Ingrese el codigo del empleado (o para salir):\n");
            scanf("%d",&cod_aux);

            if(cod_aux!=CODIGO_SALIR){
                if(validar_codigo(empleados,cod_aux,*cantEmple)==false){
                    empleados[*cantEmple].cod=cod_aux;
                    printf("Ingrese el Nombre\n");
                    scanf("%s",empleados[*cantEmple].nombre);
                    empleados[*cantEmple].cat=numero_aleatorio(MIN_CAT,MAX_CAT);
                    empleados[*cantEmple].horas=numero_aleatorio(MIN_HR,MAX_HR);
                    empleados[*cantEmple].sue=empleados[*cantEmple].horas*SUELDO_CAT[empleados[*cantEmple].cat-1];
                    if(empleados[*cantEmple].horas>HORAS_EXTRAS){
                        empleados[*cantEmple].sue+=((HORAS_EXTRAS-empleados[*cantEmple].horas)*SUELDO_CAT[empleados[*cantEmple].cat-1]*0.1);
                    }
                    (*cantEmple)++;

                }else{
                    printf("\nCodigo de cliente existente\n");
                }
            }
        }else{
            printf("Ha llegado al maximo de empleados");
        }
    }while(cod_aux!=CODIGO_SALIR);

}

bool validar_codigo(registro_t empleados[],int cod,int cant){

    for(int i=0;i<cant;i++){
        if(empleados[i].cod==cod)return true;
    }
    return false;
}

void imprimir_empleados(registro_t empleados[],int cant){

    printf("Cant de empleados %d\n",cant);
    printf("Cod \t Nombre \t Categoria \t Horas Trabajadas \t Sueldo\n");
    for(int i=0;i<cant;i++){
        printf("%d",empleados[i].cod);
        printf("\t %s",empleados[i].nombre);
        printf("\t\t %d",empleados[i].cat);
        printf("\t\t %d",empleados[i].horas);
        printf("\t\t\t $%2.2f\n",empleados[i].sue);
    }
    pausa();
   
}

int numero_aleatorio(int min,int max){
    return (((rand()%(max-min+1))+min));
}

void pausa (void){
    printf("\nPresione enter para continuar\n");
    fflush(stdin);
    getchar();
}
void borrar (void){
    printf("\e[1;1H\e[2J");
}

void filtrar(registro_t empleados[],registro_t empleados_filtro[],int cant){
    int copia=0;
    for(int emple=0;emple<cant;emple++){
        if(empleados[emple].horas<100){
            empleados_filtro[copia].cat=empleados[emple].cat;
            empleados_filtro[copia].cod=empleados[emple].cod;
            empleados_filtro[copia].horas=empleados[emple].horas;
            empleados_filtro[copia].sue=empleados[emple].sue;
            strcpy(empleados_filtro[copia].nombre,empleados[emple].nombre);
            copia++;
        }
    }
    imprimir_empleados(empleados_filtro,copia);

}
void sueldos_categoria(registro_t empleados[],int cant){
    sueldos_t sueldos={{0,0,0,0},{1,2,3,4}};
    for(int i=0;i<cant;i++){
        sueldos.valores[empleados[i].cat-1]+=empleados[i].sue;
    }
    borrar();
    ordenar(&sueldos,MAX_CAT);
    printf("Cod Cat \t  Total Sueldo\n");
    for(int i=0;i<MAX_CAT;i++){
        printf("%d \t \t %2.2f\n",sueldos.categoria[i],sueldos.valores[i]);
    }
    pausa();

}

void ordenar (sueldos_t *sueldos,int cant){
    float aux;
    int aux2;
    for(int i = 0; i < cant-1; i++){
        for(int j = 0; j <cant-i-1; j++){
            if (sueldos->valores[j] < sueldos->valores[j+1]){
                aux = sueldos->valores[j];
                aux2= sueldos->categoria[j];
                sueldos->valores[j] = sueldos->valores[j+1];
                sueldos->categoria[j]=sueldos->categoria[j+1];
                sueldos->valores[j+1] = aux;
                sueldos->categoria[j+1]=aux2;
            }
        }
    }
}

void empleados_categoria(registro_t empleados[],int cant){
    int emple_cat[MAX_CAT]={0};
    for(int i=0;i<cant;i++){
        emple_cat[empleados[i].cat-1]++;
    }
    printf("Cod Cat \t \t  Cant Empleados\n");
    for(int i=0;i<MAX_CAT;i++){
        printf("%d \t\t\t %d\n",i,emple_cat[i]);
    }
    pausa();
}