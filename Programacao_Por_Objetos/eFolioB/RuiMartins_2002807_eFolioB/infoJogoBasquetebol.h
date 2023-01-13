#include "infoJogoBase.h"

namespace std
{

    class InfoJogoBasquetebol : public std::InfoJogoBase
    {
    protected:
        struct timePlayed
        {
            int player;
            int minutes;
            int seconds;
        };

        struct pointsScored
        {
            int player;
            int points;
        };

        list<timePlayed> lTimePlayed;
        list<timePlayed>::iterator timeIt;

        list<pointsScored> lPointsScored;
        list<pointsScored>::iterator pointsIt;

    public:
        InfoJogoBasquetebol();
        virtual ~InfoJogoBasquetebol();
        void setTimePlayed();
        void displayPlayerTime(timePlayed timeplayed);
        void displayAllTimes();
        void setPlayerScores();
        void setTeamsScore();
        void displayPlayerScore(pointsScored pointsScored);
        void displayAllScores();
    };
}
