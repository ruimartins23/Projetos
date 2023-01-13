#include "conjunto.h"

using namespace std;

int main()
{
    int choice;

    cout << "XXXXXXXXX Bem vindo ao programa das Atividaes imersivas!! XXXXXXXXX\n"
         << endl;
    cout << "Deseja criar um conjunto de atividades(0), ou juntar duas atividades para ter as melhores coordenadas?(1)" << endl;
    cin >> choice;

    if (choice == 0)
    {
        int n;

        cout << "Quantas atividades deseja inserir:" << endl;
        cin >> n;

        Conjunto conjAtividades(n);

        cout << "Antes de ser ordenado:" << endl;
        conjAtividades.displayAtividades();

        conjAtividades.ordenaConjuntoAgencia();
        cout << "Ordenado por Agencia: " << endl;
        conjAtividades.displayAtividades();

        conjAtividades.ordenaConjuntoNarrativa();
        cout << "Ordenado por Narrativa: " << endl;
        conjAtividades.displayAtividades();

        conjAtividades.ordenaConjuntoSistema();
        cout << "Ordenado por Sistema: " << endl;
        conjAtividades.displayAtividades();
    }
    else if (choice == 1)
    {
        Atividades a = Atividades();
        Atividades b = Atividades();

        a + b;
        cout << "Junção das melhores coordenadas: " << endl;

        b.displayCoordenadas();
    }
    else
    {
        cout << "Escolha inválida" << endl;
        exit(1);
    }
}