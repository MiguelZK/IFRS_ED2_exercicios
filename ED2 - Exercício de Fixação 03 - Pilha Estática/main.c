#include <stdio.h>
#include <malloc.h> //Importa biblioteca de alocação dinâmica de memória
#include <stdlib.h>
#include <locale.h> //Importa biblioteca de ambiente de trabalho

#define true 1
#define false 0
#define N 10

/*
Agora eu quero que vocês, em cima do que aprendemos, efetuem um programa que:

Crie uma pilha de N posições;

Mostre o endereço de memória onde a pilha está alocada.

Inclua novos elementos na pilha (façam a quantidade que quiserem), eu quero que a pilha aceite novas inclusões através da interação com o usuário;

Liste todos os itens da pilha após a inclusão;

Exclua um item da pilha. E o item excluído seja direcionado a outro ponteiro na memória;

O item excluído seja apresentado ao usuário;

Seja apresentado o endereço de memória deste novo registro de ponteiro;

Então teremos nossa pilha, e um segundo local na memória que irá receber o item excluído da pilha. Este segundo local da memória não precisa ser um arranjo.
*/

typedef struct{
    int elemento;
}REGISTRO;

typedef struct{
    REGISTRO A[N];
    int topo;
}PILHA;

void inicializar (PILHA * p){
    p->topo = -1;
}

int tamanho (PILHA * p){
    return p->topo+1;
}

void exibePilha (PILHA * p){
    printf("Sua pilha: ");
    if(p->topo == -1)
        printf("...está vazia ainda.");
    else{
        for(int i = p->topo; i >= 0; i--){
            printf("%d ", p->A[i]);
        }
        printf("\n");
    }
}

int insereElemento (PILHA * p, REGISTRO reg){
    if(p->topo >= N - 1)
        return 0;
    p->topo++;
    p->A[p->topo] = reg;
    return 1;
}

int excluiElemento (PILHA * p){
    if(p->topo == -1)
        return 0;
    REGISTRO * excluido = (REGISTRO*) malloc (sizeof(REGISTRO));
    * excluido = p->A[p->topo];
    printf("O registro de valor %d foi excluído.\n", *excluido);
    printf("\nEle está neste endereço de memória: %d.\n", excluido);
    p->topo--;
    return 1;
}

void reiniciarPilha(PILHA * p){
    p->topo = -1;
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); //Configura programa para padrões de localização de ambiente em português.

    int opc, ok;
    REGISTRO val;
    // REGISTRO* excluido = (REGISTRO*) malloc (sizeof(REGISTRO));
    PILHA* pil = (PILHA*) malloc (sizeof(PILHA));

    if(pil != NULL)
        printf("A pilha foi alocada aqui: %d\n", pil);

    inicializar(pil);

    while(opc != 0){
        printf("\n");
        system("pause");
        system("cls");
        printf("MENU:\n");
        printf("1) Adicionar número à pilha\n");
        printf("2) Imprimir todos elementos da pilha\n");
        printf("3) Excluir um elemento da pilha\n");
        printf("4) Lembrar onde está a pilha (na memória)\n");
        printf("5) Reiniciar a pilha\n");
        // printf("5) Teste de incremento do topo\n");
        printf("0) Sair do programa\n");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            printf("Informe o %dº número a ser inserido\n", pil->topo+2);
            scanf("%d", &val.elemento);
            ok = insereElemento(pil, val);
            if(ok){
                printf("Feito\n");
                //printf("Topo após inserir, fora da função é %d\n", pil->topo);
                //printf("Valor no topo da pilha, fora da função é %d\n", pil->A[pil->topo]);
                exibePilha(pil);
            }
            else{
                printf("Hummm... algo não deu certo, jovem!\n");
                printf("A pilha está cheia.\n");
            }
            break;

        case 2:
            exibePilha(pil);
            break;

        case 3:
            ok = excluiElemento(pil);
            if(ok){
                printf("\nBora pra próxima operação?\n");
                /*printf("O item %d foi excluído da pilha.\n", *excluido);
                printf("\nAgora ele está, temporariamente, neste endereço: %d.\n", excluido);
                printf("\nAo excluir um novo item, este será perdido.\n");*/
            }
            else{
                printf("Hummm... algo não deu certo, jovem!\n");
                printf("A pilha estava vazia já.\n", N);
            }
            break;

        case 4:
            printf("A pilha foi alocada aqui: %d\n", pil);
            break;

        case 5:
            reiniciarPilha(pil);
            printf("A pilha foi despilhada... :¬(\n");
            break;

        /*case 5:
            printf("Topo antes de qualquer ação: %d\n", pil->topo);
            pil->topo++;
            printf("Topo após topo++: %d\n", pil->topo);
            pil->topo += 1;
            printf("Topo após +=: %d\n", pil->topo);
            pil->topo = pil->topo + 1;
            printf("Topo após = pil->topo + 1: %d\n", pil->topo);
            break;
*/
        case 0:
            printf("Até mais!\n");
            free(pil);
            break;

        default:
            printf("Opção inválida. Tente novamente, por favor.\n\n");
            break;
        }
    }
    return 0;
}
