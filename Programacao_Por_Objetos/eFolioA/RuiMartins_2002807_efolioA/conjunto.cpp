#include "conjunto.h"

namespace std
{

    // construtor
    Conjunto::Conjunto(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            conjAtividades.push_back(Atividades());
    }

    // construtor vazio
    Conjunto::Conjunto()
    {
    }

    // destructor
    Conjunto::~Conjunto()
    {
    }

    // display ao conjunto de atividades
    void Conjunto::displayAtividades()
    {
        for (it = conjAtividades.begin(); it != conjAtividades.end(); it++)
            (*it).displayAtividade();
    }

    // ordena o conjunto de atividades por coordenadas de agencia
    void Conjunto::ordenaConjuntoAgencia()
    {
        sort(conjAtividades.begin(), conjAtividades.end(), [](const Atividades &lhs, const Atividades &rhs)
             { return lhs.coordAgencia > rhs.coordAgencia; });
    }

    // ordena o conjunto de atividades por coordenadas de sistema
    void Conjunto::ordenaConjuntoSistema()
    {
        sort(conjAtividades.begin(), conjAtividades.end(), [](const Atividades &lhs, const Atividades &rhs)
             { return lhs.coordSistema > rhs.coordSistema; });
    }

    // ordena o conjunto de atividades por coordenadas de narrativa
    void Conjunto::ordenaConjuntoNarrativa()
    {
        sort(conjAtividades.begin(), conjAtividades.end(), [](const Atividades &lhs, const Atividades &rhs)
             { return lhs.coordNarrativa > rhs.coordNarrativa; });
    }

}