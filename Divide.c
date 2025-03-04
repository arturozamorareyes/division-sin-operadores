#include <stdio.h>
#include <stdlib.h>  // Para abs()

int main() {
    int INT_MAX = 2147483647;  // 2^31 - 1
    int INT_MIN = -2147483648; // -2^31

    int dividendo, divisor;

    // Pedir entrada al usuario
    printf("Ingrese el dividendo: ");
    scanf("%d", &dividendo);
    
    printf("Ingrese el divisor: ");
    scanf("%d", &divisor);

    // Caso especial: División por 0
    if (divisor == 0) {
        printf("Error: No se puede dividir por cero.\n");
        return 1;
    }

    // Caso especial: Evitar el desbordamiento de -2147483648 ÷ -1
    if (dividendo == INT_MIN && divisor == -1) {
        printf("%d\n", INT_MAX);
        return 0;
    }

    // Determinar si el resultado es negativo
    int es_negativo = (dividendo < 0) != (divisor < 0);

    // Convertir a valores absolutos
    int abs_dividendo = abs(dividendo);
    int abs_divisor = abs(divisor);

    int cociente = 0;

    // Resta sucesiva en lugar de usar `/`
    while (abs_dividendo >= abs_divisor) {
        abs_dividendo -= abs_divisor;
        cociente++;
    }

    // Aplicar el signo al resultado
    if (es_negativo) {
        cociente = -cociente;
    }

    // Imprimir el resultado
    printf("Resultado: %d\n", cociente);

    return 0;
}
