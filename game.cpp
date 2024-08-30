#include"game.h"
using namespace std;

Game::Game()
{
    total_balls=6;
    player_perteam=4;
    total_player=11;
    firstinn=false;
    teamA.team_name="Team-A";
    teamB.team_name="Team-B";
    players[0]="MS Dhoni";
    players[1]="Virat";
    players[2]="Shikhar";
    players[3]="KL Rahul";
    players[4]="Rohit";
    players[5]="Harbhajan";
    players[6]="Jadeja";
    players[7]="Ashwin";
    players[8]="Hardik";
    players[9]="Bumrah";
    players[10]="Ishant";
}
void Game::welcome(void)
{
    cout<<"\n\n\t\t\t\t\t---------------------------------------\n";
    cout<<"\t\t\t\t\t|                                     |\n";
    cout<<"\t\t\t\t\t|          GULLY CRICKET              |\n";
    cout<<"\t\t\t\t\t|                                     |\n";
    cout<<"\t\t\t\t\t---------------------------------------\n";
}
void Game::showplayer(void)
{
    cout<<"\n\n\n\t\t\t\t\t---------------------------------------\n";
    cout<<"\t\t\t\t\t|         Pool of Players               |\n";
    cout<<"\t\t\t\t\t---------------------------------------\n";
    cout<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<"\t\t\t\t\t\t\t["<<i<<"]"<<players[i]<<endl;
    }

}
void Game::create(void)
{
    cout<<"\n\n\n\t\t\t\t\t---------------------------------------\n";
    cout<<"\t\t\t\t\t|       Create Team-A & Team-B        |\n";
    cout<<"\t\t\t\t\t---------------------------------------\n";
}
// string Game::operator==(string s)
// {
    
