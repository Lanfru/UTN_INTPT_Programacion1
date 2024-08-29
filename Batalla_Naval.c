#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define TAM_TAB 10
#define AGUA 0
#define BARCO 1
#define DESTRUIDO 2
#define VACIO 3
#define MAX_GOLPES 17 // 1*2 2*2 3*1 4*2
#define TAM_NOM 15
#define PUB 0 
#define PRIV 1
#define DOS 2
#define TRES 3 
#define CUATRO 4
#define NO 0 
#define SI 1 

void iniciarJuego(int[TAM_TAB][TAM_TAB] , int[TAM_TAB][TAM_TAB]);
void mostrarTablero(int[TAM_TAB][TAM_TAB] , char[] , int);
void disparar(int[TAM_TAB][TAM_TAB] , int*);
void ponerBarco1(int[TAM_TAB][TAM_TAB]);
void ponerBarco2(int[TAM_TAB][TAM_TAB]);
void ponerBarcoMult(int[TAM_TAB][TAM_TAB] , int);
int pedirCoordenadaX();
int pedirCoordenadaY();
void pedirNombreJugador(char[] , int);

int main(){
    int tablero_Jug1[TAM_TAB][TAM_TAB]={AGUA};
    int tablero_Jug2[TAM_TAB][TAM_TAB]={AGUA};
    
    do{
        iniciarJuego(tablero_Jug1 , tablero_Jug2);
        printf("Presione 'S' para jugar de nuevo ");
    }while(0);

    return 0;
}

void iniciarJuego(int tablero_1[TAM_TAB][TAM_TAB] , int tablero_2[TAM_TAB][TAM_TAB]){
    char jugador_1[TAM_NOM] , jugador_2[TAM_NOM];
    int cantAciertos_1=0 , cantAciertos_2=0;
    pedirNombreJugador(jugador_1 , 1);
    //pedirNombreJugador(jugador_2 , 2);
    
    mostrarTablero(tablero_1 , jugador_1 , PUB);
    ponerBarco1(tablero_1);
    mostrarTablero(tablero_1 , jugador_1 , PUB);
    //ponerBarco2(tablero_1);
    ponerBarcoMult(tablero_1 , DOS);
    mostrarTablero(tablero_1 , jugador_1 , PUB);
    ponerBarcoMult(tablero_1 , TRES);
    mostrarTablero(tablero_1 , jugador_1 , PUB);
    ponerBarco1(tablero_1);
    mostrarTablero(tablero_1 , jugador_1 , PUB);
    ponerBarco1(tablero_1);
    mostrarTablero(tablero_1 , jugador_1 , PRIV);
    disparar(tablero_1, &cantAciertos_1);
    mostrarTablero(tablero_1 , jugador_1 , PRIV);
    printf("%d", cantAciertos_1);
    disparar(tablero_1, &cantAciertos_1);
    printf("%d", cantAciertos_1);
    mostrarTablero(tablero_1 , jugador_1 , PRIV);
}

void mostrarTablero(int tablero[TAM_TAB][TAM_TAB] , char nombre[] , int esVisible){
    char letra = 'A';
    system("clear");
    printf("Está jugando %s \n", nombre);
    
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for(int i=0 ; i<TAM_TAB ; i++){
        for(int j=0 ; j<TAM_TAB ; j++){
            if(j==0){
                printf("%c  ", letra);
                letra = letra + 1;
            }
            if(tablero[i][j]==DESTRUIDO) printf("X ");
            else if(tablero[i][j]==VACIO) printf("  ");
            else if(esVisible == PRIV){
                if((tablero[i][j]==AGUA) || tablero[i][j]==BARCO) printf("O ");
            }else {
                if(tablero[i][j]==BARCO) printf("B ");
                else if(tablero[i][j]==AGUA) printf("O ");
            }
        }
        printf("\n");
    }
}

