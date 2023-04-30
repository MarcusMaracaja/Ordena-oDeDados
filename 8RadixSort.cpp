/******************************************************************************


*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função de ordenação do Radix Sort
void radix_sort(int arr[], int n) {
    int max = find_max(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n]; // vetor de saída
        int count[10] = {0}; // array de contagem com 10 posições

        // conta o número de ocorrências de cada dígito
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        // ajusta o array de contagem para indicar a posição de cada elemento no array ordenado
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // constrói o array de saída
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // copia o array de saída de volta para o array original
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}
void imprime(int *arr, int tamanho){
    printf("O vetor tem tamanho %d\n", tamanho);
    printf("VETOR: [ ");
    for(int i = 0;i < tamanho;i++){
        printf("%d ", arr[i]);
        }
    printf("]\n");
}

int main(void){

    int cont, inicio = 0, fim;
    //fim guarda o tamanho total do vetor
    printf("Criando um vetor Randomico\n\n");

    srand(time(NULL));// para mudar os numeros de acordo com a hora
    
    fim = rand() % 100; // tamamho do vetor
    int arr[fim];
    for(cont = 0;cont < fim; cont++){
        arr[cont] = rand() % 500; //preenchendo o vetor
    }
    
    imprime(arr, fim);
    
    radix_sort(arr, fim);
    printf("Vetor ordenado: ");
    imprime(arr, fim);
    
}