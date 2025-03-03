#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // Tamaño del arreglo

int main() {
    // Algoritmo 2: Recorrer un arreglo unidimensional
    float B[N];
    float X = 0;

    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Llenar el arreglo con valores aleatorios entre 0 y 100
    for (int i = 0; i < N; i++) {
        B[i] = (float)(rand() % 100);
    }

    // Medir el tiempo de ejecución
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Inicia el contador de tiempo

    // Recorrer el arreglo y asignar los valores a X
    for (int i = 0; i < N; i++) {
        X = B[i];
    }

    end = clock(); // Finaliza el contador de tiempo
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Mostrar el tiempo de ejecución
    printf("Tiempo de ejecución del recorrido del arreglo B: %f segundos\n", cpu_time_used);

    return 0;
}
