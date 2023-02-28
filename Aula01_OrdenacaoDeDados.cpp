#include<stdio.h>


/*
tudo começa no main que cria um vetor
E lá ele chama a função selectionSort na linha 42
*/

int selectt(int *v, int n, int i)
    /*
    Esta função recebe o que foi colocado na função selectionSort.
    recebe o ponteiro do vetor, o tamanho total e indice i.
    */
{
    int in = i; // apenas atribuindo o in.
    
    for (int j = i + 1; j < n; j++) 
                                       /*
                                       contador que  inicia o valor de acordo com o indice +1,
                                       */         
    {
        
        if(v[j] < v[in]) 
                        /*
                        Perguntamos então: o valor que está nesse índice j é menor que
                        o valor i de entrada?
                        */
        in = j;  
        /* se sim, in recebe o j como novo valor*/                   
    }
   return in; //então retonamos o valor de in, então voltamos pra linha 28 deste código.
}

void swap(int *v, int in, int i)
{
    int temp = v[in];
    v[in] = v[i];
    v[i] = temp;
}


void selectionSort( int *v, int n)
    /*
    função principal que chamamos no main
    entramos no main com um ponteiro do vetor que será o que está
    na primeira posição e o tamanho n dele.
    */
{
  for (int i = 0; i < n; i++){ 
                                /*
                                incrementação da posição indice do
                                vetor para varrer o vetor.
                                Enquanto o indice, que começa no zero,
                                for menor o n, que é o tamanho
                                inteiro do vetor, incrementa a posição.   
                               */

    int in = selectt( v, n, i);
                                /*
                                Em seguida chamamos a função selectt
                                passando o primeiro item do vetor (v),
                                o tamanho total dele (n) e o valor índice
                                atual que estamos trabalhando, agora vamos olhar a função select
                                na linha 9
                                */
    if(in != i){ /*Então se o valor de in que veio de select for diferente do valor de  i*/
        swap(v, in, i);  /* chamamos a função troca*/
    }
  }  

}

void printador(int *v, int n){
    
    for (int x = 0; x < n; x++){
        printf("%d ", v[x]);
    }
    printf("\n");
}

int main(void)
{
    int v[3] = {2, 44, 3};
    printf("%d\n", *v);
    printador(v, 3);
    selectionSort(v, 3);
    printador(v, 3);
}