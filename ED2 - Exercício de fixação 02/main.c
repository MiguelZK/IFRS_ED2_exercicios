#include <stdio.h>
#include <malloc.h> //Importa biblioteca de alocação dinâmica de memória
#include <stdlib.h>
#include <locale.h> //Importa biblioteca de ambiente de trabalho

#define N 5

typedef struct{
    int elemento;
}REGISTRO;

typedef struct{
    REGISTRO A[N];
    int nroElem;
}LISTA;

int insereElemento (LISTA* l, int elem){
    if(l->nroElem < N){
        if(l->nroElem == 0){
            l->A[0].elemento = elem;
        }
        else{
            for(int i = l->nroElem-1; i >= 0; i--){
                if(l->A[i].elemento > elem){
                    l->A[i+1].elemento = l->A[i].elemento;
                    l->A[i].elemento = elem;
                }
                else{
                    l->A[i+1].elemento = elem;
                    l->nroElem++;
                    return 1;
                }
            }
        }
        l->nroElem++;
        return 1;
    }
    else{
        return 0;
        }
}

void inicializar (LISTA* l){
    l->nroElem = 0;
}

void imprime (LISTA* l){
    for(int i = 0; i < l->nroElem; i++){
        printf("Elemento %d: %d\n", i, l->A[i].elemento);
    }
}

int exclui (LISTA* l, int pos){
    if(pos >= l->nroElem || pos < 0)
        return 0;
    for(int i = pos; i < l->nroElem; i++){
        l->A[i].elemento = l->A[i+1].elemento;
    }
    l->nroElem--;
    return 1;
}

void reinicializar (LISTA* l){
    l->nroElem = 0;
    /*for(int i = 0; i < N; i++){
        l->A[i].elemento = 0;
    }*/
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); //Configura programa para padrões de localização de ambiente em português.

    int val, pos, op = 1, ok;
    LISTA* primeira = (LISTA*) malloc (sizeof(LISTA));

    //Inicializa a lista
    inicializar (primeira);

    //Adicionando elemento na lista
    insereElemento(primeira, 15);
    insereElemento(primeira, 10);
    insereElemento(primeira, 30);
    insereElemento(primeira, 20);
    insereElemento(primeira, 45);

    //imprimindo os valores em ordenados (como já estão no arranjo)
    printf("Imprimindo a lista de elementos do arranjo:\n");
    imprime(primeira);

    //Exclui o 2º elemento do registro, reordena e reimpirme o registro e a quantidade de elementos.
    exclui(primeira, 1);
    printf("\nImprimindo a lista de elementos do arranjo (após excluir o 2º elemento:\n");
    imprime(primeira);
    printf("Nº de elementos no momento: %d", primeira->nroElem);

    //Código BÔNUS para testar o sistema (não vi motivo pra apagar depois de feito).
    /*while(op != 0){
        printf("MENU:\n");
        printf("1) Adicionar número ao arranjo\n");
        printf("2) Imprimir todos elementos do arranjo\n");
        printf("3) Excluir um elemento do arranjo\n");
        printf("0) Sair do programa\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("Informe o %dº número a ser inserido\n", primeira->nroElem+1);
            scanf("%d", &val);
            ok = insereElemento(primeira, val);
            if(ok)
                printf("Feito\n");
            else
                printf("Hummm... algo não deu certo, jovem!\n");
                printf("Provavelmente o arranjo está cheio.\n");
            break;

        case 2:
            imprime(primeira);
            break;

        case 3:
            printf("Informe a posição do número a ser excluído\n");
            scanf("%d", &pos);
            ok = exclui(primeira, pos);
            if(ok)
                printf("Feito\n");
            else
                printf("Hummm... algo não deu certo, jovem!\n");
                printf("A posição não está ocupada ou é maior que o valor máximo (que é %d)\n", N);
            break;

        case 0:
            printf("Até mais!\n");
            free(primeira);
            break;

        default:
            printf("Opção inválida. Tente novamente, por favor.\n\n");
            break;
        }

    }*/

    return 0;
}
