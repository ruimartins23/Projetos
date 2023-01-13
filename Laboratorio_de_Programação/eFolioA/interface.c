#include <stdio.h>
#include <stdlib.h>
#include "control.h"
#include "db.h"
#include "control.h"

int main()
{
    int choice;
    printf("Bem vindo ao software de gestão de alunos. O que deseja fazer?\n");
    printf("**** 1. Inscrição ****\n");
    printf("**** 2. Anular ****\n");
    printf("**** 3. Listagem de inscrições por UC e por aluno ****\n");
    printf("**** 4. Calcular Propinas ****\n");
    printf("**** 5. Gravar ****\n");
    printf("**** 6. Sair ****\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        Register();
        break;
    case 2:
        // função anular
        break;
    case 3:
        // função listar
        break;
    case 4:
        // função calcular propinas
        break;
    case 5:
        // funcao gravar
        break;
    case 6:
        exit(1);
        break;

    default:
        printf("Opção inválida. Sair do programa");
        exit(1);
        break;
    }
}
