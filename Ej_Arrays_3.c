#include <stdio.h>
#include <ctype.h>

#define TAMAÑO_VECTOR 50

void cargarVectorRandom(int[]);
void calcularCantidadMayores(int[]);
void mostrarVector(int[]);

int main(){
    int vec[TAMAÑO_VECTOR];
    int tam=TAMAÑO_VECTOR;
    
    cargarVectorRandom(vec);
    mostrarVector(vec);
    calcularCantidadMayores(vec);
    
    return 0;
}

void cargarVectorRandom(int vector[]){
    for(int i=0 ; i<TAMAÑO_VECTOR ; i++) vector[i] = (rand() % (20 - 10 + 1)) + 10; 
}

void calcularCantidadMayores(int vector[]){
    int mayor , cant = 1;
    
    for(int i=0 ; i<TAMAÑO_VECTOR ; i++){
        if(i==0){
            mayor = vector[i];
        }
        else{
            if(mayor==vector[i]){
                cant++;
            }
            else{
                if(mayor<vector[i]){
                    mayor = vector[i];
                    cant = 1;
                }
            }
        }
    }
    
    printf("El numero mas alto fué %d, y se repitió %d veces" , mayor , cant);
}

void mostrarVector(int vector[]){
    for(int i=0 ; i<TAMAÑO_VECTOR ; i++){
        printf("En la posicion %d está el numero %d\n" , i+1 , vector[i]);
    }
}