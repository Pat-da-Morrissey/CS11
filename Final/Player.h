#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

using namespace std;

class Player{

  public:
    Player();
    Player(string name);

  //Player Status Variables
    void status_health(int damage);
    void status_rations(int new_rations);
    void current_name(string initial_name);

  //Gathers the Status
    int get_health();
    int get_hunger();
    void get_status();
    string get_name();

  private:
    string name;
    int health;
    int sickness;
    int rations;
};

#endif