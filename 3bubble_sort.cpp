/******************************************************************************

                            Explicando o codigo.
                        O main so serve para criar o vetor
                        O imprime é para printar o vetor
    O main chama a função imprimir para mostrar o vetor todo desordenado, em
seguida:
   1) chama o bubble_sort que faz o seguinte:
    * Inicia um contador que serve para contar qunatas pasagens faremos até
      terminar o swaps;
    * Dentro há outro for que vai do primeiro item até tamanho, menos o contador - 1
      Pois em cada passagem os ultimos vetores estarão sendo determinados, por isso não
      é necessário compara-los novamente, e aqui está o segredo desse algoritimo.
        * dentro deste for iniciamos um auxiliar(proximo) para comparar se o item
          que está nesta posição posterior é  menor que a posição indice, que é o
          contador deste for, se for, swap neles!
        * vai seguindo o for até chegar o último item da condição. saindo deste for
          incrementa-se o contador e repete a operação. 
   2) Imprime o resultado.
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *vetor, int indiceselecionado, int indice){
    int aux = vetor[indiceselecionado];
    vetor[indiceselecionado] = vetor[indice];
    vetor[indice] = aux;
}

void bubble_sort(int *vetor, int tamanho){
        
    for(int cont = 0; cont < tamanho; cont++ ){        
        for(int indice = 0; indice < (tamanho - cont - 1); indice++){
            int proximo = indice + 1;
            if (vetor[proximo] < vetor[indice]){
                swap(vetor, proximo, indice);
                }           
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

    int cont, tamanho;

    printf("Criando um vetor Randomico\n\n");

    srand(time(NULL));// para mudar os numeros de acordo com a hora
    
    tamanho = rand() % 100; // tamamho do vetor
    int vetor[tamanho];
    for(cont = 0;cont < tamanho; cont++){
        vetor[cont] = rand() % 500; //preenchendo o vetor
    }
    imprime(vetor, tamanho);
    bubble_sort(vetor, tamanho);
    imprime(vetor, tamanho);
}