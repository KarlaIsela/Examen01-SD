#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // Tamaño de la matriz

int main() {
    // Declaración de la matriz
    float A[N][N];
    float X = 0;

    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Llenar la matriz con valores aleatorios entre 0 y 100
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (float)(rand() % 100);
        }
    }

    // Medir el tiempo de ejecución
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Inicia el contador de tiempo

    // Recorrer la matriz y asignar los valores a X
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X = A[i][j];
        }
    }

    end = clock(); // Finaliza el contador de tiempo
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Mostrar el tiempo de ejecución
    printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);

    return 0;
}

