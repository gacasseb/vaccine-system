#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "Pessoa.h"
#include "Prioridade.h"
#include "Vacina.h"
#include "Vacinacao.h"
#include "Relatorio.h"

/**
* Funcao main
**/
int main()
{
    char entrada;
    entrada = 'a';

    LISTA * povo;
    povo = criaLista();

    LISTA_PRIORIDADE * prioridade;
    prioridade = criaListaPrioridade();

    LISTA_VACINA * vacinas;
    vacinas = criaListaVacina();

    LISTA_VACINACAO * vacinacao;
    vacinacao = criaListaVacinacao();

    while ( entrada != '0' ) {

        printf("---------------------------------------- MENU ----------------------------------------\n\n");

        // Imprime o menu
        printf("0 - Sair\n");
        // printf("---------- PESSOAS ----------\n");
        printf("1 - Registrar uma pessoa\n");
        printf("2 - Remover uma pessoa\n");
        // printf("------ GRUPO DE PRIORIDADES ------\n");
        printf("3 - Liberar grupo de prioridade\n");
        // printf("---------- VACINA ----------\n");
        printf("4 - Registrar uma vacina\n");
        printf("9 - Alterar estoque de uma vacina\n");
        // printf("---------- VACINACAO ----------\n");
        printf("5 - Registrar uma vacinacao\n");
        // printf("---------- VISUALIZAR ----------\n");
        printf("6 - Relatorios\n");
        printf("7 - Visualizar\n");
        printf("\n");

        scanf("%c", &entrada);
        getchar();

        if ( entrada == '1' ) {
            inserePessoa(povo);
        }

        if ( entrada == '2' ) {
            removePessoa(povo);
        }

        if ( entrada == '3' ) {
            registraPrioridade(prioridade);
        }

        if ( entrada == '4' ) {
            registraVacina(vacinas);
        }

        if ( entrada == '5' ) {
            registraVacinacao(vacinacao, povo, vacinas, prioridade);
        }

        if ( entrada == '7' ) {
            visualizar(povo, vacinas);
        }

        if ( entrada == '9' ) {
            alteraEstoque(vacinas);
        }

        if ( entrada == '6' ) {
            relatorios(vacinas);
        }
    }

    free(povo);
    free(prioridade);
    free(vacinas);
    free(vacinacao);

    return 1;
}

relatorios(LISTA_VACINA * lista_vacinas)
{
    printf("\n");
    printf("---------------------------------------- RELATORIOS ----------------------------------------\n\n");

    char entrada;
    entrada = 'a';

    while ( entrada != '0' ) {

        printf("1 - Gerar relatorio de vacinas\n");

        scanf("%c", &entrada);
        getchar();

        if ( entrada == '1' ) {
            geraRelatorioVacinas(lista_vacinas);
        }
    }
}

visualizar(LISTA *povo, LISTA_VACINA * vacinas)
{
    char entrada;
    entrada = 'a';
    printf("\n");
    printf("---------------------------------------- VISUALIZAR ----------------------------------------\n\n");
    while( entrada != '0' ) {

        printf("0 - Voltar\n");
        printf("1 - Registro de pessoas\n");
        printf("2 - Registro de vacinas\n");

        scanf("%c", &entrada);
        getchar();

        if ( entrada == '1' ) {
            showPessoas(povo);
        }

        if ( entrada == '2' ) {
            showVacinas(vacinas);
        }
    }
}
