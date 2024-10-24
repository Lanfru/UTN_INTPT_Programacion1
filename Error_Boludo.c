#include <stdio.h>

void menu(int *);
void factura(int *);

int main(){
    int contfact = 1;
    
    menu(&contfact);
    return 0;
}

void menu(int *contfact){
    printf("Menu: %d\n", *contfact);
    factura(contfact);
    printf("Menu++: %d\n", *contfact);
}

void factura(int* contfact){
    printf("Factura: %d\n", *contfact);
    (*contfact)++;
    printf("Factura++: %d\n", *contfact);
}