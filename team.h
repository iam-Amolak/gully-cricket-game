#include"player.h"
#include<vector>

class Team:public Player
{
    public:
        std::string team_name;
        int total_runs;
        int total_wick;
        int total_balls;
        std::vector<Player> player;
        Team();
        void add_player(Player &);
        void show_playerA(void);
        void show_playerB(void);
        std::string show_name(void);
        void add_runteam(int);
        void add_totballs(void);
        void add_totalwick(void);
        int show_runteam(void);
        int show_totballs(void);
        int show_totalwick(void);
};