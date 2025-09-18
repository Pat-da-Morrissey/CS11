#include <iostream>
#include <iomanip>
#include <string>
#include "Player.h"


Player::Player(){
  health = 100;
  rations = 100;
}
Player::Player(std::string initial_name){
  name = initial_name;
  health = 1000;
  rations = 100;
}

void Player::getStatus(){
  std::cout << "Your name is: " << name << std::endl;
  std::cout << "Health is: " << getHealth() << "%";                   // Status for Health
  if(health >= 70){
    std::cout << " ...good" << std::endl;
  }
  else if(health < 70 && health >= 50){
    std::cout << " ...thugging it out" << std::endl;
  }
  else if(health < 50){
    std::cout << " ...dying" << std::endl;
  }
  std::cout << "Rations are: " << getRations() << "lbs left";      // Status for Hunger
  if(rations >= 80){
    std::cout << " ...filling! Bro is full! :)" << std::endl;
  }
   else if(rations < 80 && rations >= 50){
    std::cout << " ...sufficent" << std::endl;
  }
  else if(rations < 50){
    std::cout << " ...poor, your starving!" << std::endl;
  }
}