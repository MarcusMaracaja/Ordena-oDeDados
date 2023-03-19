/******************************************************************************

                            Explicando o codigo.
                        O main so serve para criar o vetor
                        O imprime é para printar o vetor
    O main chama a função imprimir para mostrar o vetor todo desordenado, em
seguida:
   1) chama o inserctionsort que faz o seguinte:
    * Aqui o segredo está na chave que guardamos para inserir no final do while
    * O while vai comparando de dois em dois de acordo com o indice do for
    * O while sempre pergunta se o valor que está dentro do vetor no indice anterior(aux)
      é maior que o valor que guardamos na chave, se for, o item é copiado para
      a posição que estamos(aux + 1), afinal o valor de aux é o índice - 1,
      decrementa o valor de aux, para então entrar no while novamente e perguntar a
      mesma coisa.
    * depois sai do while com o valor de aux decrementado e atualiza esse vetor na
      posição aux+1 com o que guardamos na chave. Incrementa o índice e vamos novamente
      até fechar o for;
   2) Imprime o resultado.
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionsort(int *vetor, int tamanho){
    int indice, aux, chave;
    for(indice = 0; indice < tamanho ; indice++){
        chave = vetor[indice];
        aux = indice - 1;
        while (aux>=0 && vetor[aux] > chave){
            vetor[aux + 1] = vetor[aux];
            aux--;
            }
            vetor[aux + 1] = chave;
        }
        printf("Vetor ordenado: ");
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
    insertionsort(vetor, tamanho);
    imprime(vetor, tamanho);
}