void disparar(int tablero[TAM_TAB][TAM_TAB] , int* cantAciertos){
    int coorX , coorY;
    char coorLetra;
    printf("Ingrese las coordenadas a donde desea disparar\n");
    
    coorY = pedirCoordenadaY();
    coorX = pedirCoordenadaX();
    
    if(tablero[coorY][coorX]==AGUA) tablero[coorY][coorX] = VACIO;
    else if(tablero[coorY][coorX]==BARCO){
        tablero[coorY][coorX] = DESTRUIDO;
        (*cantAciertos)++;
    } 
}

void ponerBarco1(int tablero[TAM_TAB][TAM_TAB]){
    int coorX , coorY;
    
    printf("Está colocando un barco de 1\n");
    printf("Por favor ingrese las coordenadas de la posicion del barco:\n");
    
    coorY = pedirCoordenadaY();
    coorX = pedirCoordenadaX();
    
    tablero[coorY][coorX] = BARCO;
}

int pedirCoordenadaX(){
    int coorX;
    printf("Ingrese la coordenada de X (1-10): ");
    scanf("%d", &coorX);
    coorX--;
    
    return(coorX);
}

int pedirCoordenadaY(){
    int coorY;
    char coorLetra;
    printf("Ingrese la coordenada de X (A-J): ");
    __fpurge(stdin);
    scanf("%c", &coorLetra);
    switch (coorLetra){
        case 'a': 
        case 'A': coorY=0 ; break;
        case 'b': 
        case 'B': coorY=1 ; break;
        case 'c': 
        case 'C': coorY=2 ; break;
        case 'd': 
        case 'D': coorY=3 ; break;
        case 'e': 
        case 'E': coorY=4 ; break;
        case 'f': 
        case 'F': coorY=5 ; break;
        case 'g': 
        case 'G': coorY=6 ; break;
        case 'h': 
        case 'H': coorY=7 ; break;
        case 'i': 
        case 'I': coorY=8 ; break;
        case 'j': 
        case 'J': coorY=9 ; break;
    }
    return(coorY);
}

void pedirNombreJugador(char nombre[] , int numero){
    printf("Ingrese el nombre del Jugador %d \n", numero);
    scanf("%s",nombre);
}

void ponerBarco2(int tablero[TAM_TAB][TAM_TAB]){
    int coorX , coorY;
    
    printf("Está colocando un barco de 2\n");
    
    printf("Por favor ingrese las coordenadas del primer espacio del barco:\n");
    coorY = pedirCoordenadaY();
    coorX = pedirCoordenadaX();
    tablero[coorY][coorX] = BARCO;
    
    printf("Por favor ingrese las coordenadas del segundo espacio del barco:\n");
    coorY = pedirCoordenadaY();
    coorX = pedirCoordenadaX();
    tablero[coorY][coorX] = BARCO;
}

void ponerBarcoMult(int tablero[TAM_TAB][TAM_TAB] , int cant){
    int coorInX , coorInY , coorFinX , coorFinY , coorInvalidas=SI , espValidos=NO;
    
    printf("Está colocando un barco de 3\n");
    do{
        printf("Por favor ingrese las coordenadas del primer espacio del barco:\n");
        coorInY = pedirCoordenadaY();
        coorInX = pedirCoordenadaX();
        //tablero[coorY][coorX] = BARCO;
    
        printf("Por favor ingrese las coordenadas finales del barco:\n");
        coorFinY = pedirCoordenadaY();
        coorFinX = pedirCoordenadaX();
        //tablero[coorY][coorX] = BARCO;
        
        if((coorInY==coorFinY) && (coorFinX - coorInX == cant-1)) espValidos=SI;
        else if((coorInX==coorFinX) && (coorFinY - coorInY == cant-1)) espValidos=SI;
        
        if((((coorInY==coorFinY) && (coorInX!=coorFinX)) || ((coorInX==coorFinX) && (coorInY!=coorFinY)))&& (espValidos)) coorInvalidas=NO;
        else printf("Debe ingresar unas coordenadas validas, intente nuevamente \n");
    }while(coorInvalidas);
    
    for(int i=0 ; i<cant ; i++){
        if(coorInY==coorFinY) tablero[coorInY][coorInX+i] = BARCO;
        else tablero[coorInY+i][coorInX] = BARCO;
    }
}
