/******************************************************************************

                            Explicando o codigo.
                        O main so serve para criar o vetor
                        O imprime é para printar o vetor
    O main chama a função imprimir para mostrar o vetor todo desordenado, em
seguida:
   1) chama o mergeSort que faz o seguinte:
        * para este algoritimo vamos precisar pendar em recursividade, pois
          a divisão dos vetores ocorre até ficar apenas as folhas da árvore
        * o mergeSort começa perguntando se o indice da esquerda é menor que o da
          direita, pois e não for, então não existe mais divisão
            * Sendo maior então vamos dividir esse vetor e achar um ponto médio;
                * E chama recursivamente o mergeSort passando o lado esquerdo
                  da divisão, ou seja com esq sendo o priemiro indice e o pntmedio
                  sendo ultimo item do vetor,a té que não tenha mais como dividir.
                * Cahma recusrsivamente o mergeSort novamente passando os
                  parametrosdo lado direito.
            * Terminando as divisões, chamamos o merge.
              E aqui está a recursividade, dentro da recursividade, qunado o merge
              termina ele volta pro vetor de cima e da merge novamente.
        * o merge: criamos contadores e guardamos os indices n1 e n2 para indicar
          o tamanho dos vetores temporarios dos lados dirteito e esquerdo.
          * Em seguida prenchem o vetor da mesma forma que fazemos quando queremos
            imprimir na tela.
                **OBS: sempre prestar atenção na questão da recursividade, por isso
                       que é preenchido usando E[i] = vetor[esqu + i]; pois o valor
                       de esqu varia de acordo com o nó da árvore que se encontre.
          * Depois de separado em esquerda e direita, vamos comparar, mesclando os
            lados dos vetores que através do while decide quem é o menor, quem vai
            para a esquerda, ou quem vai para a direita. E no final ainda complementa
            se faltar alguma comparação.
          * O algoritimo chama o merge até terminar a recursividade do mergeSort    
   2) Imprime o resultado.
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *vetor, int esqu, int pntmedio, int dir) {
    int i, j, k;
    int n1 = pntmedio - esqu + 1;
    int n2 = dir - pntmedio;
    // Cria vetores temporários
    int E[n1], D[n2];

    // Copia dados para os vetores temporários
    for (i = 0; i < n1; i++)
        E[i] = vetor[esqu + i];
    for (j = 0; j < n2; j++)
        D[j] = vetor[pntmedio + 1 + j];

    // Mescla os vetores temporários de volta para vetor[esqu..dir]
    i = 0; // Índice inicial do primeiro subvetor
    j = 0; // Índice inicial do segundo subvetor
    k = esqu; // Índice inicial do vetor mesclado
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            vetor[k] = E[i];
            i++;
        }
        else {
            vetor[k] = D[j];
            j++;
        }
        k++;
    }
    // Copia os elementos restantes de E[], se houver algum
    while (i < n1) {
        vetor[k] = E[i];
        i++;
        k++;
    }
    // Copia os elementos restantes de D[], se houver algum
    while (j < n2) {
        vetor[k] = D[j];
        j++;
        k++;
    }
}

void mergeSort(int *vetor, int esqu, int dir) {
    if (esqu < dir) {
        // Encontra o ponto médio
        int pntmedio = esqu + (dir - esqu) / 2;
        // Ordena a primeira e a segunda metades
        mergeSort(vetor, esqu, pntmedio);
        mergeSort(vetor, pntmedio + 1, dir);

        // Mescla as metades ordenadas
        merge(vetor, esqu, pntmedio, dir);        
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
    mergeSort(vetor, inicio , fim);
    printf("Vetor ordenado: ");
    imprime(vetor, fim);
}