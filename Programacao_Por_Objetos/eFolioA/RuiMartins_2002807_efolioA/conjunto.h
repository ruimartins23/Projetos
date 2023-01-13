#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <list>
#include <vector>
#include <algorithm>
#include "atividades.h"

namespace std
{
    class Conjunto
    {
    private:
        vector<Atividades> conjAtividades;
        vector<Atividades>::iterator it;
        int n;

    public:
        Conjunto(int n);
        Conjunto();
        virtual ~Conjunto();
        void displayAtividades();
        void ordenaConjuntoAgencia();
        void ordenaConjuntoSistema();
        void ordenaConjuntoNarrativa();
    };
};

#endif