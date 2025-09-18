#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {

 public:
  Player();
  Player(std::string name);
  ~Player() {}

  // Updates Player Status
  void newHealth(int damage) {health = health - damage;}
  void newRations(int new_rations) {rations = rations + new_rations;}

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