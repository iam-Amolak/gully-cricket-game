#include"team.h"
#include<unistd.h>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#include<cstring>
#include<random>

class Game:public Team
{
    public:
        std::string players[11];
        int total_balls;
        Team teamA;
        Team teamB;
        bool firstinn;
        int player_perteam;
        int total_player;
        Team *batting;
        Team *bowling;
        Player *batsman;
        Player *bowler;
        Game();
        void welcome(void);
        void showplayer(void);
        void create(void);
        void getplayerA(int);
        void getplayerB(int);
        void show_player(void);
        void toss(void);
        int runs(void);
        void first_inn(void);
        void sec_inn(void);
        void show_resA(void);
        void show_resB(void);
};