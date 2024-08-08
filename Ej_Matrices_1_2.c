/*
1- Ingresar una matriz, de NxN valores en forma aleatoria, entre 1 y 30, donde N es 5, 
informar el valor máximo y su ubicación.

2-	Ídem el primer ejercicio, nada más que los valores serán entre 1 y 15,
pero informar cuantas veces se repite el máximo dentro de la matriz y en que posiciones.

*/

#include <stdio.h>
#include<time.h>
#include<stdlib.h>

#define TAMANO 5
#define SI 1
#define NO 0

void cargarMatriz(int[TAMANO][TAMANO]);
int buscarValorMax(int[TAMANO][TAMANO]);
void informarPosValMax(int[TAMANO][TAMANO] , int);

int main(){
    int max;
    int matriz[TAMANO][TAMANO];
    srand(time(NULL));
    
    cargarMatriz(matriz);
    max = buscarValorMax(matriz);
    informarPosValMax(matriz , max);

    return 0;
}

void cargarMatriz(int mat[TAMANO][TAMANO]){
    int i , j;

    for(i=0 ; i<TAMANO ; i++){
        for(j=0 ; j<TAMANO ; j++){
            mat[i][j] = (rand() % (15 - 1 + 1)) + 1;
        }
    }

    for(i=0 ; i<TAMANO ; i++){
        for(j=0 ; j<TAMANO ; j++){
            printf("%d  " , mat[i][j]);
        }
        printf("\n");
    }
}

int buscarValorMax(int mat[TAMANO][TAMANO]){
    int max = 0 , primeraVez = SI;
    
    for(int i=0 ; i<TAMANO ; i++){
        for(int j=0 ; j<TAMANO ; j++){
            if (primeraVez){
                primeraVez = NO;
                max = mat[i][j];
            }
            if(max<mat[i][j]) max = mat[i][j];
        }
    }
    return(max);
}

void informarPosValMax(int mat[TAMANO][TAMANO] , int valMax){
    int cont = 0;
    
    printf("\nEl valor maximo (%d), se encuentra en las posiciones: \n", valMax);
    
    for(int i=0 ; i<TAMANO ; i++){
        for(int j=0 ; j<TAMANO ; j++){
            if(mat[i][j] == valMax){
                printf("Fila: %d, Columna: %d\n", i+1 , j+1);
                cont++;
            } 
        }
    }
    printf("Se repitió %d veces", cont);
}