#ifndef OREGONTRAIL_H
#define OREGONTRAIL_H
#include <string>
#include "Player.h"


class OregonTrail {
 public: 

  OregonTrail();
  ~OregonTrail() {}
  void startGame();

 private:

  Player P1;
  int mainMenuPrompt();
  void learnMorePrompt();
  void namePrompt();
  void departionPrompt();
  void checkPointPrompt();
  void journey();
  void gameOver(int health, std::string Player);
  void victoryPrompt();
  int accident();
  bool isDead(int health) {
    if(health <= 0) {
      return true;
    }
    return false;
  }

  int days = 1; 
  int totalDays; 
  int monthIndex;
  int year = 1848;
  int milesTraveled;
  int location;
 
  std::string weather[6] = {"Hot", "Warm", "Cool", "Cold", "Cloudy", "Raining"};
  std::string seasons[4] = {"Winter", "Spring", "Summer", "Fall"};
  std::string checkPoints[9] = {"Independance", "Fort Kearny", "Chimney Rock", "Fort Laramie", "Independance Rock", "Soda Srings", "Fort Bosie", "The Dales", "Oregon City"};
  std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  std::string date;
  std::string currWeather;

  bool winterStorm = false;
  bool summerDrought = false;
  bool rainStorm = false;

  void generateDate() {
    if(days > 28 && monthIndex == 1) { // February
      monthIndex++;
      days = 1;
    } else if(days > 30  && (monthIndex == 3 || monthIndex == 5 || monthIndex == 8 || monthIndex == 10)) { // Months w/ 30 days
      monthIndex++;
      days = 1;
    } else if (days > 31) { // Months with 31 Days
      if(monthIndex == 11) { // December
        monthIndex = 0;
        days = 1;
        year++; 
      } else { // Rest of the 31 day months
        monthIndex++;
        days = 1;
      }
    }
    date = months[monthIndex] + " " + std::to_string(days) + ", " + std::to_string(year); // should always update date everytime it's called
  }
  
  std::string weatherForcast() {
    std::string returnWeather;
    if(monthIndex == 11 || monthIndex == 0 || monthIndex == 1) { // Winter
      int i = rand() % 10;
      if(i == 1) {
        winterStorm = true;
      }
      if(winterStorm) { // in case there is a storm
        int j = rand() % 4;
        if(j == 1) {
          winterStorm = false;
        } else {
          return "Snow Storm!";
        }
      }
      if(!winterStorm) { // normal winter weather
        int r = rand() % 3;
        r += 3; // adjust the weather
        return weather[r];
      }
    } else if(monthIndex > 1 && monthIndex < 5) { // Spring
      int i = rand() % 10;
      if(i == 1) {
        rainStorm = true;
      }
      if(rainStorm) { // in case there is a storm
        int j = rand() % 5;
        if(j == 1) {
          rainStorm = false;
        } else {
          return "Rain Storm!";
        }
      }
      if(!rainStorm) {
        int r = rand() % 4;
        r += 1;
        return weather[r];
      }
    } else if(monthIndex > 4 && monthIndex < 8) { // Summer
      int i = rand() % 10;
      if(i == 1) {
        summerDrought = true;
      }
      if(summerDrought) {  // incase there is a drought
        int j = rand() % 2;
        if(j == 1) {
          summerDrought = false;
        } else {
          return "Heat Wave!";
        }
      }
      if(!summerDrought) { // normal summer weather
        int r = rand() % 3;
        return weather[r];
      }
    } else if( monthIndex > 7 && monthIndex < 11) { // Fall
      int r = rand() % 4;
      r += 1;
      return weather[r];
    }
    return weather[2];
  }

};

#endif