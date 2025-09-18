#include <iostream>
#include <iomanip>
#include "Player.h"

using namespace std;

//Player Functions
Player::Player(){
  health = 100;
  sickness = 0;
  rations = 100;
}
Player::Player(string initial_name){
  name = initial_name;
  health = 100;
  sickness = 0;
  rations = 100;
}
//Get Functions
void Player::status_health(int damage){
  health = health - damage;
}
void Player::status_rations(int new_rations){
  rations = rations + new_rations;
}

void Player::get_status(){
  cout << "Your name is " << name << endl;
  cout << "Health is: ";                   // Status for Health
  if(health >= 70){
    cout << "healthy" << endl;
  }
  else if(health < 70 && health >= 50){
    cout << "Health is ight" << endl;
  }
  else if(health < 50){
    cout << "Dying" << endl;
  }
  cout << "Your player rations are ";      // Status for Hunger
  if(rations >= 80){
    cout << "good. Bro is full :)" << endl;
  }
   else if(rations < 80 && rations >= 50){
    cout << "sufficent" << endl;
  }
  else if(rations < 50){
    cout << "mid rn. Bro Albert is like starving!" << endl;
  }
}
int Player::get_health(){
  return health;
}
int Player::get_hunger(){
  return rations; 
}
string Player::get_name(){
  return name; 
}