#include<string>
#include<iostream>

class Player
{
    public:
        std::string name;
        int id;
        int runs_score;
        int balls_play;
        int balls_bowl;
        int runs_given;
        int wicket;
        Player();
        Player(std::string);
        std::string show();
        void add_runbat(int);
        void add_runbowl(int);
        void add_wick(void);
        void add_ballsplay(void);
        void add_ballsbowl(void);
        int show_runbat(void);
        int show_runbowl(void);
        int show_wick(void);
        int show_ballsp(void);
        int show_ballsbowl(void);
};