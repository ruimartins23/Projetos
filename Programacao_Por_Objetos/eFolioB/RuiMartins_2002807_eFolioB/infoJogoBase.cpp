#include "infoJogoBase.h"

#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <list>

namespace std
{
    InfoJogoBase::InfoJogoBase()
    {
        string teamA_, teamB_;

        cout << "Qual o nome da equipa A?" << endl;
        cin.ignore();
        getline(cin, teamA_);
        cout << "Qual o nome da equipa B?" << endl;
        getline(cin, teamB_);

        setTeamA(teamA_);
        setTeamB(teamB_);
    }

    InfoJogoBase::~InfoJogoBase()
    {
        // DESTRUCTOR
    }

    void InfoJogoBase::displayGameScore()
    {
        cout << "O resultado final foi de: " << scoreA << ":" << scoreB << endl;
    }

    void InfoJogoBase::printGameInfo()
    {
        if (sport == 0)
            cout << "Desporto: Futebol" << endl;

        if (sport == 1)
            cout << "Desporto: Basquetebol" << endl;

        cout << "Nome da equipa A: " << teamA << endl;
        cout << "Nome da equipa B: " << teamB << endl;
    }

    void InfoJogoBase::displayPlayerInfo(player player)
    {
        cout << "Número: " << player.number << "  "
             << "Posição: " << player.position << endl;
    }

    void InfoJogoBase::displayPlayers()
    {
        cout << "Titulares equipa A: " << endl;
        for (playerIt = startingA.begin(); playerIt != startingA.end(); playerIt++)
            displayPlayerInfo(*playerIt);

        cout << "Suplentes equipa A: " << endl;
        for (playerIt = benchA.begin(); playerIt != benchA.end(); playerIt++)
            displayPlayerInfo(*playerIt);

        cout << "Titulares equipa B: " << endl;
        for (playerIt = startingB.begin(); playerIt != startingB.end(); playerIt++)
            displayPlayerInfo(*playerIt);

        cout << "Suplentes equipa B: " << endl;
        for (playerIt = benchB.begin(); playerIt != benchB.end(); playerIt++)
            displayPlayerInfo(*playerIt);
    }

    void InfoJogoBase::loadPlayers()
    {
        string text;
        string aTeamName = this->teamA + ".txt", bTeamName = this->teamB + ".txt";

        // transformar string de nome da equipa em lowercase
        transform(aTeamName.begin(), aTeamName.end(), aTeamName.begin(), [](unsigned char c)
                  { return tolower(c); });

        transform(bTeamName.begin(), bTeamName.end(), bTeamName.begin(), [](unsigned char d)
                  { return tolower(d); });

        ifstream file;
        file.open(aTeamName);

        if (!file.is_open())
        {
            cout << "Não foi possivel abrir o ficheiro. Tente de novo" << endl;
            loadPlayers();
        }

        if (sport == 0)
        {
            for (int i = 0; i < 11; i++)
            {
                player player;
                getline(file, text);
                // dividir a linha do ficheiro em 2 tokens
                char *token;
                token = strtok(const_cast<char *>(text.c_str()), " ");
                player.number = atoi(token);

                token = strtok(nullptr, " ");
                player.position = token;

                startingA.push_back(player);
            }

            while (getline(file, text))
            {
                player player;
                // dividir a linha do ficheiro em 2 tokens
                char *token;
                token = strtok(const_cast<char *>(text.c_str()), " ");
                player.number = atoi(token);

                token = strtok(nullptr, " ");
                player.position = token;

                benchA.push_back(player);
            }

            file.close();

            file.open(bTeamName);

            if (!file.is_open())
            {
                cout << "Não foi possivel abrir o ficheiro. Tente de novo" << endl;
                loadPlayers();
            }

            for (int i = 0; i < 11; i++)
            {
                player player;
                getline(file, text);
                // dividir a linha do ficheiro em 2 tokens
                char *token;
                token = strtok(const_cast<char *>(text.c_str()), " ");
                player.number = atoi(token);

                token = strtok(nullptr, " ");
                player.position = token;

                startingB.push_back(player);
            }

            while (getline(file, text))
            {
                player player;
                // dividir a linha do ficheiro em 2 tokens
                char *token;
                token = strtok(const_cast<char *>(text.c_str()), " ");
                player.number = atoi(token);

                token = strtok(nullptr, " ");
                player.position = token;

                benchB.push_back(player);
            }

            file.close();
        }
        else if (sport == 1)
        {
            for (int i = 0; i < 5; i++)
            {
                player player;
                getline(file, text);
                // dividir a linha do ficheiro em 2 tokens
                char *token;
                token = strtok(const_cast<char *>(text.c_str()), " ");
                player.number = atoi(token);

                token = strtok(nullptr, " ");
                player.position = token;

                startingA.push_back(player);
            }

            while (getline(file, text))
            {
                player player;
                // dividir a linha do ficheiro em 2 tokens
                char *token;
                token = strtok(const_cast<char *>(text.c_str()), " ");
                player.number = atoi(token);

                token = strtok(nullptr, " ");
                player.position = token;

                benchA.push_back(player);
            }

            file.close();

            file.open(bTeamName);

            if (!file.is_open())
            {
                cout << "Não foi possivel abrir o ficheiro. Tente de novo" << endl;
                loadPlayers();
            }

            for (int i = 0; i < 5; i++)
            {
                player player;
                getline(file, text);
                // dividir a linha do ficheiro em 2 tokens
                char *token;
                token = strtok(const_cast<char *>(text.c_str()), " ");
                player.number = atoi(token);

                token = strtok(nullptr, " ");
                player.position = token;

                startingB.push_back(player);
            }

            while (getline(file, text))
            {
                player player;
                // dividir a linha do ficheiro em 2 tokens
                char *token;
                token = strtok(const_cast<char *>(text.c_str()), " ");
                player.number = atoi(token);

                token = strtok(nullptr, " ");
                player.position = token;

                benchB.push_back(player);
            }

            file.close();
        }
    }
}
