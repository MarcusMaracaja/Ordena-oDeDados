/******************************************************************************


*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void counting_sort(int arr[], int n, int max_value) {
    int count[max_value + 1]; // inicializa o array de contagem com 0
    int output[n]; // array de saída
    int i;

    // inicializa o array de contagem
    for (i = 0; i <= max_value; ++i) {
        count[i] = 0;
    }

    // conta o número de ocorrências de cada elemento
    for (i = 0; i < n; ++i) {
        ++count[arr[i]];
    }

    // ajusta o array de contagem para indicar a posição de cada elemento no array ordenado
    for (i = 1; i <= max_value; ++i) {
        count[i] += count[i - 1];
    }

    // constrói o array de saída
    for (i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    // copia o array de saída de volta para o array original
    for (i = 0; i < n; ++i) {
        arr[i] = output[i];
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
    int max_value = arr[0]; // define o primeiro elemento como o maior valor
    for (int i = 1; i < fim; ++i) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    counting_sort(arr, fim, max_value);
    printf("Vetor ordenado: ");
    imprime(arr, fim);
    
}


