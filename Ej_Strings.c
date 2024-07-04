#include <stdio.h>
#define MAX_CHAR 50

int dimension(char[]);
void pasaMinuscula(char[]);
int vocales(char[]);
void invertir(char[]);
void copiarCadena(char[] , char[]);

int main(){
    char cadena[MAX_CHAR];

    printf("Ingrese una cadena: ");
    scanf("%s",cadena);

    printf("\nLa cadena tiene %d caracteres", dimension(cadena));

    pasaMinuscula(cadena);
    printf("\nLa cadena en minuscula sería: %s", cadena);

    printf("\nLa cadena tiene %d vocales", vocales(cadena));
    
    invertir(cadena);
    printf("\nLa cadena al reves seria: %s ", cadena);

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
        switch(cadena[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': cant++;
        }
        //if((cadena[i]=='a') || (cadena[i]=='e') || (cadena[i]=='i') || (cadena[i]=='o') || (cadena[i]=='u')) cant++;
    }

    return (cant);
}


void invertir(char cadena[]){
    char cadenaAux[MAX_CHAR];
    int largoCadena = dimension(cadena);
    
    copiarCadena(cadena , cadenaAux);
    
    for(int i=0 ; i<largoCadena ; i++){
        cadena[i] = cadenaAux[largoCadena - i -1];
    }
}

void copiarCadena(char cadena[] , char cadenaAux[]){
    for(int i=0 ; cadena[i] ; i++) cadenaAux[i] = cadena[i];
}
