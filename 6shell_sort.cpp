/******************************************************************************

                            Explicando o codigo.
                        O main so serve para criar o vetor
                        O imprime é para printar o vetor
    O main chama a função imprimir para mostrar o vetor todo desordenado, em
seguida:
   1) chama o shellsort que faz o seguinte:
        *O loop externo define o espaçamento inicial do intervalo gap, que é
         reduzido pela metade a cada iteração até que o intervalo se torne 1.
         O loop interno compara os elementos em intervalos de gap e troca os
         elementos adjacentes que estão na ordem errada. O programa de exemplo
         cria um array de inteiros, chama a função shellsort para classificar
         o array e imprime o array antes e depois da classificação.            
   2) Imprime o resultado.
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shellsort(int *vetor, int n) {
    int i, j, gap, temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = vetor[i];
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) {
                vetor[j] = vetor[j - gap];
            }
            vetor[j] = temp;
        }
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
    shellsort(vetor, fim);
    printf("Vetor ordenado: ");
    imprime(vetor, fim);
}
