#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define a estrutura de um nó da lista encadeada
typedef struct node {
    int value;
    struct node* next;
} node_t;

// função que insere um elemento na lista encadeada
void insert(node_t** head, int value) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// função que ordena um bucket usando insertion sort
void sort_bucket(node_t* bucket) {
    if (bucket == NULL || bucket->next == NULL) {
        return;
    }
    node_t* i, *j;
    for (i = bucket->next; i != NULL; i = i->next) {
        int value = i->value;
        for (j = bucket; j != i && j->value > value; j = j->next) {
            j->next->value = j->value;
        }
        j->value = value;
    }
}

// função que implementa o Bucket Sort
void bucket_sort(int arr[], int n) {
    // cria um array de n listas encadeadas
    node_t** buckets = malloc(sizeof(node_t*) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // coloca cada elemento do array em um balde
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / n;
        insert(&buckets[bucket_index], arr[i]);
    }

    // ordena cada balde individualmente
    for (int i = 0; i < n; i++) {
        sort_bucket(buckets[i]);
    }

    // concatena todos os baldes em um array ordenado
    int index = 0;
    for (int i = 0; i < n; i++) {
        node_t* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            node_t* temp = current;
            current = current->next;
            free(temp);
        }
    }

    // libera a memória alocada
    free(buckets);
}

// função que imprime um array

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
    
    bucket_sort(arr, fim);
    printf("Vetor ordenado: ");
    imprime(arr, fim);
    
}