/*76. Escribe un programa teniendo en cuenta las siguientes funciones
 leeOpcion lee la opción deseada y comprueba su validez
 menú muestra el menú en la pantalla
 cuadrado, circulo, rectángulo, trapecio, triángulo calculan la superficie
correspondiente.*/

#include <stdio.h>

#define PI 3.14159265359

int leeOpcion();
void menu();
void cuadrado();
void circulo();
void rectangulo();
void trapecio();
void triangulo();
float pedirDatoValido(int);

int main(){
    int opcion;
    
    do{
        menu();
        opcion = leeOpcion();
        switch(opcion){
            case 1: cuadrado(); break;
            case 2: circulo(); break;
            case 3: rectangulo(); break;
            case 4: trapecio(); break;
            case 5: triangulo(); break;
        }
    }while(opcion != 0);
    
    printf("Adios!");

    getchar();
    return 0; 
}

int leeOpcion(){
    int opcion;
    do{
        printf("Ingrese que opcion desea realizar: ");
        scanf("%d",&opcion);
        if((opcion < 0)||(opcion > 5)) printf("Ingrese un valor valido\n");
    }while((opcion < 0)||(opcion > 5));
    
    return(opcion);
}

void menu(){
    printf("\n************************************\n");
    printf("****** CÁLCULO DE SUPERFICIES ******\n");
    printf("1. Cuadrado (lado*lado) \n");
    printf("2. Círculo (pi*radio*radio)\n");
    printf("3. Rectángulo (base*altura)\n");
    printf("4. Trapecio (base1+base2)*altura/2)\n");
    printf("5. Triángulo (base*altura)/2)\n");
    printf("0. Salir del programa\n");
    printf("************************************\n");
}

void cuadrado(){
    float lado = 0 , area = 0;
    
    lado = pedirDatoValido(1);
    area = lado * lado;
    
    printf("El Area del Cuadrado es de: %f\n" , area);
}

void circulo(){
    float radio = 0 , area = 0;
    
    radio = pedirDatoValido(2);
    area = radio * radio * PI;
    
    printf("El Area del Circulo es de: %f\n" , area);
}

void rectangulo(){
    float base = 0 , altura = 0 , area = 0;
    
    base = pedirDatoValido(3);
    altura = pedirDatoValido(4);
    area = base * altura;
    
    printf("El Area del Rectangulo es de: %f\n" , area);
}

void trapecio(){
    float base = 0 , base_2 , altura = 0 , area = 0;
    
    base = pedirDatoValido(3);
    base_2 = pedirDatoValido(5);
    altura = pedirDatoValido(4);
    area = ((base+base_2)*altura/2);
    
    printf("El Area del Rectangulo es de: %f\n" , area);
}

void triangulo(){
    float base = 0 , altura = 0 , area = 0;
    
    base = pedirDatoValido(3);
    altura = pedirDatoValido(4);
    area = ((base * altura) / 2);
    
    printf("El Area del Rectangulo es de: %f\n" , area);
}

float pedirDatoValido(int opcion){
    float dato = 0;
    do{
        printf("Ingrese el valor ");
        switch(opcion){
            case 1: printf("del lado: "); break;
            case 2: printf("del radio:"); break;
            case 3: printf("de la base:"); break;
            case 4: printf("de la altura: "); break;
            case 5: printf("de la segunda base: "); break;
        }
        scanf("%f",&dato);
        
        if(dato < 0) printf("Valor invalido, debe ser positivo.\n");
    }while(dato < 0);
    
    return(dato);
}