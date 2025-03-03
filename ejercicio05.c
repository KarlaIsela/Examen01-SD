#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define NUM_TESTS 5

// Búsqueda binaria
int binary_search(int arr[], int left, int right, int target, double *time_taken) {
    clock_t start = clock();
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            *time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC * 1000;
            return mid;
        }
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    *time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC * 1000;
    return -1;
}

int main() {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i * 2; // Números pares ordenados
    }
    
    int test_values[NUM_TESTS] = {50, 100, 500, 750, 900};
    double times[NUM_TESTS];
    
    for (int i = 0; i < NUM_TESTS; i++) {
        binary_search(arr, 0, SIZE - 1, test_values[i], &times[i]);
    }
    
    // Guardar los resultados en un archivo
    FILE *fp = fopen("times.txt", "w");
    for (int i = 0; i < NUM_TESTS; i++) {
        printf("Tiempo de búsqueda para %d: %lf ms\n", test_values[i], times[i]);
        fprintf(fp, "%d %lf\n", test_values[i], times[i]);
    }
    fclose(fp);
    
    printf("Resultados guardados en times.txt. Ejecuta 'python plot_times.py' para ver la gráfica.\n");
    return 0;
}
