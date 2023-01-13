#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <list>

#include "infoJogoBasquetebol.h"

namespace std
{
    InfoJogoBasquetebol::InfoJogoBasquetebol()
    {
        setSport(1);
    }

    InfoJogoBasquetebol::~InfoJogoBasquetebol()
    {
        // DESTRUCTOR
    }

    void InfoJogoBasquetebol::setTimePlayed()
    {
        int totalPlayers;
        cout << "Quantos jogadores participaram no jogo? (min10)" << endl;
        cin >> totalPlayers;

        if (totalPlayers < 10)
        {
            cout << "O mínimo tem de ser 10 jogadores." << endl;
            setTimePlayed();
        }

        cout << "Insira o tempo de jogo do jogador do seguinte modo: 1:12:15 (jogador 1 jogou 12 min e 15 segundos)" << endl;
        cin.ignore();
        for (int i = 0; i < totalPlayers; i++)
        {
            string input = "";
            timePlayed timePlayed;

            getline(cin, input);
            char *token;

            token = strtok(const_cast<char *>(input.c_str()), ":");

            timePlayed.player = atoi(token);

            token = strtok(nullptr, ":");

            timePlayed.minutes = atoi(token);

            token = strtok(nullptr, ":");

            timePlayed.seconds = atoi(token);

            if (timePlayed.minutes > 60 || timePlayed.seconds > 60)
            {
                cout << "Tempo inválido." << endl;
                setTimePlayed();
            }

            lTimePlayed.push_back(timePlayed);
        }
    }

    void InfoJogoBasquetebol::displayPlayerTime(timePlayed timeplayed)
    {
        cout << "O jogador nº " << timeplayed.player << " jogou " << timeplayed.minutes << ":" << timeplayed.seconds << " minutos." << endl;
    }

    void InfoJogoBasquetebol::displayAllTimes()
    {
        for (timeIt = lTimePlayed.begin(); timeIt != lTimePlayed.end(); timeIt++)
            displayPlayerTime(*timeIt);
    }

    void InfoJogoBasquetebol::setPlayerScores()
    {
        int pointsTeams = getScoreA() + getScoreB(), pointsPlayers = 0, totalPlayers;

        cout << "Quantos jogadores marcaram pontos neste jogo?" << endl;
        cin >> totalPlayers;

        cout << "Insira os dados da seguinte forma: 1,45 (jog1 marcou 45 pontos)\nO total de pontos no jogo foi: " << pointsTeams << endl;
        cin.ignore();
        for (int i = 0; i < totalPlayers; i++)
        {
            string input;
            char *token;
            pointsScored pointsScored;

            getline(cin, input);

            token = strtok(const_cast<char *>(input.c_str()), ",");
            pointsScored.player = atoi(token);

            token = strtok(nullptr, ",");
            pointsScored.points = atoi(token);

            lPointsScored.push_back(pointsScored);

            pointsPlayers += pointsScored.points;
            ;
        }

        if (pointsPlayers != pointsTeams)
        {
            cout << "Os pontos que inseriu não equivalem aos pontos da equipa\nTente novamente" << endl;
            lPointsScored.clear();
            setPlayerScores();
        }
    }

    void InfoJogoBasquetebol::setTeamsScore()
    {
        int scoreA, scoreB;
        cout << "Digite o score de ambas as equipas. O JOGO NÃO PODE ACABAR EMPATADO!" << endl;
        do
        {
            cout << "Score da equipa A: " << endl;
            cin >> scoreA;
            cout << "Score da equipa B: " << endl;
            cin >> scoreB;

        } while (scoreA == scoreB);

        setScoreA(scoreA);
        setScoreB(scoreB);
    }

    void InfoJogoBasquetebol::displayPlayerScore(pointsScored pointsScored)
    {
        cout << "Jogador nº " << pointsScored.player << " marcou " << pointsScored.points << " pontos." << endl;
    }

    void InfoJogoBasquetebol::displayAllScores()
    {
        for (pointsIt = lPointsScored.begin(); pointsIt != lPointsScored.end(); pointsIt++)
            displayPlayerScore(*pointsIt);
    }

}