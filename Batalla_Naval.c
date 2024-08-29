#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define TAM_TAB 10
#define AGUA 0
#define BARCO 1
#define DESTRUIDO 2
#define VACIO 3
#define MAX_GOLPES
#define TAM_NOM 15

void iniciarJuego(int[TAM_TAB][TAM_TAB] , int[TAM_TAB][TAM_TAB]);
void mostrarTablero(int[TAM_TAB][TAM_TAB] , char[]);
void disparar(int[TAM_TAB][TAM_TAB]);
void ponerBarco1(int[TAM_TAB][TAM_TAB]);
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
    //pedirNombreJugador(jugador_1 , 1);
    //pedirNombreJugador(jugador_2 , 2);
    
    mostrarTablero(tablero_1 , jugador_1);
    ponerBarco1(tablero_1);
    mostrarTablero(tablero_1 , jugador_1);
    ponerBarco1(tablero_1);
    mostrarTablero(tablero_1 , jugador_1);
    ponerBarco1(tablero_1);
    mostrarTablero(tablero_1 , jugador_1);
    disparar(tablero_1);
    mostrarTablero(tablero_1 , jugador_1);
}

void mostrarTablero(int tablero[TAM_TAB][TAM_TAB] , char nombre[]){
    char letra = 'A';
    system("clear");
    printf("Está jugando %s \n", nombre);
    
    printf("  1 2 3 4 5 6 7 8 9 10\n");
    for(int i=0 ; i<TAM_TAB ; i++){
        for(int j=0 ; j<TAM_TAB ; j++){
            if(j==0){
                printf("%c ", letra);
                letra = letra + 1;
            }
            if(tablero[i][j]==AGUA) printf("O ");
            else if(tablero[i][j]==DESTRUIDO) printf("X ");
            else if(tablero[i][j]==BARCO) printf("B ");
            else if(tablero[i][j]==VACIO) printf("  ");
        }
        printf("\n");
    }
}

void disparar(int tablero[TAM_TAB][TAM_TAB]){
    int coorX , coorY;
    char coorLetra;
    printf("Ingrese las coordenadas a donde desea disparar\n");
    
    coorY = pedirCoordenadaY();
    coorX = pedirCoordenadaX();
    
    if(tablero[coorY][coorX]==AGUA) tablero[coorY][coorX] = VACIO;
    else if(tablero[coorY][coorX]==BARCO) tablero[coorY][coorX] = DESTRUIDO;
}

void ponerBarco1(int tablero[TAM_TAB][TAM_TAB]){
    int coorX , coorY;
    char coorLetra;
    
    printf("Está colocando un barco de 1:\n");
    
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