#include"team.h"
using namespace std;

Team::Team()
{
    total_runs=0;
    total_wick=0;
    total_balls=0;
}
void Team::show_playerA(void)
{
    for(int i=0;i<4;i++)
    {
        cout<<"\t\t\t\t\t|\t["<<i<<"]"<<player.at(i).show()<<"\t   |"<<endl;
    }
}
void Team::show_playerB(void)
{
    for(int i=0;i<4;i++)
    {
        cout<<"\t\t\t\t\t|\t["<<i<<"]"<<player.at(i).show()<<"\t   |"<<endl;
    }
}
void Team::add_player(Player &p)
{
    player.push_back(p);
}
string Team::show_name(void)
{
    return team_name;
}
void Team::add_runteam(int r)
{
    total_runs+=r;
}
int Team::show_runteam(void)
{
    return total_runs;
}
int Team::show_totalwick(void)
{
    return total_wick;
}
void Team::add_totalwick(void)
{
    total_wick++;
}
void Team::add_totballs(void)
{
    total_balls++;
}
int Team::show_totballs(void)
{
    return total_balls;
}