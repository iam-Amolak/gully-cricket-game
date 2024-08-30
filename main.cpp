#include"game.h"
using namespace std;

int check(int arr[],int,int);

int main()
{
    Game game;
    int n,m,c;
    int chosen[8];
    static int chose=0;
    game.welcome();
    cout<<endl<<"\t\t\t\t\tPress ENTER to Continue....";
    getch();
    game.showplayer();
    cout<<endl<<"\t\t\t\t\tPress ENTER to Continue....";
    getch();
    game.create();
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(j==0)
            {
                cout<<endl;
                cout<<"\t\t\t\t\tPlayer "<<i+1<<" of Team-A : ";
                cin>>n;
                if(i==1||i==2||i==3)
                {
                    c=check(chosen,chose,n);
                }
                if(c==0)
                {
                    cout<<"\t\t\t\t\tThis player is already chosen\n";
                    cout<<"\t\t\t\t\tPlayer "<<i+1<<" of Team-A : ";
                    cin>>n;
                    game.getplayerA(n);
                    chosen[chose]=n;
                    chose++;
                    continue;
                }
                if(n<0||n>10)
                {
                    cout<<"\t\t\t\t\tPlease select from given players\n";
                    cout<<"\t\t\t\t\tPlayer "<<i+1<<" of Team-A : ";
                    cin>>n;
                    c=check(chosen,chose,n);
                    if(c==0)
                    {
                        cout<<"\t\t\t\t\tThis player is already chosen\n";
                        cout<<"\t\t\t\t\tPlayer "<<i+1<<" of Team-A : ";
                        cin>>n;
                        game.getplayerA(n);
                        chosen[chose]=n;
                        chose++;
                        continue;
                    }
                    game.getplayerA(n);
                    chosen[chose]=n;
                    chose++;
                    continue;
                }
                game.getplayerA(n);
                chosen[chose]=n;
                chose++;
            }
            if(j==1)
            {
                cout<<"\t\t\t\t\tPlayer "<<i+1<<" of Team-B : ";
                cin>>m;
                c=check(chosen,chose,m);
                if(c==0)
                {
                    cout<<"\t\t\t\t\tThis player is already chosen\n";
                    cout<<"\t\t\t\t\tPlayer "<<i+1<<" of Team-B : ";
                    cin>>m;
                    game.getplayerB(m);
                    chosen[chose]=m;
                    chose++;
                    continue;
                }
                if(m<0||m>10)
                {
                    cout<<"\t\t\t\t\tPlease select from given players\n";
                    cout<<"\t\t\t\t\tPlayer "<<i+1<<" of Team-B : ";
                    cin>>m;
                    c=check(chosen,chose,m);
                    if(c==0)
                    {
                        cout<<"\t\t\t\t\tThis player is already chosen\n";
                        cout<<"\t\t\t\t\tPlayer "<<i+1<<" of Team-B : ";
                        cin>>m;
                        game.getplayerB(m);
                        chosen[chose]=m;
                        chose++;
                        continue;
                    }
                    game.getplayerB(m);
                    chosen[chose]=m;
                    chose++;
                    continue;
                }
                game.getplayerB(m);
                chosen[chose]=m;
                chose++;
            }
        }
    }
    game.show_player();
    cout<<endl<<"\t\t\t\t\tPress ENTER to Toss....\n";
    getch();
    game.toss();
    usleep(5000000);
    game.first_inn();
    game.sec_inn();
    game.show_resA();
    game.show_resB();
    getch();
    return 0;
}

int check(int arr[],int s,int n)
{
    for(int i=0;i<s+1;i++)
    {
        if(n==arr[i])
        {
            return 0;
        }
    }
}