#include <stdio.h>

//Prototipo de funciones:
int ingresarCodigoVenta(void);
int ingresarCantidadVenta(void);
float ingresarPrecioVenta(void);
float calcularVenta(int, float);
void calculaImprime(float, int, int, int);
void bienvenidaAlParcial(void);

int main(void){
    int codigo, cantidad, cantidadVentas = 0, op = 1, codigoMax = 0, codigoMin = 0, primeraVenta = 1;
    float precio, precioTotal = 0, valorVenta = 0, precioMin, precioMax;
    
    bienvenidaAlParcial();
    do{
        codigo = ingresarCodigoVenta();
        if (codigo >= 0){
            cantidad = ingresarCantidadVenta();
            precio = ingresarPrecioVenta();
            valorVenta = calcularVenta(cantidad, precio);
            
            if(primeraVenta){
                codigoMax = codigo;
                codigoMin = codigo;
                precioMax = valorVenta;
                precioMin = valorVenta;
                
                primeraVenta = 0;
            }
            else{
                if(precioMin > valorVenta){
                    codigoMin = codigo;
                    precioMin = valorVenta;
                }
                
                if(precioMax < valorVenta){
                    codigoMax = codigo;
                    precioMax = valorVenta;
                }
            }
            
            cantidadVentas++;
            precioTotal = precioTotal + valorVenta;
            printf("***********************************\n");
        }
        else op = 0;
    }while(op);
    
    calculaImprime(precioTotal, codigoMax, codigoMin, cantidadVentas);
    
    getchar();
    return 0;
}

int ingresarCodigoVenta(void){
    int codigo;
    
    printf("Ingrese el Codigo del producto: ");
    scanf("%d", &codigo);
    
    return (codigo);
}

int ingresarCantidadVenta(void){
    int cantidad;
    
    printf("Ingrese la cantidad vendida: ");
    scanf("%d", &cantidad);
    while(cantidad <= 0){
        printf("La cantidad debe ser positiva\n");
        printf("Por favor, ingrese una cantidad positiva: ");
        scanf("%d", &cantidad);
    }
    return (cantidad);
    
}

float ingresarPrecioVenta(void){
    float precio;
    
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);
    while(precio <= 0){
        printf("El precio debe ser positivo\n");
        printf("Por favor, ingrese un precio positivo: ");
        scanf("%f", &precio);
    }
    return (precio);
    
}

float calcularVenta(int cantidad, float precio){
    float valorVentas;
    valorVentas = cantidad * precio;
    
    return(valorVentas);
}

void calculaImprime(float totalVentas, int maxCodigo, int minCodigo, int contadorVentas){
    printf("\nTotal de ventas del dia: $%.2f\n", totalVentas);
    printf("Codigo del producto con la venta mas alta: %d\n", maxCodigo);
    printf("Codigo del producto con la venta mas baja: %d\n", minCodigo);
    printf("Numero total de ventas ingresadas: %d\n", contadorVentas);
}

void bienvenidaAlParcial(){
    printf("Hola Profe, y bienvenido al Primer Parcial de Programacion I\n");
    printf("Alumno: Lanfranchi Agustin INSPT T.N\n");
    printf("Presione ENTER para comenzar con el Parcial\n");
    getchar();
}
