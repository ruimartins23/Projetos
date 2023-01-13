#ifndef InfoJogoBase_H_
#define InfoJogoBase_H_

#include <iostream>
#include <string>
#include <list>

namespace std
{

    class InfoJogoBase
    {
    protected:
        int sport;
        string teamA;
        string teamB;
        int scoreA;
        int scoreB;
        struct player
        {
            int number;
            string position;
        };

        list<player> startingA;
        list<player> startingB;
        list<player> benchA;
        list<player> benchB;
        list<player>::iterator playerIt;

    public:
        // functions
        InfoJogoBase();
        virtual ~InfoJogoBase();
        void printGameInfo();
        void displayPlayerInfo(player player);
        void displayPlayers();
        void loadPlayers();
        void displayGameScore();
        // getters
        int getSport() { return sport; };
        string getTeamA() { return teamA; };
        string getTeamB() { return teamB; };
        int getScoreA() { return scoreA; };
        int getScoreB() { return scoreB; };
        // setters
        void setSport(int a) { sport = a; };
        void setTeamA(string b) { teamA = b; };
        void setTeamB(string c) { teamB = c; };
        void setScoreA(int a) { scoreA = a; };
        void setScoreB(int b) { scoreB = b; };
    };

}

#endif