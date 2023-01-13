#ifndef ATIVIDADES_H_
#define ATIVIDADES_H_

#include <iostream>
#include <string>

namespace std
{

    class Atividades
    {
        friend class Conjunto;

    private:
        string titulo;
        string descricao;
        string URL;
        float coordSistema;
        float coordNarrativa;
        float coordAgencia;

    public:
        Atividades();
        Atividades(int);
        virtual ~Atividades();
        void displayAtividade();
        void displayCoordenadas();

        // getters
        string getTitulo() { return titulo; };
        string getDescricao() { return descricao; };
        string getUrl() { return URL; };
        float getCordSistema() { return coordSistema; };
        float getCordNarrativa() { return coordNarrativa; };
        float getCordAgencia() { return coordAgencia; };

        // setters
        void setTitulo(string m) { titulo = m; };
        void setDescricao(string m) { descricao = m; };
        void setUrl(string m) { URL = m; };
        void setCoordSistema(float m) { coordSistema = m; };
        void setCoordNarrativa(float m) { coordNarrativa = m; };
        void setCoordAgencia(float m) { coordAgencia = m; };

        // overload
        Atividades operator+(Atividades &a)
        {
            if (coordSistema > a.coordSistema)
                a.coordSistema = coordSistema;

            if (coordNarrativa > a.coordNarrativa)
                a.coordNarrativa = coordNarrativa;

            if (coordAgencia > a.coordAgencia)
                a.coordAgencia = coordAgencia;

            return a;
        }
    };
};

#endif