// }
void Game::getplayerA(int n)
{
    Player p(players[n]);
    teamA.add_player(p);
}
void Game::getplayerB(int m)
{
    Player P(players[m]);
    teamB.add_player(P);
}
void Game::show_player(void)
{
    cout<<"\n\t\t\t\t\t----------------------------\n";
    cout<<"\t\t\t\t\t|========= TEAM-A ========|\n";
    cout<<"\t\t\t\t\t----------------------------\n";
    teamA.show_playerA();
    cout<<"\t\t\t\t\t----------------------------\n";
    cout<<"\n\t\t\t\t\t----------------------------\n";
    cout<<"\t\t\t\t\t|========= TEAM-B ========|\n";
    cout<<"\t\t\t\t\t----------------------------\n";
    teamB.show_playerB();
    cout<<"\t\t\t\t\t----------------------------\n";
}
void Game::toss(void)
{
    int ch;
    cout<<"\t\t\t\t\t1.HEADS\n";
    cout<<"\t\t\t\t\t2.TAILS\n";
    cout<<"\t\t\t\t\tTEAM-A select the side of coin...";
    int side;
    cin>>side;
    cout<<"\n\t\t\t\t\tTossing the Coin...";
    usleep(5000000);
    srand(time(NULL));
    int toss=rand()%2+1;
    if(toss==side)
    {
        cout<<"\n\t\t\t\t\tTEAM-A won the toss.....";
        cout<<"\n\t\t\t\t\tEnter 1 to BAT or 2 to BOWL first : ";
        cin>>ch;
        if(ch==1)
        {
            batting=&teamA;
            bowling=&teamB;
            batsman=&teamA.player[0];
            bowler=&teamB.player[0];
            cout<<"\n\t\t\t\t\tTEAM-A won the toss and choose to bat first.";
        }
        else
        {
            batting=&teamB;
            bowling=&teamA;
            batsman=&teamB.player[0];
            bowler=&teamA.player[0];
            cout<<"\n\t\t\t\t\tTEAM-A won the toss and choose to bowl first.";
        }
    }
    else
    {
        cout<<"\n\t\t\t\t\tTEAM-B won the toss.....";
        cout<<"\n\t\t\t\t\tEnter 1 to BAT or 2 to BOWL first : ";
        cin>>ch;
        if(ch==1)
        {
            batting=&teamB;
            bowling=&teamA;
            batsman=&teamB.player[0];
            bowler=&teamA.player[0];
            cout<<"\n\t\t\t\t\tTEAM-B won the toss and choose to bat first.";
        }
        else
        {
            batting=&teamA;
            bowling=&teamB;
            batsman=&teamA.player[0];
            bowler=&teamB.player[0];
            cout<<"\n\t\t\t\t\tTEAM-B won the toss and choose to bowl first.";
        }
    }
}
int Game::runs(void)
{
    srand(time(NULL));
    int r;
    r=rand()%7;
    return r;
}
void Game::first_inn(void)
{
    int run;
    system("cls");
    cout<<"\n\n\t\t\t\t\t|||  First Inning Starts  |||";
    cout<<"\n\t\t\t\t\t"<<batting->show_name()<<" : "<<batsman->show()<<" is batting";
    cout<<"\n\t\t\t\t\t"<<bowling->show_name()<<" : "<<bowler->show()<<" is bowling";
    for(int i=0;i<6;i++)
    {
        cout<<"\n\t\t\t\t\tPress ENTER to bowl...";
        getch();
        cout<<"\n\t\t\t\t\tBowling...";
        usleep(5000000);
        run=runs();
        batsman->add_ballsplay();
        bowler->add_ballsbowl();
        batting->add_totballs();
        if(run==0||run==5)
        {
            cout<<"\n\n\t\t\t\t\t"<<bowler->show()<<" to "<<batsman->show()<<" "<<" OUT!";
            batting->add_totalwick();
            if(batting->show_totalwick()==4)
            {
                cout<<"\n\n\t\t\t\t\t------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t          "<<batting->show_name()<<"  "<<batting->show_runteam()<<"-"<<batting->show_totalwick()<<"   "<<"("<<i+1<<")  | "<<batsman->show()<<" "<<batsman->show_runbat()<<" "<<"("<<batsman->show_ballsp()<<")   "<<bowler->show()<<"  "<<i+1<<"-"<<bowler->show_runbowl()<<"-"<<bowler->show_wick();
                cout<<"\n\t\t\t\t\t------------------------------------------------------------------------";
                break;
            }
            bowler->add_wick();
            cout<<"\n\n\t\t\t\t\t------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t          "<<batting->show_name()<<"  "<<batting->show_runteam()<<"-"<<batting->show_totalwick()<<"   "<<"("<<i+1<<")  | "<<batsman->show()<<" "<<batsman->show_runbat()<<" "<<"("<<batsman->show_ballsp()<<")   "<<bowler->show()<<"  "<<i+1<<"-"<<bowler->show_runbowl()<<"-"<<bowler->show_wick();
            cout<<"\n\t\t\t\t\t------------------------------------------------------------------------";
            batsman++;
            cout<<"\n\t\t\t\t\tNew batsman is "<<batsman->show()<<"!";
            continue;
        }
        cout<<"\n\n\t\t\t\t\t"<<bowler->show()<<" to "<<batsman->show()<<" "<<run<<" runs!";
        batting->add_runteam(run);
        batsman->add_runbat(run);
        bowler->add_runbowl(run);
        cout<<"\n\n\t\t\t\t\t------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t          "<<batting->show_name()<<"  "<<batting->show_runteam()<<"-"<<batting->show_totalwick()<<"   "<<"("<<i+1<<")  | "<<batsman->show()<<" "<<batsman->show_runbat()<<" "<<"("<<batsman->show_ballsp()<<")   "<<bowler->show()<<"  "<<i+1<<"-"<<bowler->show_runbowl()<<"-"<<bowler->show_wick();
        cout<<"\n\t\t\t\t\t------------------------------------------------------------------------";
    }
    cout<<"\n\n\t\t\t\t\t                         |||  First Inning ENDS  |||";
    cout<<"\n\n\t\t\t\t\t"<<batting->show_name()<<"   "<<batting->show_runteam()<<" - "<<batting->show_totalwick()<<"  (6)";
    cout<<"\n\t\t\t\t\t"<<bowling->show_name()<<" needs "<<batting->show_runteam()+1<<" runs to win!!";
}
void Game::sec_inn(void)
{
    int run,t;                  //t to check which team is batting
    if(batting->show_name()=="Team-A")
    {
        t=0;
        batting=&teamB;
        bowling=&teamA;
        batsman=&teamB.player[0];
        bowler=&teamA.player[0];
    }
    else
    {
        t=1;
        batting=&teamA;
        bowling=&teamB;
        batsman=&teamA.player[0];
        bowler=&teamB.player[0];
    }
    cout<<"\n\n\t\t\t\t\t|||  Second Inning Starts  |||";
    cout<<"\n\t\t\t\t\t"<<batting->show_name()<<" : "<<batsman->show()<<" is batting";
    cout<<"\n\t\t\t\t\t"<<bowling->show_name()<<" : "<<bowler->show()<<" is bowling";
    for(int i=0;i<6;i++)
    {
        cout<<"\n\t\t\t\t\tPress ENTER to bowl...";
        getch();
        cout<<"\n\t\t\t\t\tBowling...";
        usleep(5000000);
        run=runs();
        batsman->add_ballsplay();
        bowler->add_ballsbowl();
        batting->add_totballs();
        if(run==0||run==5)
        {
            cout<<"\n\n\t\t\t\t\t"<<bowler->show()<<" to "<<batsman->show()<<" "<<" OUT!";
            batting->add_totalwick();
            if(batting->show_totalwick()==4)
            {
                cout<<"\n\n\t\t\t\t\t------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t          "<<batting->show_name()<<"  "<<batting->show_runteam()<<"-"<<batting->show_totalwick()<<"   "<<"("<<i+1<<")  | "<<batsman->show()<<" "<<batsman->show_runbat()<<" "<<"("<<batsman->show_ballsp()<<")   "<<bowler->show()<<"  "<<i+1<<"-"<<bowler->show_runbowl()<<"-"<<bowler->show_wick();
                cout<<"\n\t\t\t\t\t------------------------------------------------------------------------";
                break;
            }
            bowler->add_wick();
            cout<<"\n\n\t\t\t\t\t------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t          "<<batting->show_name()<<"  "<<batting->show_runteam()<<"-"<<batting->show_totalwick()<<"   "<<"("<<i+1<<")  | "<<batsman->show()<<" "<<batsman->show_runbat()<<" "<<"("<<batsman->show_ballsp()<<")   "<<bowler->show()<<"  "<<i+1<<"-"<<bowler->show_runbowl()<<"-"<<bowler->show_wick();
            cout<<"\n\t\t\t\t\t------------------------------------------------------------------------";
            batsman++;
            cout<<"\n\t\t\t\t\tNew batsman is "<<batsman->show()<<"!";
            continue;
        }
        cout<<"\n\n\t\t\t\t\t"<<bowler->show()<<" to "<<batsman->show()<<" "<<run<<" runs!";
        batting->add_runteam(run);
        batsman->add_runbat(run);
        bowler->add_runbowl(run);
        if(t==0)
        {
            if(batting->show_runteam()>teamA.total_runs)
            {
                cout<<"\n\n\t\t\t\t\t"<<batting->show_name()<<" won  the match!!!";
                break;
            }
        }
        if(t==1)
        {
            if(batting->show_runteam()>teamB.total_runs)
            {
                cout<<"\n\n\t\t\t\t\t"<<batting->show_name()<<" won  the match!!!";
                break;
            }
        }
        cout<<"\n\n\t\t\t\t\t------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t          "<<batting->show_name()<<"  "<<batting->show_runteam()<<"-"<<batting->show_totalwick()<<"   "<<"("<<i+1<<")  | "<<batsman->show()<<" "<<batsman->show_runbat()<<" "<<"("<<batsman->show_ballsp()<<")   "<<bowler->show()<<"  "<<i+1<<"-"<<bowler->show_runbowl()<<"-"<<bowler->show_wick();
        cout<<"\n\t\t\t\t\t------------------------------------------------------------------------";
    }
    if(t==0)
    {
        if(batting->show_runteam()<teamA.total_runs)
        {
            cout<<"\n\n\t\t\t\t\tTeam-A won the match!!!";
        }
        if(batting->show_runteam()==teamA.total_runs)
        {
            cout<<"\n\n\t\t\t\t\tMatch DRAWS!!!";
        }
    }
    if(t==1)
    {
        if(batting->show_runteam()<teamB.total_runs)
        {
            cout<<"\n\n\t\t\t\t\tTeam-B won  the match!!!";
        }
        if(batting->show_runteam()==teamB.total_runs)
        {
            cout<<"\n\n\t\t\t\t\tMatch DRAWS!!!";
        }
    }
    cout<<"\n\n\t\t\t\t\t                         |||  Match ENDS  |||";
}
void Game::show_resA(void)
{
    cout<<"\n\n\t\t\t\t\tTeam-A  "<<teamA.total_runs<<"-"<<teamA.total_wick<<" ("<<teamA.total_balls<<")";
    cout<<"\n\t\t\t\t\t=====================================";
    cout<<"\n\t\t\t\t\t|  PLAYER\tBATTING\t   BOWLING  |";
    for(int a=0;a<4;a++)
    {
        if(a==0)
        {
            cout<<"\n\t\t\t\t\t|["<<a<<"]"<<teamA.player[a].show()<<"\t"<<teamA.player[a].show_runbat()<<"("<<teamA.player[a].show_ballsp()<<")"<<"\t   "<<teamA.player[a].show_ballsbowl()<<"-"<<teamA.player[a].show_runbowl()<<"-"<<teamA.player[a].show_wick()<<"   |";
        }
        else
        {
            cout<<"\n\t\t\t\t\t|["<<a<<"]"<<teamA.player[a].show()<<"\t"<<teamA.player[a].show_runbat()<<"("<<teamA.player[a].show_ballsp()<<")"<<"\t   "<<teamA.player[a].show_ballsbowl()<<"-"<<teamA.player[a].show_runbowl()<<"-"<<teamA.player[a].show_wick()<<"    |";
        }
    }
    cout<<"\n\t\t\t\t\t=====================================";
}
void Game::show_resB(void)
{
    cout<<"\n\n\n\t\t\t\t\tTeam-B  "<<teamB.total_runs<<"-"<<teamB.total_wick<<" ("<<teamB.total_balls<<")";
    cout<<"\n\t\t\t\t\t=====================================";
    cout<<"\n\t\t\t\t\t|  PLAYER\tBATTING\t   BOWLING  |";
    for(int a=0;a<4;a++)
    {
        if(a==0)
        {
            cout<<"\n\t\t\t\t\t|["<<a<<"]"<<teamB.player[a].show()<<"\t"<<teamB.player[a].show_runbat()<<"("<<teamB.player[a].show_ballsp()<<")"<<"\t   "<<teamB.player[a].show_ballsbowl()<<"-"<<teamB.player[a].show_runbowl()<<"-"<<teamB.player[a].show_wick()<<"   |";
        }
        else
        {
            cout<<"\n\t\t\t\t\t|["<<a<<"]"<<teamB.player[a].show()<<"\t"<<teamB.player[a].show_runbat()<<"("<<teamB.player[a].show_ballsp()<<")"<<"\t   "<<teamB.player[a].show_ballsbowl()<<"-"<<teamB.player[a].show_runbowl()<<"-"<<teamB.player[a].show_wick()<<"    |";
        }
    }
    cout<<"\n\t\t\t\t\t=====================================";
}