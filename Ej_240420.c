#include <stdio.h>
#include <stdio_ext.h>

int main(){
    float operando_1 = 0 , operando_2 = 0;
    char operacion;
    
    printf("Ingrese el primer numero: ");
    scanf("%f",&operando_1);
    
    printf("Y el segundo: ");
    scanf("%f",&operando_2);
    
    printf("Que operacion desea realizar?\n");
    //fflush(stdin)
    __fpurge(stdin);
    scanf("%c" , &operacion);

    switch (operacion) {
        case '+': printf("\nLa suma da como resultado: %f" , operando_1 + operando_2); break;
        case '-': printf("\nLa resta da como resultado: %f" , operando_1 - operando_2); break;
        case '*': printf("\nLa multiplicacion da como resultado: %f" , operando_1 * operando_2); break;
        case '/': 
            if (operando_2 == 0)printf("\No papi, aca no se divide por 0.");
            else printf("\nLa division da como resultado: %f" , operando_1 / operando_2);
            break;
        default: printf("\nNa, la proxima ingresa bien las cosas padre"); break;
    }
    
    getchar();
    return 0;
}