/*
21. Construye un programa que permita ingresar las medidas de los lados de un rectángulo; el mismo debe
emitir por pantalla su superficie y su perímetro. 
*/

#include <stdio.h>

int main(){
    float lado_1 = 0 , lado_2 = 0;
    
    printf("Ingrese el valor del primer lado: ");
    scanf("%f",&lado_1);
    
    printf("Y el del segundo: ");
    scanf("%f",&lado_2);
    
    printf("\nSuperficie: %f." , lado_1*lado_2);
    printf("\nPerimetro: %f." , (lado_1*2)+(lado_2*2));
    getchar();

    return 0;
}