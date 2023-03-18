/******************************************************************************

                            Explicando o codigo.
                        O main so serve para criar o vetor
                        O imprime é para printar o vetor
    O main chama a função imprimir para mostrar o vetor todo desordenado, em
seguida:
   1) chama o selectionsort que faz o seguinte:
    * Inicia com um contador que vai armazenar o indice que está sendo avaliado
    * Entra no for que vai percorrer o vetor inteiro depois de testar as
      condições;
    ** Espera a analise do selectt que retorna um valor de um indice...
    ***** A função select analisa se o conteudo do indice com proximo vetor,
          atribui uma variavel pra guardar esse valor para poder percorrer o for
          sem alterar o indice. Seo que tem no proximo item for menor que o que
          tem nonovosindice, ele altera esse valor para entrar no if do
          selectionsort. Enquanto não for menor, ele salta pra casa(indice)
          seguinte, incrementa o valor do indice e compara se o que tem no
          proximoindice é menor do que o valor que está dentro do vetor na
          posição novoindice.
    ** Voltado após a analise, ele pergunta no IF, o valor retornando do selecct
       é diferente do valor do indice que enviei pro sellect? Se não for, ele
       volta pro for que vai chamar o selecct com um novo valor para indice.
       Ou seja, ele segura o valor do indice até percorrer o for. Mas se o
       valor for diferente, ele chama a função swap.
    *** O swap tem um auxiliarque guarda o valor do indice que saiu lá do
        select num auxiliar. Dai ele copia o valor do indice para o espaço
        do indice que veio do select e  depois atualiza outro com o valor
        que guardamos no auxiliar.
   2) Imprime o resultado.
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


 
int selectt(int *vetor, int tamanho, int indice){
    int novoindice = indice;    
    for(int proximoindice = indice + 1; proximoindice < tamanho; proximoindice++){
        if(vetor[proximoindice] < vetor[novoindice]){
            //se condição aceita o indice do proximo
            //recebe o indice do atual
            novoindice = proximoindice;
        }            
    }
    return novoindice;
}

void swap(int *vetor, int indiceselecionado, int indice){
    int aux = vetor[indiceselecionado];
    vetor[indiceselecionado] = vetor[indice];
    vetor[indice] = aux;
}

void selectionsort(int *vetor, int tamanho){
    
    for(int indice = 0; indice < tamanho ; indice++){
        int indiceselecionado = selectt(vetor, tamanho, indice);
        if(indiceselecionado != indice){
            swap(vetor, indiceselecionado, indice);
        }
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
    selectionsort(vetor, tamanho);
    imprime(vetor, tamanho);
}
