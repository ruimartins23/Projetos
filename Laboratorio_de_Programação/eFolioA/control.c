#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "db.h"

void Register()
{
    char nacionalidade[50], nome[50];
    int id;
    Student student;

    id = rand();
    student.id = id;

    printf("Insira o seu nome: ");
    gets(nome);
    student.name = (char *)malloc(strlen(nome) + 1);
    strcpy(student.name, nome);

    printf("Insira a sua nacionalidade: ");
    gets(nacionalidade);
    student.nationality = (char *)malloc(strlen(nacionalidade) + 1);
    strcpy(student.nationality, nacionalidade);

    printf("Para resumir, o seu id é %d, a sua nacionalidade é %s e o seu nome é %s", student.id, student.nationality, student.name);
}