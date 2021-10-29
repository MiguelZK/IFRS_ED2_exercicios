#include <stdio.h>
#include <malloc.h> //Importa biblioteca de aloca��o din�mica de mem�ria
#include <stdlib.h>
#include <locale.h> //Importa biblioteca de ambiente de trabalho

#define true 1
#define false 0
#define N 10

/*
Agora eu quero que voc�s, em cima do que aprendemos, efetuem um programa que:

Crie uma pilha de N posi��es;

Mostre o endere�o de mem�ria onde a pilha est� alocada.

Inclua novos elementos na pilha (fa�am a quantidade que quiserem), eu quero que a pilha aceite novas inclus�es atrav�s da intera��o com o usu�rio;

Liste todos os itens da pilha ap�s a inclus�o;

Exclua um item da pilha. E o item exclu�do seja direcionado a outro ponteiro na mem�ria;

O item exclu�do seja apresentado ao usu�rio;

Seja apresentado o endere�o de mem�ria deste novo registro de ponteiro;

Ent�o teremos nossa pilha, e um segundo local na mem�ria que ir� receber o item exclu�do da pilha. Este segundo local da mem�ria n�o precisa ser um arranjo.
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
        printf("...est� vazia ainda.");
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
    printf("O registro de valor %d foi exclu�do.\n", *excluido);
    printf("\nEle est� neste endere�o de mem�ria: %d.\n", excluido);
    p->topo--;
    return 1;
}

void reiniciarPilha(PILHA * p){
    p->topo = -1;
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); //Configura programa para padr�es de localiza��o de ambiente em portugu�s.

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
        printf("1) Adicionar n�mero � pilha\n");
        printf("2) Imprimir todos elementos da pilha\n");
        printf("3) Excluir um elemento da pilha\n");
        printf("4) Lembrar onde est� a pilha (na mem�ria)\n");
        printf("5) Reiniciar a pilha\n");
        // printf("5) Teste de incremento do topo\n");
        printf("0) Sair do programa\n");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            printf("Informe o %d� n�mero a ser inserido\n", pil->topo+2);
            scanf("%d", &val.elemento);
            ok = insereElemento(pil, val);
            if(ok){
                printf("Feito\n");
                //printf("Topo ap�s inserir, fora da fun��o � %d\n", pil->topo);
                //printf("Valor no topo da pilha, fora da fun��o � %d\n", pil->A[pil->topo]);
                exibePilha(pil);
            }
            else{
                printf("Hummm... algo n�o deu certo, jovem!\n");
                printf("A pilha est� cheia.\n");
            }
            break;

        case 2:
            exibePilha(pil);
            break;

        case 3:
            ok = excluiElemento(pil);
            if(ok){
                printf("\nBora pra pr�xima opera��o?\n");
                /*printf("O item %d foi exclu�do da pilha.\n", *excluido);
                printf("\nAgora ele est�, temporariamente, neste endere�o: %d.\n", excluido);
                printf("\nAo excluir um novo item, este ser� perdido.\n");*/
            }
            else{
                printf("Hummm... algo n�o deu certo, jovem!\n");
                printf("A pilha estava vazia j�.\n", N);
            }
            break;

        case 4:
            printf("A pilha foi alocada aqui: %d\n", pil);
            break;

        case 5:
            reiniciarPilha(pil);
            printf("A pilha foi despilhada... :�(\n");
            break;

        /*case 5:
            printf("Topo antes de qualquer a��o: %d\n", pil->topo);
            pil->topo++;
            printf("Topo ap�s topo++: %d\n", pil->topo);
            pil->topo += 1;
            printf("Topo ap�s +=: %d\n", pil->topo);
            pil->topo = pil->topo + 1;
            printf("Topo ap�s = pil->topo + 1: %d\n", pil->topo);
            break;
*/
        case 0:
            printf("At� mais!\n");
            free(pil);
            break;

        default:
            printf("Op��o inv�lida. Tente novamente, por favor.\n\n");
            break;
        }
    }
    return 0;
}
