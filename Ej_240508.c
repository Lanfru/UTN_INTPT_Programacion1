#include <stdio.h>

#define VAL_MIN 1
#define VAL_MAX 11

#define FALSO 0 
#define VERDADERO 1

int main(){
    int num_tabla = 0 , salir = FALSO , tabla_cont = VAL_MIN;
    
    printf("Ingrese el numero cuya tabla quiera saber: ");
    scanf("%d",&num_tabla);
        
    while(!salir){
        while(tabla_cont != VAL_MAX) printf("%d x %d = %d\n", num_tabla, tabla_cont++, num_tabla*tabla_cont);
        
        printf("Ingrese que otro numero quiere saber su tabla, si quiere salir presione 0: ");
        scanf("%d",&num_tabla);
        
        if(!num_tabla) salir = VERDADERO;
            else tabla_cont = VAL_MIN;
            
    }
    printf("Adios");
    
    getchar();
    return 0;
}