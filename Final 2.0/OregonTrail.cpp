#include "OregonTrail.h"
#include "Player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>


OregonTrail::OregonTrail() {
  milesTraveled = 0;
  location = 0;
  totalDays = 0;
  startGame();
}

void OregonTrail::startGame() {
  int choice = mainMenuPrompt();
  
  if(choice == 2) {
    learnMorePrompt();
    choice = 1;
  }
  if(choice == 1) { // Starts the game
    namePrompt();
    departionPrompt();
    std::cout << "Alrighty lets begin your horrible journey! Enter anything to start" << std::endl;
    std::string start;
    std::cin >> start; 
 
    while(location != 8 && !isDead(P1.getHealth())) { // location 8 is Oregon City
      generateDate();
      journey();
      if(!isDead(P1.getHealth())) {
        location++;
        checkPointPrompt();
      }
    }
    if(!isDead(P1.getHealth())) {
      victoryPrompt();
    } else {
      return;
    }
  }  return; // if choice == 3
}

int OregonTrail::mainMenuPrompt() {
  std::cout << "Welcome to The Oregon Trail" << std::endl;
  std::cout << "---------====+====---------" << std::endl;
  std::cout << "You may:" << std::endl;
  std::cout << "1. Travel the trail" << std::endl;
  std::cout << "2. Learn about the trail" << std::endl;
  std::cout << "3. Quit" << std::endl;
  std::cout << "What is your choice?" << std::endl;
  std::cout << "---------====+====---------" << std::endl;
  int choice;
  std::cin >> choice;
  while(!std::cin.fail()) {
    if(std::cin.fail()) {
      std::string trash = " ";
      std::cin.clear();
      std::cin >> trash;
      std::cout << "Invaild input! Please Try Again" << std::endl;
      std::cin >> choice;
    }
    return choice;
  }
  return 3;
}

void OregonTrail::learnMorePrompt() {
  std::cout << "---------====+====---------" << std::endl;
  std::cout << "So it's 1848 and your life" << std::endl;
  std::cout << "is mid in the midwest. Get it... " << std::endl;
  std::cout << "You see what I did there lol!" << std::endl;
  std::cout << "So your going to move to Oregon " << std::endl; 
  std::cout << "Cause thats the place to be apparenlty" << std::endl; 
  std::cout << "and well planes don't exist yet" << std::endl;
  std::cout << "so good luck walking their! ;)" << std::endl;
  std::cout << std::endl;
  std::cout << "P.S. dont die of Dysentery" << std::endl;
  std::cout << "---------====+====---------" << std::endl;
  std::cout << std::endl << std::endl;
  std::cout << "Enter anything to continue" << std::endl;
  std::string moveOn;
  std::cin >> moveOn;
}

void OregonTrail::namePrompt() {
  std::cout << "---------====+====---------" << std::endl;
  std::cout << std::endl;
  std::cout << "What is the name of the" << std::endl;
  std::cout << "wagon leader?" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter your name:" << std::endl;
  std::cout << "---------====+====---------" << std::endl;
  std::string player1name;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, player1name);
  P1 = Player(player1name);
  if(player1name == "Albert Clarance II"){
        std::cout << "---------====+====---------" << std::endl;
        std::cout << "That is a great name!" << std::endl;
        std::cout << std::endl;
        std::cout << "Welcome Albert Claracne II to" << std::endl;
        std::cout << "Oregon Trail!" << std::endl;
        std::cout << std::endl;
        std::cout << "---------====+====---------" << std::endl;
      }
}

void OregonTrail::departionPrompt() {
  std::cout << "---------====+====---------" << std::endl;
  std::cout << "It is 1848. Your leaving your" << std::endl;
  std::cout << "boring home in Independance, Missouri" << std::endl;
  std::cout << "to go to Ohio. Like you live in" << std::endl;
  std::cout << "Missery no duh your leaving..." << std::endl;
  std::cout << "What month do you want to leave?" << std::endl;
  std::cout << std::endl;
  std::cout << "1. March" << std::endl;
  std::cout << "2. April" << std::endl;
  std::cout << "3. May" << std::endl;
  std::cout << "4. June" << std::endl;
  std::cout << "5. July" << std::endl;
  std::cout << "6. Ask for advice" << std::endl;
  std::cout << std::endl;
  std::cout << "---------====+====---------" << std::endl;
  int departureTime = -1;
  std::string departionMonths[5] = {"March", "April", "May", "June", "July"};
  while(departureTime == -1) {
    std::cin >> departureTime;
    if (departureTime < 6 && departureTime > 0) {
      monthIndex = departureTime + 1; // creates the offset for 
      std::cout << "You are leaving in " << departionMonths[departureTime - 1] << std::endl;
    } else {
      std::cout << "Invaild input! Please Try Again" << std::endl;
      departureTime = -1;
      if(std::cin.fail()) {             // is this necessary?
        std::string trash = " ";
        std::cin.clear();
        std::cin >> trash;
        departureTime = -1;
      }
    }
  }
}

