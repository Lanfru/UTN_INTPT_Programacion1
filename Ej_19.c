/*
19. Construye un programa que dados el valor de 1 kg de determinada mercadería y la cantidad mercadería
comprada, emite el valor del total a pagar. 
*/

#include <stdio.h>

int main(){
    float presio = 0;
    int cantidad = 0;
    
    printf("Ingrese el precio xKg de mercaderia: ");
    scanf("%f",&presio);
    
    printf("Y la cantidad de Kgs comprados: ");
    scanf("%d",&cantidad);
    
    printf("\nHay que pagar $%f." , presio*cantidad);
    getchar();

    return 0;
}