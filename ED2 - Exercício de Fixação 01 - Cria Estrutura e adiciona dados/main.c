#include <stdio.h>
#include <malloc.h> //Importa biblioteca de alocação dinâmica de memória
#include <stdlib.h>
#include <locale.h> //Importa biblioteca de ambiente de trabalho

typedef struct{     //Cria estrutura já com nome definido por typedef
    char nome[100]; //O campo nome terá espaço para 100 caracteres
    int idade;      //idade será número inteiro (anos)
    float altura;   // altura será decimal (float) para registro em metros.
}pessoa;            //nome da estrutura

int main()
{

    setlocale(LC_ALL, "Portuguese"); //Configura programa para padrões de localização de ambiente em português.

    //Declara e instancia "pessoa1" como ponteiro do tipo pessoa
    //e aloca dinamicamente a memória necessária para este tipo de estrutura
    pessoa * pessoa1 = (pessoa*) malloc (sizeof(pessoa));

    //Atribuição dos valores solicitados à cada campo da estrutura.
    strcpy(pessoa1->nome, "Fulano"); //Atribuição de valor de string não pode ser por operador de atribuição.
    pessoa1 -> idade = 20;
    pessoa1 -> altura = 1.81;

    //Imprime valores na tela
    printf("pessoa1 -> nome = %s\npessoa1 -> idade = %d\n", pessoa1 -> nome, pessoa1 -> idade);
    printf("pessoa1 -> altura = %.2f\n", pessoa1 -> altura); // Altura delimitada em 2 casas decimais.

    //Como pessoa1 é um ponteiro, indicar o mesmo traz o endereço inicial onde está a estrutura.
    printf("\nEsta variável e seus dados estão alocados neste endereço de memória: %d\n", pessoa1);

    //Aqui, para imprimir o endereço e não os valores, foi colocado "&" (e comercial).
    printf("\nJá os campos estão alocados nos seguintes endereços:\n");
    printf("- nome: %d\n", &pessoa1 -> nome);
    printf("- idade: %d\n", &pessoa1 -> idade);
    printf("- altura: %d\n", &pessoa1 -> altura);

    //Libera memória alocada.
    free (pessoa1);
    return 0;
}
