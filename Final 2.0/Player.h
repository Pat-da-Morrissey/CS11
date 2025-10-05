#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>

class Player {

 public:
  Player();
  Player(std::string name);
  ~Player() {}

  // Updates Player Status
  void newHealth(int damage) {
    if(health >= 100 && damage > 0) {
      return;
    }
    health += damage;
  }

  void newRations(int new_rations) {
    rations += new_rations;
    if(rations < 0) {
      rations = 0;
    }
    if(rations < 20) {
      newHealth(-5);
    }
  }

  // Returns the Status
  void getStatus();
  int getHealth() {return health;}
  int getRations() {return rations;}
  std::string getName() {return name;}

 private:
  std::string name;
  int health;
  int rations;
};

#endif
