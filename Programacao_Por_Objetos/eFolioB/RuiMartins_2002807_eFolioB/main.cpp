#include "infoJogoFutebol.h"
#include "infoJogoBasquetebol.h"

#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int choice;
    cout << "XXXXXXXXXX BEM VINDO AO PROGRAMA DE GESTÃO DE JOGOS DE BASQUETEBOL OU FUTEBOL XXXXXXXXXX" << endl;
    cout << "XXXXXXXXXX DESEJA INSERIR INFORMAÇÕES SOBRE FUTEBOL(0) OU BASQUETEBOL(1) XXXXXXXXXXXXXXX?" << endl;
    cin >> choice;

    if (choice == 0)
    {
        InfoJogoFutebol jogo;
        jogo.loadPlayers();
        jogo.displayPlayers();
        jogo.subsSentOffs();
        jogo.setTeamsScore();
        jogo.setPlayersScore();
        jogo.displayGameScore();
        jogo.displaySubsSentOffs();
        jogo.displayAllScores();
    }
    else if (choice == 1)
    {
        InfoJogoBasquetebol jogo;
        jogo.loadPlayers();
        jogo.displayPlayers();
        jogo.setTeamsScore();
        jogo.setPlayerScores();
        jogo.setTimePlayed();
        jogo.displayGameScore();
        jogo.displayAllTimes();
        jogo.displayAllScores();
    }
    else
    {
        cout << "Input inválido. Tente de novo" << endl;
        main();
    }
}
