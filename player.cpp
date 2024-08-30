#include"player.h"
using namespace std;

Player::Player()
{
    id=0;
    runs_score=0;
    balls_play=0;
    runs_given=0;
    balls_bowl=0;
    wicket=0;
}
Player::Player(string n)
{
    name=n;
    id=0;
    runs_score=0;
    balls_play=0;
    runs_given=0;
    balls_bowl=0;
    wicket=0;
}
string Player::show()
{
    return name;
}
void Player::add_runbat(int r)
{
    runs_score+=r;
}
void Player::add_runbowl(int r)
{
    runs_given+=r;
}
int Player::show_runbat(void)
{
    return runs_score;
}
int Player::show_runbowl(void)
{
    return runs_given;
}
int Player::show_wick(void)
{
    return wicket;
}
void Player::add_wick(void)
{
    wicket++;
}
void Player::add_ballsplay(void)
{
    balls_play++;
}
int Player::show_ballsp(void)
{
    return balls_play;
}
void Player::add_ballsbowl(void)
{
    balls_bowl++;
}
int Player::show_ballsbowl(void)
{
    return balls_bowl;
}