/******************************************************************************

                            Explicando o codigo.
                        O main so serve para criar o vetor
                        O imprime é para printar o vetor
    O main chama a função imprimir para mostrar o vetor todo desordenado, em
seguida:
   1) chama o quicksort que faz o seguinte:
        * para este algoritimo vamos precisar pensar em recursividade, pois
          a divisão dos vetores ocorre após a escolha de um uma posição pivô
          * Primeiro ele cahma o quicksort que vai separar o vetor analizado
          * para fechar o cliclo da recursividade que acontecerá aqui, temos um
            if que vai fuincioanr caso o vetor tenha mais d eum elemento
            *para separar o vetor em lado esquerdo e direito, precisamos fazer
             a divisão do vetor com a escolha de uim pivô, que firá o papel de
             ponto médio.
             **chama o partition que irá selecionar o pivô de acordo com a divisão
               vamos escolher o pivô, ou o low, ou o high do array, neste caso
               escolheremos o high e guardameos ele a variavel pivo
               e também pegamos o low -1 para guardar o valor mais à esquerda do
               array, ele servirá assim, pos nem sempre o array mais à esquerda é
               o zero.
              * Iniciamos um contador no for que vai incrementado da esquerda para
                o penultimo da direita, perguntando se o conteudo naquela posição
                é menor que o que foi guardado no pivot, se sim, ele incrementa o
                indice do low - 1 e chama o swap para fazer a troca do valor mais
                baixo, e perguntará pelo item seguinte. até percorrer o vetor todo.
              * Saindo do for ele separa os vetores em duas partes, trocando-os de
                lugar e retorna o indice do vetor.
          * Voltando para o quicksort ele se chama novamente pelo lado esquerdo
            e acontece a mesma coisa, e vai fazendo isso até restar apenas dois
            elementos no vetor. E o mesmo será para o lado direito.    
   2) Imprime o resultado.
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void imprime(int *vetor, int tamanho){
    printf("O vetor tem tamanho %d\n", tamanho);
    printf("VETOR: [ ");
    for(int i = 0;i < tamanho;i++){
        printf("%d ", vetor[i]);
        }
    printf("]\n");
}

int main(void){

    int cont, inicio = 0, fim;
    //fim guarda o tamanho total do vetor
    printf("Criando um vetor Randomico\n\n");

    srand(time(NULL));// para mudar os numeros de acordo com a hora
    
    fim = rand() % 100; // tamamho do vetor
    int vetor[fim];
    for(cont = 0;cont < fim; cont++){
        vetor[cont] = rand() % 500; //preenchendo o vetor
    }
    imprime(vetor, fim);
    quicksort(vetor, inicio , fim);
    printf("Vetor ordenado: ");
    imprime(vetor, fim);
}
