#include <stdio.h>

#define MAX_CHAR 50
#define TAM_MAX 2

struct puntos{
    int coordX;
    int coordY;
    int color;
    char simbolo;
    char nombre[MAX_CHAR];
}p1={10 , 30 , 0 , 'X' , "Puntito"}, p2;

typedef struct{
    int valor;
    int esVisible;
}casillero_t;

void mostrarCasillero(casillero_t);
void cargarCasilleros(casillero_t[]);

int main(){
    struct puntos p3;
    
    casillero_t cas={0 , 1} , cas_2={10 , 2};
    casillero_t casilleros[TAM_MAX];
    
    printf("Coordenada en X vale: %d\n", p1.coordX);
    printf("Coordenada en Y vale: %d\n", p1.coordY);
    printf("Color vale: %d\n", p1.color);
    printf("El simbolo es: %c\n", p1.simbolo);
    printf("El nombre es: %s\n\n", p1.nombre);
    
    printf("Coordenada en X vale: %d\n", p3.coordX);
    printf("Coordenada en Y vale: %d\n", p3.coordY);
    printf("Color vale: %d\n", p3.color);
    printf("El simbolo es: %c\n", p3.simbolo);
    printf("El nombre es: %s\n\n", p3.nombre);
    
    printf("Valor casillero: %d\n", cas.valor);
    printf("Es visible?: %d\n", cas.esVisible);
    
     mostrarCasillero(cas_2);
     cargarCasilleros(casilleros);
     mostrarCasillero(casilleros[0]);
    return 0;
}

void mostrarCasillero(casillero_t casi){
    printf("Valor casillero: %d\n", casi.valor);
    printf("Es visible?: %d\n", casi.esVisible);
}

void cargarCasilleros(casillero_t casilleros[]){
    for(int i=0 ; i<TAM_MAX ; i++){
        printf("Ingrese el valor del casillero %d: ", (i+1));
        scanf("%d\n", &casilleros[i].valor);
        printf("El casillero %d es visible?: ", (i+1));
        scanf("%d\n", &casilleros[i].esVisible);
    }
}