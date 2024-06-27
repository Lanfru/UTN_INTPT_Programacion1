#include <stdio.h>

//Bibliotecas utiles
/*
#include <string.h>
#include <ctype.h>
*/

#define TAMAÑO_VECTOR 5

int main(){
    
    // Definicion
    int temperatura[31];
    
    
    // Inicializacion
    //temperatura = Puntero al inicio del vector;
    temperatura[0] = 15;
    temperatura[1] = 21;
    
    char txt_1[TAMAÑO_VECTOR] = "Holis";
    char txt_2[] = "Holis que tal como va";
    
    
    // Imprimir
    for(int i=0 ; txt_2[i] != 0 ; i++){
        printf("%c" , txt_2[i]);
    }
    
    printf("\n%s" , txt_2);
    
    
    //getchar();
    return 0;
}