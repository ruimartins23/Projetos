#ifndef InfoJogoFutebol_H_
#define InfoJogoFutebol_H_

#include "infoJogoBase.h"

namespace std
{

    class InfoJogoFutebol : public std::InfoJogoBase
    {
    protected:
        struct sub
        {
            int in;
            int out;
            int time;
        };
        struct sentOff
        {
            int number;
            int time;
        };
        struct playerScore
        {
            string number; // tem de ser string para aceitar o #
            int time;
        };
        list<sub> subsA;
        list<sub> subsB;
        list<sub>::iterator subIt;
        list<sentOff> sentOffsA;
        list<sentOff> sentOffsB;
        list<sentOff>::iterator sentOffIt;
        list<playerScore> playerScores;
        list<playerScore>::iterator scoreIt;

    public:
        InfoJogoFutebol();
        virtual ~InfoJogoFutebol();
        void subsSentOffs();
        void displaySubsSentOffs();
        void displaySubInfo(sub sub);
        void displaySentOffInfo(sentOff sentOff);
        void setPlayersScore();
        void setTeamsScore();
        void displayPlayerScore(playerScore playerscore);
        void displayAllScores();
    };
}

#endif