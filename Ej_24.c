/*24. Construye un programa que permita ingresar 2 tiempos, expresados en horas, minutos y segundos, el
mismo debe emitir por pantalla la suma de ambos (también en horas, minutos y segundos).*/

#include <stdio.h>

int main(){
    int horas_1 = 0 , minutos_1 = 0 , segundos_1 = 0 , horas_2 = 0 , minutos_2 = 0 , segundos_2 = 0 , horas_3 = 0 , minutos_3 = 0 , segundos_3 = 0;
    
    printf("Ingrese la primera hora: ");
    scanf("%d",&horas_1);
    
    printf("Ingrese los primeros minutos: ");
    scanf("%d",&minutos_1);
    
    printf("Ingrese los primeros segundos: ");
    scanf("%d",&segundos_1);
    
    printf("Ingrese la segunda hora: ");
    scanf("%d",&horas_2);
    
    printf("Ingrese los segundos minutos: ");
    scanf("%d",&minutos_2);
    
    printf("Ingrese los segundos segundos xd: ");
    scanf("%d",&segundos_2);

    segundos_3 = (segundos_1 + segundos_2) % 60;
    minutos_3 = (segundos_1 + segundos_2) / 60;
    
    minutos_3 = minutos_3 + ((minutos_1 + minutos_2) % 60);
    horas_3 = (minutos_1 + minutos_2) / 60;
    
    horas_3 = horas_3 + horas_1 + horas_2;
    
    printf("La suma de ambos numeros da como resultado %d horas, %d minutos, y %d segundos.", horas_3 , minutos_3 , segundos_3);
    
    getchar();
    return 0;
}
