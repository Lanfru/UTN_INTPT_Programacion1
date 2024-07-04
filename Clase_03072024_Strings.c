#include <stdio.h>
#include <string.h>

#define MAX_CHAR 50
#define IGUALES 1 
#define DISTINTOS 0

int cuentaLetras(char []);
int compararPalabras(char[] , char[]);

int main(){
    char nombre[MAX_CHAR];
    char nombre_2[MAX_CHAR];
    int cantLetras;

    printf("Ingrese su nombre: ");
    scanf("%s",nombre);

    cantLetras=cuentaLetras(nombre);
    //cantLetras=strlen(nombre);

    printf("Hola %s\n",nombre);
    printf("Tu nombre tiene %d letras",cantLetras);
    
    printf("\nIngrese segundo nombre: ");
    scanf("%s",nombre_2);
    
    if(compararPalabras(nombre , nombre_2) == DISTINTOS) printf("\nLos nombres son distintos");
    else printf("\nLos nombres son iguales");

    return 0;
}

int cuentaLetras (char palabra[]){
    int i=0;

    while(palabra[i++]!='\0');

    return (i-1);
}


int compararPalabras(char txt_1[] , char txt_2[]){
    int sonIguales = IGUALES;
    int cont = 0;
    
    if(cuentaLetras(txt_1) != cuentaLetras(txt_2)) sonIguales = DISTINTOS;
    else{
        while((cont < cuentaLetras(txt_1)) && (sonIguales == IGUALES)){
            if(txt_1[cont] != txt_2[cont]) sonIguales = DISTINTOS;
            cont++;
        }
    }
    
    return (sonIguales);
}