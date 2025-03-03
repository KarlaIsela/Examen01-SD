#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // Tamaño del arreglo

int main() {
    // Algoritmo 1: Arreglo unidimensional
    float A[N];
    float X = 0;

    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Llenar el arreglo con valores aleatorios entre 0 y 100
    for (int i = 0; i < N; i++) {
        A[i] = (float)(rand() % 100);
    }

    X = (int)(rand() % 9999);

    // Medir el tiempo de ejecución
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Inicia el contador de tiempo

    // Acceder a un elemento del arreglo
    X = A[0];

    end = clock(); // Finaliza el contador de tiempo
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Mostrar el tiempo de ejecución
    printf("Tiempo de ejecución del acceso a A[0]: %f segundos\n", cpu_time_used);

    return 0;
}
