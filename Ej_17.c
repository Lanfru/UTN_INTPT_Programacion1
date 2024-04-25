/*
17. Desarrolla un algoritmo que permita, dados ciertos centímetros como entrada de tipo flotante, emitir por
pantalla su equivalencia en pies (enteros) y en pulgadas.
*/

#include <stdio.h>

int main(){
    float centimetros = 0;
    
    printf("Ingrese la cantidad de centimetros: ");
    scanf("%f",&centimetros);
    
    printf("\nSu equivalente en pies es: %f" , centimetros/30,48);
    getchar();

    return 0;
}