void OregonTrail::checkPointPrompt() {
  int input = -1;
  while(input == -1) {
    std::cout << "---------====+====---------" << std::endl;
    std::cout << "       " << checkPoints[location] << std::endl;                    // to be fixed!
    std::cout << "       "<< date << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "You may:" << std::endl; 
    std::cout << "1. Check Your Stats" << std::endl;
    std::cout << "2. Find Food" << std::endl;
    std::cout << "3. Continue on the Trail" << std::endl;
    std::cout << "---------====+====---------" << std::endl;
    
    std::cin >> input;
    if(input == 1) {
      P1.getStatus();
      std::cout << "Enter anything to return" << std::endl;
      std::string anything;
      std::cin >> anything;
      input = -1;
    } else if(input == 2) {
      std::cout << "Looking for food..." << std::endl;
      int newFood = 0;
      std::string moveOn;
      int r = rand() % 10;
      if(r >= 1) {
        std::cout << "Lucky you, you found 10 rations of food!" << std::endl;
        newFood = 10;
        P1.newRations(newFood);
      } else if(r >=2 && r <= 7){
        std::cout << "You found nothing" << std::endl;
      } else if(r > 8) {
        std::cout << "You wasted 1 day finding nothing..." << std::endl;
        std::cout << "and you used up 10 rations in the process. Next time learn how to shoot properly!" << std::endl;
        newFood = -10;
        days++;
        generateDate();
        P1.newRations(newFood);         
      }
      std::cout << "Come on! Lets get a move on! Theirs still a long ways to go!" << std::endl;
      std::cout << "Enter anything to continue: ";
      std::cin >> moveOn;
    } else if(input == 3) {
      std::cout << "Come on! Lets get a move on! Theirs still a long ways to go!" << std::endl;
    } else {
      std::cout << "Invaild input! Please Try Again" << std::endl;
      input = -1;
      if(std::cin.fail()) {
        std::string trash = " ";
        std::cin.clear();
        std::cin >> trash;
      }
    }
  }
}

void OregonTrail::victoryPrompt() {
  std::cout << "---------====+====---------" << std::endl;
  std::cout << " Congrats you survived... " << std::endl;
  std::cout << " The Oregon Trail! " << std::endl;
  std::cout << " It was sure a challange" << std::endl;
  std::cout << " but you survived... somehow." << std::endl; 
  std::cout << " Hope you enjoyed the journey!" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "---------====+====---------" << std::endl;
}


int OregonTrail::accident() {
  int accidentChance = 100;
  int r = rand() % accidentChance;
  if(r < 50) { // 50% chance of being fine
    return 0;
  } else if (r >= 50 && r < 75) { // 25% chance of getting sick
    int diseaseDamage[3] = {20, 30, 25};
    std::string diseaseType[3] = {"Dystentary", "Smallpox", "Measels"};
    int diseaseChance = 15; // has a 20% chance of catching anything
    int r1 = rand() % diseaseChance;
    if(r1 < 3) {
      std::cout << P1.getName() << " has " << diseaseType[r1] << std::endl;
      return diseaseDamage[r1];
    } else {
      return 0;
    }
  } else {  // 25% chance of getting hurt
    int eventDamage[3] = {5, 1, 10};
    std::string eventType[3] = {"has a broken leg!", "got frost bite!", "got attacked by a bear!"};
    int eventChance = 9; // has a 33% chance of really getting hurt
    int r2 = rand() % eventChance;
    if(r2 < 3) { 
      std::cout << P1.getName() << " " << eventType[r2] << std::endl;
      return eventDamage[r2];
    } else {
      return 0;
    }
  }
}

void OregonTrail::gameOver(int health, std::string Player) {

  if(health <= 0) {
    std::cout << Player << " died! Game Over! You traveled " << milesTraveled << " miles thats a super low score" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "              __________________" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "            //                  \\\\" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "           || Here lies:         ||" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "           || " << Player <<" ||" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "           || Age: 31 i think idk||" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "           ||                    ||" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "           || Traveled: " << milesTraveled << "miles ||" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "           ||                    ||" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "           ||                    ||" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "           ||                    ||" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "___________||                    ||__________" << std::endl;


    std::ofstream fout;
    fout.open("GameOverStats.txt");
    fout << "              __________________" << std::endl;
    fout << "            //                  \\" << std::endl;
    fout << "           || Here lies:         ||" << std::endl;
    fout << "           || " << Player <<" ||" << std::endl;
    fout << "           || Age: 31 i think idk||" << std::endl;
    fout << "           ||                    ||" << std::endl;
    fout << "           || Traveled: " << milesTraveled << "miles ||" << std::endl;
    fout << "           ||                    ||" << std::endl;
    fout << "           ||                    ||" << std::endl;
    fout << "           ||                    ||" << std::endl;
    fout << "___________||                    ||__________" << std::endl;
  }
}

void OregonTrail::journey() {
  int displayTurns = 45;
  for(int start_checkpoint = 0; start_checkpoint < 11; ++start_checkpoint) {
    std::cout << "-----------------=====+=====-----------------" << std::endl;
    std::cout << std::setw(displayTurns) <<"        _____ " << std::endl;
    std::cout << std::setw(displayTurns) <<"@(==)~_(_____)" << std::endl;
    std::cout << std::setw(displayTurns) <<" ^  ^   *   * " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Weather: " << weatherForcast() << std::endl;
    std::cout << "Health: " << P1.getHealth() << std::endl;
    std::cout << "Food: " << P1.getRations() << std::endl;
    std::cout << "Next landmark:" << std::endl;
    std::cout << "Miles traveled: "<< milesTraveled << std::endl;
    P1.newHealth(accident());

    std::cout << "-----------------=====+=====-----------------" << std::endl;
    milesTraveled  += 25;
    displayTurns -= 3;
    days = days + 3;
    generateDate(); // updates date
    int rations = -2;
  
    P1.newRations(rations);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    if(isDead(P1.getHealth())){
      gameOver(P1.getHealth(), P1.getName());
      return;
    }
  }
  totalDays += days;
}