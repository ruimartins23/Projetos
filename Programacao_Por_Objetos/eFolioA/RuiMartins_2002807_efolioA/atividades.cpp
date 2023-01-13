#include "atividades.h"

namespace std
{
    // construtor
    Atividades::Atividades()
    {
        cout << "Introduza o titulo:" << endl;
        cin.ignore();
        getline(cin, titulo);
        cout << "Introduza a descricao:" << endl;
        getline(cin, descricao);
        cout << "Introduza o URL:" << endl;
        cin >> URL;
        cout << "Introduza as coordenadas do Sistema: (entre 0 e 1)" << endl;
        cin >> coordSistema;
        cout << "Introduza as coordenadas da Narrativa: (entre 0 e 1)" << endl;
        cin >> coordNarrativa;
        cout << "Introduza as coordenadas da Agencia: (entre 0 e 1)" << endl;
        cin >> coordAgencia;

        // Checkar se o URL é valido
        if (URL.rfind("http://", 0) != 0 && URL.rfind("https://", 0) != 0)
        {
            cout << "URL Inválido\n";
            exit(1);
        }

        // Checkar se as coordenadas são validas
        if (coordAgencia < 0 || coordAgencia > 1 || coordSistema < 0 || coordSistema > 1 || coordNarrativa < 0 || coordNarrativa > 1)
        {
            cout << "Valor das coordenadas tem de ser entre 0 e 1\n";
            exit(1);
        }
    }

    // construtor vazio
    Atividades::Atividades(int op)
    {
    }

    Atividades::~Atividades()
    {
        // DESTRUCTOR
    }

    // apresenta todas as atividades
    void Atividades::displayAtividade()
    {
        cout << "Titutlo: " << titulo << endl;
        cout << "Descricao: " << descricao << endl;
        cout << "URL: " << URL << endl;
        cout << "Coord Sistema: " << coordSistema << endl;
        cout << "Coord Narrativa: " << coordNarrativa << endl;
        cout << "Coord Agencia: " << coordAgencia << endl;
        cout << "\n\n"
             << endl;
    }

    // da display apenas ás coordenadas da atividade
    void Atividades::displayCoordenadas()
    {
        cout << "Coordenadas Sistema: " << coordSistema << endl;
        cout << "Coordenadas Narrativa: " << coordNarrativa << endl;
        cout << "Coordenadas Agencia: " << coordAgencia << endl;
    }

}
