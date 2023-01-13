#include "infoJogoFutebol.h"

#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <list>

namespace std
{
    InfoJogoFutebol::InfoJogoFutebol()
    {
        setSport(0);
    }

    InfoJogoFutebol::~InfoJogoFutebol()
    {
        // DESTRUCTOR
    }

    void InfoJogoFutebol::subsSentOffs()
    {
        int n;
        cout << "Digite o número de substituições e expulsões totais que deseja inserir no jogo: " << endl;
        cin >> n;
        cout << "Insira substituições do seguinte modo: 1 30 45 (in, out, tempo)\nOu expulsões do seguinte modo 10 # 45(expulso, tempo)" << endl;
        for (int i = 0; i < n; i++)
        {

            string input, subOrSentOff, subSentTest;

            cin.ignore();
            getline(cin, input);

            char *token;

            token = strtok(const_cast<char *>(input.c_str()), " ");

            subOrSentOff = token;

            token = strtok(nullptr, " ");

            subSentTest = token;

            if (subSentTest.rfind("#", 0) == 0)
            {
                cout << "EXPULSÃO: " << endl;
                int choice;
                cout << "Expulsão na equipa A(0) ou B(1)?" << endl;
                cin >> choice;

                token = strtok(nullptr, " ");
                string time = token;
                sentOff sentOff;
                sentOff.number = atoi(const_cast<char *>(subOrSentOff.c_str()));
                sentOff.time = atoi(const_cast<char *>(time.c_str()));

                if (choice == 0)
                {
                    sentOffsA.push_back(sentOff);
                }
                else if (choice == 1)
                {
                    sentOffsB.push_back(sentOff);
                }
            }
            else
            {
                cout << "SUBSTITUIÇÃO: " << endl;
                int choice;
                cout << "Sub na equipa A(0) ou B(1)?" << endl;
                cin >> choice;

                sub sub;
                sub.in = atoi(const_cast<char *>(subOrSentOff.c_str()));
                sub.out = atoi(const_cast<char *>(subSentTest.c_str()));
                token = strtok(nullptr, " ");
                string time = token;
                sub.time = atoi(const_cast<char *>(time.c_str()));

                if (choice == 0)
                {
                    subsA.push_back(sub);
                }
                else if (choice == 1)
                {
                    subsB.push_back(sub);
                }
            }
        }
    }

    void InfoJogoFutebol::displaySubsSentOffs()
    {
        cout << "Subs Equipa A: " << endl;
        for (subIt = subsA.begin(); subIt != subsA.end(); subIt++)
            displaySubInfo(*subIt);

        cout << "Subs Equipa B: " << endl;
        for (subIt = subsB.begin(); subIt != subsB.end(); subIt++)
            displaySubInfo(*subIt);

        cout << "Expulsões equipa A: " << endl;
        for (sentOffIt = sentOffsA.begin(); sentOffIt != sentOffsA.end(); sentOffIt++)
            displaySentOffInfo(*sentOffIt);

        cout << "Expulsões equipa B: " << endl;
        for (sentOffIt = sentOffsB.begin(); sentOffIt != sentOffsB.end(); sentOffIt++)
            displaySentOffInfo(*sentOffIt);
    }

    void InfoJogoFutebol::displaySubInfo(sub sub)
    {
        cout << "Entrou o jogador nº " << sub.in << " , saiu o jogador nº " << sub.out << " ao minuto " << sub.time << endl;
    }

    void InfoJogoFutebol::displaySentOffInfo(sentOff sentOff)
    {
        cout << "Jogador nº " << sentOff.number << " expulso ao minuto " << sentOff.time << endl;
    }

    void InfoJogoFutebol::setPlayersScore()
    {
        string input;
        int total = getScoreA() + getScoreB();

        cout << "Insira golos da seguinte maneira: 30 40(jog30 marcou aos 40 min) ou # 40(autogolo aos 40 min)" << endl;
        cin.ignore();

        for (int i = 0; i < total; i++)
        {
            playerScore score;

            getline(cin, input);

            char *token;

            token = strtok(const_cast<char *>(input.c_str()), " ");

            score.number = token;

            token = strtok(nullptr, " ");

            score.time = atoi(token);

            playerScores.push_back(score);
        }
    }

    void InfoJogoFutebol::setTeamsScore()
    {
        int a, b;
        cout << "Qual o score da equipa A?" << endl;
        cin >> a;
        setScoreA(a);
        cout << "Qual o score da equipa B?" << endl;
        cin >> b;
        setScoreB(b);
    }

    void InfoJogoFutebol::displayPlayerScore(playerScore playerscore)
    {
        if (playerscore.number.rfind("#", 0) == 0)
        {
            cout << "Autogolo ao minuto " << playerscore.time << endl;
        }
        else
        {
            cout << "Jogador nº " << playerscore.number << " marcou ao minuto " << playerscore.time << endl;
        }
    }

    void InfoJogoFutebol::displayAllScores()
    {
        for (scoreIt = playerScores.begin(); scoreIt != playerScores.end(); scoreIt++)
            displayPlayerScore(*scoreIt);
    }

}