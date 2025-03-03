#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // Tamaño de la matriz
#define REPS 5

int main() {
    // Declaración de la matriz tridimensional en el heap
    float (*A)[N][N] = malloc(sizeof(float) * N * N * N);
    if (A == NULL) {
        printf("Error al asignar memoria!\n");
        return 1;
    }

    float value = 0.0;

    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Llenar la matriz con valores aleatorios entre 0 y 100
    printf("Llenando la matriz...\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                A[i][j][k] = (float)(rand() % 100);
            }
        }
    }
    printf("Matriz llena correctamente\n");

    // Variables para medir el tiempo
    clock_t start, end;
    double cpu_time_used;

    // Ejecutar la medición 5 veces
    for (int r = 0; r < REPS; r++) {
        printf("Iniciando repetici%cn %d\n", 162, r + 1);
        start = clock();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    value = A[i][j][k];
                }
            }
        }

        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tiempo de ejecuci%cn %d: %f segundos\n", 162, r + 1, cpu_time_used);
    }

    printf("Programa terminado\n");
    free(A); // Liberar la memoria

    return 0;
}