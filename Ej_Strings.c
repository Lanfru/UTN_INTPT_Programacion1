#include <stdio.h>
#define MAX_CHAR 50

int dimension(char[]);
void pasaMinuscula(char[]);
int vocales(char[]);
void invertir(char[]);

int main(){
    char cadena[MAX_CHAR];
    
    printf("Ingrese una cadena: ");
    scanf("%s",cadena);
    
    printf("\nLa cadena tiene %d caracteres", dimension(cadena));
    
    pasaMinuscula(cadena);
    printf("\nLa cadena en minuscula sería: %s", cadena);
    
    printf("\nLa cadena tiene %d vocales", vocales(cadena));

    return 0;
}

int dimension(char cadena[]){
    int i=0;

    while(cadena[i++]!='\0');

    return (i-1);
}


void pasaMinuscula(char cadena[]){
    for(int i=0 ; cadena[i] ; i++){
        if((cadena[i]>='A') && (cadena[i]<='Z')) cadena[i] = cadena[i] + 32;
    }
}


int vocales(char cadena[]){
    int cant = 0;
    for(int i=0 ; cadena[i] ; i++){
        if((cadena[i]=='a') || (cadena[i]=='e') || (cadena[i]=='i') || (cadena[i]=='o') || (cadena[i]=='u')) cant++;
    }
    
    return (cant);
}


void invertir(char cadena[]){
    char cadenaAux[]
}