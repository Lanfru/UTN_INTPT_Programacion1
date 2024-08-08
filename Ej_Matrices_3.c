
3- Realizar un Programa, que cargue una matriz cuadrada de 10 x 10, 
con valores al azar entre 1 y 100, y guarde en un vector, todos los valores que sean números primos.


#include stdio.h
#includetime.h
#includestdlib.h

#define TAMANO 10
#define TAMANO_VEC 20
#define SI 1
#define NO 0

void cargarMatriz(int[TAMANO][TAMANO]);
void verMatriz(int[TAMANO][TAMANO]);
void guardarNumerosPrimos(int[TAMANO][TAMANO] , int[]);
int esPrimo(int);
void mostrarPrimos(int[]);

int main(){
    int primos[TAMANO_VEC]={0};
    int matriz[TAMANO][TAMANO];
    srand(time(NULL));
    
    cargarMatriz(matriz);
    verMatriz(matriz);
    guardarNumerosPrimos(matriz , primos);
    mostrarPrimos(primos);

    return 0;
}

void cargarMatriz(int mat[TAMANO][TAMANO]){
   for(int i=0 ; iTAMANO ; i++){
        for(int j=0 ; jTAMANO ; j++){
            mat[i][j] = (rand() % (100 - 1 + 1)) + 1;
        }
    }
}

void verMatriz(int mat[TAMANO][TAMANO]){
    for(int i=0 ; iTAMANO ; i++){
        for(int j=0 ; jTAMANO ; j++){
            printf(%d   , mat[i][j]);
        }
        printf(n);
    }
}

void guardarNumerosPrimos(int mat[TAMANO][TAMANO] , int primos[]){
    int cant = 0;
    
    for(int i=0 ; iTAMANO ; i++){
        for(int j=0 ; jTAMANO ; j++){
            if(esPrimo(mat[i][j])){
                primos[cant] = mat[i][j];
                cant++;
            }
        }
    }
}

int esPrimo(int numero){
    int cont=2 , numPrimo = SI;
    while(contnumero && numPrimo){
        if((numero % cont) == 0) numPrimo = NO;
        cont++;
    }
    return(numPrimo);
}

void mostrarPrimos(int primos[]){
    int primeraVez = SI;
    
    printf(Los numeros primos fueron);
    for(int i=0 ; iTAMANO ; i++){
        if (primos[i] != 0){
            if(primeraVez){
                printf( %d, primos[i]);
                primeraVez = NO;
            }
            printf(, %d , primos[i]);
        } 
    }
}