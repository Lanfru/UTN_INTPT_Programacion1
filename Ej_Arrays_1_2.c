#include <stdio.h>
#include <ctype.h>

#define TAMAÑO_VECTOR 5 

int sumarVector (int[] , int);
int calcularPromedio(int[] , int);
void cargarVector(int[] , int);

int main(){
    int vec[TAMAÑO_VECTOR];
    int sum=0 , prom=0 , tam=TAMAÑO_VECTOR;
    
    cargarVector(vec , tam);
    sum = sumarVector(vec , tam);
    prom = calcularPromedio(vec , tam);
    
    printf("\nLa suma del Vector es: %d\n" , sum);
    printf("El promedio del Vector es: %d\n" , prom);
    
    getchar();
    return 0;
}


int sumarVector (int vector[] , int tamano){
    int suma = 0;
    
    for(int i=0 ; i<tamano ; i++){
        suma = suma + vector[i];
    }
    
    return(suma);
}

int calcularPromedio(int vector[] , int tamano){
    int suma=0 , promedio = 0;
    
    suma = sumarVector(vector , tamano);
    
    promedio = suma / tamano;
    
    return(promedio);
}

void cargarVector(int vector[] , int tamano){
    for(int i=0 ; i<tamano ; i++){
        printf("Ingrese el valor de la posicion %d: " , i+1);
        scanf("%d" , &vector[i]);
    }
}