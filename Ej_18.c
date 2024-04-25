/*
18. Construye un programa que pregunte los años que tienes y emita como respuesta el número de días vividos. 
*/

#include <stdio.h>

int main(){
    int ans = 0;
    
    printf("Cuantó año' viviste?\n");
    scanf("%d",&ans);
    
    printf("\nAh, osea que viviste %d dias." , ans*365);
    getchar();

    return 0;
}