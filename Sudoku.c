//Proyecto Sudoku

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM_MAX 9

#define SI 1
#define NO 0

void cargarMatriz(int[TAM_MAX][TAM_MAX]);
void mostrarMatriz(int[TAM_MAX][TAM_MAX]);
int noExisteEnFila(int[TAM_MAX][TAM_MAX] , int , int);
int noExisteEnColumna(int[TAM_MAX][TAM_MAX] , int , int);
int noExisteEnCuadrante(int[TAM_MAX][TAM_MAX], int , int , int);

int main(){
    int sudoku[TAM_MAX][TAM_MAX]={0};
    srand(time(NULL));

    cargarMatriz(sudoku);
    mostrarMatriz(sudoku);

    return 0;
}

void cargarMatriz(int mat[TAM_MAX][TAM_MAX]){
    int num , noExiste;

    for(int i=0 ; i<TAM_MAX ; i++){
        for(int j=0 ; j<TAM_MAX ; j++){
            while(mat[i][j] == 0){
                num = (rand() % (9 - 1 + 1)) + 1;
                if(noExisteEnFila(mat,i,num)){
                    if(noExisteEnColumna(mat,j,num)){
                        if(noExisteEnCuadrante(mat,i,j,num)){
                            noExiste = SI;
                        }else noExiste = NO;
                    }else noExiste = NO;
                }else noExiste = NO;
                //noExiste = verificarNoExiste(mat , num);
                if(noExiste){
                    mat[i][j] = num;
                }
            }
        }
    }
}

void mostrarMatriz(int mat[TAM_MAX][TAM_MAX]){
    for(int i=0 ; i<TAM_MAX ; i++){
        for(int j=0 ; j<TAM_MAX ; j++){
            if(j==(TAM_MAX-1)) printf("%d \n", mat[i][j]);
            else printf("%d | ", mat[i][j]);
        }
    }
}






int verificarNoExiste(int mat[TAM_MAX][TAM_MAX] , int num){
    int esUnico=SI;
    for(int i=0 ; i<TAM_MAX ; i++){
        for(int j=0 ; j<TAM_MAX ; j++){
            if(mat[i][j]== num) esUnico=NO;
        }
    }
    return(esUnico);
}

int noExisteEnFila(int mat[TAM_MAX][TAM_MAX] , int fila , int num){
    int esUnico=SI;

    for(int i=0 ; i<TAM_MAX ; i++){
        if(mat[i][fila]== num){
            printf("Repetido Fil  ");
            esUnico=NO;
        }
    }
    return(esUnico);
}

int noExisteEnColumna(int mat[TAM_MAX][TAM_MAX] , int columna , int num){
    int esUnico=SI;
    
    for(int j=0 ; j<TAM_MAX ; j++){
        if(mat[columna][j]== num){
            printf("Repetido Col  ");
            esUnico=NO;
        } 
    }
    return(esUnico);
}

int noExisteEnCuadrante(int mat[TAM_MAX][TAM_MAX], int fila , int columna , int num){
    /*int esUnico=SI;
    
    return(esUnico);*/
    return 1;
}
