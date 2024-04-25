/*
20. Construye un programa que permita ingresar los valores de 2 de los ángulos interiores de un triángulo, y se
emita por pantalla el valor del restante. 
*/

#include <stdio.h>

int main(){
    float angulo_1 = 0 , angulo_2 = 0;
    
    printf("Ingrese el valor del primer angulo: ");
    scanf("%f",&angulo_1);
    
    printf("Y el del segundo: ");
    scanf("%f",&angulo_2);
    
    printf("\nEntonces el tercero tiene que valer °%f." , 180-angulo_1-angulo_2);
    getchar();

    return 0;
}