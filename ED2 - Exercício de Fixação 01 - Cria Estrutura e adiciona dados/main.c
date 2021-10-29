#include <stdio.h>
#include <malloc.h> //Importa biblioteca de aloca��o din�mica de mem�ria
#include <stdlib.h>
#include <locale.h> //Importa biblioteca de ambiente de trabalho

typedef struct{     //Cria estrutura j� com nome definido por typedef
    char nome[100]; //O campo nome ter� espa�o para 100 caracteres
    int idade;      //idade ser� n�mero inteiro (anos)
    float altura;   // altura ser� decimal (float) para registro em metros.
}pessoa;            //nome da estrutura

int main()
{

    setlocale(LC_ALL, "Portuguese"); //Configura programa para padr�es de localiza��o de ambiente em portugu�s.

    //Declara e instancia "pessoa1" como ponteiro do tipo pessoa
    //e aloca dinamicamente a mem�ria necess�ria para este tipo de estrutura
    pessoa * pessoa1 = (pessoa*) malloc (sizeof(pessoa));

    //Atribui��o dos valores solicitados � cada campo da estrutura.
    strcpy(pessoa1->nome, "Fulano"); //Atribui��o de valor de string n�o pode ser por operador de atribui��o.
    pessoa1 -> idade = 20;
    pessoa1 -> altura = 1.81;

    //Imprime valores na tela
    printf("pessoa1 -> nome = %s\npessoa1 -> idade = %d\n", pessoa1 -> nome, pessoa1 -> idade);
    printf("pessoa1 -> altura = %.2f\n", pessoa1 -> altura); // Altura delimitada em 2 casas decimais.

    //Como pessoa1 � um ponteiro, indicar o mesmo traz o endere�o inicial onde est� a estrutura.
    printf("\nEsta vari�vel e seus dados est�o alocados neste endere�o de mem�ria: %d\n", pessoa1);

    //Aqui, para imprimir o endere�o e n�o os valores, foi colocado "&" (e comercial).
    printf("\nJ� os campos est�o alocados nos seguintes endere�os:\n");
    printf("- nome: %d\n", &pessoa1 -> nome);
    printf("- idade: %d\n", &pessoa1 -> idade);
    printf("- altura: %d\n", &pessoa1 -> altura);

    //Libera mem�ria alocada.
    free (pessoa1);
    return 0;
}
