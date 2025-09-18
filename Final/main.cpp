#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>
#include "Player.h"
#include <fstream>

using namespace std;

void main_menu(){
  cout << "Welcome to The Oregon Trail" << endl;
  cout << "---------====+====---------" << endl;
  cout << "You may:" << endl;
  cout << "1. Travel the trail" << endl;
  cout << "2. Learn about the trail" << endl;
  cout << "3. Quit" << endl;
  cout << "What is your choice?" << endl;
  cout << "---------====+====---------" << endl;
}

void departion(){
  cout << "---------====+====---------" << endl;
  cout << "It is like 1848 and your leaving" << endl;
  cout << "your boring home in Missour, like who lives their like no duh your leaving..." << endl;
  cout << "What month do you want to leave?" << endl;
  cout << endl;
  cout << "1. March" << endl;
  cout << "2. April" << endl;
  cout << "3. May" << endl;
  cout << "4. June" << endl;
  cout << "5. July" << endl;
  cout << "6. Ask for help" << endl;
  cout << endl;
  cout << "---------====+====---------" << endl; 
}

void firstcheckpoint(){
  cout << "---------====+====---------" << endl;
  cout << "        Kansas City" << endl;
  cout << "        Jan 1, 1849" << endl;
  cout << "---------------------------" << endl;
  cout << "You may:" << endl; 
  cout << "1. Check Your Stats" << endl;
  cout << "2. Find Food" << endl;
  cout << "3. Continue on the Trail" << endl;
  cout << "---------====+====---------" << endl;
}
void secondcheckpoint(){
  cout << "---------====+====---------" << endl;
  cout << "        Fort Kearny" << endl;
  cout << "        Feb 1, 1849" << endl;
  cout << "---------------------------" << endl;
  cout << "You may:" << endl; 
  cout << "1. Check Your Stats" << endl;
  cout << "2. Find Food" << endl;
  cout << "3. Continue on the Trail" << endl;
  cout << "---------====+====---------" << endl;
}

void finish(){
  cout << "---------====+====---------" << endl;
  cout << " Congrats you made it to..." << endl;
  cout << " idk you made it somewhere " << endl;
  cout << " the game is not finished yet" << endl;
  cout << " but you survived somehow" << endl; 
  cout << " so hope you enjoyed the game" << endl;
  cout << endl;
  cout << endl;
  cout << "---------====+====---------" << endl;
}
int disease(){
  int diseases[4] = {20, 30, 25, 0};
  string disease_type[3] = {"dystentary", "smallpox", "measels"};
  int turns = 15;                                                             //Set Difficulty
  int r;
  //r = rand() % (size + (turns - distance)); // if i want to create difficulty in diseases
  r = rand() % turns;
  
  if(r < 3){
    cout << "You got " << disease_type[r] << endl;
    return diseases[r];
  }
  else{
    return diseases[3];
  }
}

int event(){
  int events[4] = {5, 1, 10, 0};
  string event_type[3] = {"broken Leg", "gotten frost bite!", "got attacked by a bear"};
  int turns = 20;
  int r;
  r = rand() % turns;
  
  if(r < 3){
    cout << "You have " <<event_type[r] << endl;
    return events[r];
  }
  else{
    return events[3];
  }
}

bool dead(int health, int miles, string Player){

  if(health <= 0){
    cout << "Bro Albert died! Game Over! You traveled " << miles << " miles thats a super low score" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "              __________________" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "            //                  \\" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "           || Here lies:         ||" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "           || " << Player <<" ||" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "           || Age: 31 i think idk||" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "           ||                    ||" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "           || Traveled: " << miles << "miles ||" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "           ||                    ||" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "           ||                    ||" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "           ||                    ||" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "___________||                    ||__________" << endl;


    ofstream fout;
    fout.open("GameOverStats.txt");
    fout << "              __________________" << endl;
    fout << "            //                  \\" << endl;
    fout << "           || Here lies:         ||" << endl;
    fout << "           || " << Player <<" ||" << endl;
    fout << "           || Age: 31 i think idk||" << endl;
    fout << "           ||                    ||" << endl;
    fout << "           || Traveled: " << miles << "miles ||" << endl;
    fout << "           ||                    ||" << endl;
    fout << "           ||                    ||" << endl;
    fout << "           ||                    ||" << endl;
    fout << "___________||                    ||__________" << endl;



    return true;
  }
  return false;
}

int main(){
  srand(time(0));
  //Start
  main_menu();
  int choice;
  
  while(!cin.fail()){
    cin >> choice;
    if(cin.fail()){
      string trash = " ";
      cin.clear();
      cin >> trash;
      cout << "Invaild input! Please Try Again" << endl;
    }

    if(choice == 1){ //Starts the game

      cout << "---------====+====---------" << endl;
      cout << endl;
      cout << "What is the name of the" << endl;
      cout << "wagon leader?" << endl;
      cout << endl;
      cout << "Enter your name:" << endl;
      cout << "---------====+====---------" << endl;

      string player1name;
      cin.ignore(256, '\n');
      getline(cin, player1name);
      
      if(player1name == "Albert Clarance II"){
        cout << "---------====+====---------" << endl;
        cout << "That is a great name!" << endl;
        cout << endl;
        cout << "Welcome Albert Claracne II to" << endl;
        cout << "Oregon Trail!" << endl;
        cout << endl;
        cout << "---------====+====---------" << endl;
        Player P1(player1name);
      }
      else{
        cout << "---------====+====---------" << endl;
        cout << "That name sucks" << endl;
        cout << "Your name is now: Albert Clarance II" << endl;
        cout << "It's historically accurate or something idk" << endl;
        cout << endl;
        cout << "Welcome Albert Clarance II!" << endl;
        cout << "---------====+====---------" << endl;
      
        player1name = "Albert Clarance II";
        Player P1(player1name);

        this_thread::sleep_for(chrono::milliseconds(4000));

        departion();
        int departure_time = -1;
        while(departure_time = -1){
          cin >> departure_time;
          if (departure_time < 6 && departure_time > 0){
            cout << "Starting in December perfect!" << endl;
            break;
          }
          if(departure_time == 6){
            cout << "Starting ealier in the year is best as you will travel mainly through warmer weather" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            cout << "Enter anything to return" << endl;
            string exit_advice = "";
            cin >> exit_advice; 
            departion();
            departure_time = -1;
          }
          if(departure_time != -1){
            cout << "Invaild input! Please Try Again" << endl;
            departure_time = -1;
            if(cin.fail()){
              string trash = " ";
              cin.clear();
              cin >> trash;
              departure_time = -1;
            }
          }
        }

        cout << "Alrighty lets begin your horrible journey! Enter anything to start" << endl;
        string start = "";
        cin >> start; 

        int miles = 0;
        int days = 1;
        int display_turns = 45;
        for(int start_checkpoint = 0; start_checkpoint < 11; ++start_checkpoint){

          cout << "-----------------=====+=====-----------------" << endl;
          cout << setw(display_turns) <<"        _____ " << endl;
          cout << setw(display_turns) <<"@(==)~_(_____)" << endl;
          cout << setw(display_turns) <<" ^  ^   *   * " << endl;
          cout << "---------------------------------------------" << endl;
          cout << "Date: December " << days << " 1848" << endl;
          cout << "Weather: Freezing cause you decided to leave in December!" << endl;
          cout << "Health: " << P1.get_health() << endl;
          cout << "Food: " << P1.get_hunger() << endl;
          cout << "Miles: "<< miles << endl;
          P1.status_health(disease());
          P1.status_health(event());

          cout << "-----------------=====+=====-----------------" << endl;
          miles += 25;
          display_turns -= 3;
          days = days + 3;
          int rations = -1;
          P1.status_rations(rations);
          this_thread::sleep_for(chrono::milliseconds(1000));
          if(dead(P1.get_health(), miles, P1.get_name()) == 1){
            return 0;
          }
        }
        int total_day = 0;
        total_day = total_day + days;
        days = 1;

        firstcheckpoint();
        int checkpoint1 = -1;
        while(checkpoint1 == -1){
          cin >> checkpoint1;
          if(checkpoint1 == 1){
            P1.get_status();
            cout << "Enter anything to return" << endl;
            string anything;
            cin >> anything;
            firstcheckpoint();
            checkpoint1 = -1;
          }
          if(checkpoint1 == 2){
            cout << "Looking for food..." << endl;
            int new_food = 0;
            string findfood;
            int r;
            r = rand() % 10;
            if(r == 1){
              cout << "Lucky you, you found 10 rations of food!" << endl;
              cout << "Enter anything to continue" << endl;
              cin >> findfood;
              new_food = 10;
              P1.status_rations(new_food);
            }
            else if(r >=2 && r <= 4){
              cout << "You found nothing" << endl;
              cout << "Enter anything to continue" << endl;
              cin >> findfood;
            }
            else if(r == 5){
              cout << "You wasted 1 day finding nothing..." << endl;
              cout << "and you used up 10 rations in the process next time learn to shoot properly!" << endl;
              cout << "Enter anything to continue" << endl;
              cin >> findfood;
              new_food = -10;
              //days++;
              P1.status_rations(new_food);             
            }
            checkpoint1 = 3;
          }
          if(checkpoint1 == 3){
            cout << "Come on! Lets get a move on! Theirs still a long ways to go!" << endl;
            cout << "Albert wants to get to Oregon and doesn't like the Kansas City Chiefs" << endl;
            break;
          }
          if(checkpoint1 != 1){
            cout << "Invaild input! Please Try Again" << endl;
            checkpoint1 = -1;
          }
          if(cin.fail()){
            string trash = " ";
            cin.clear();
            cin >> trash;
            cout << "Invaild input! Please Try Again" << endl;
            checkpoint1 = -1;
          }
        }

        //Fork in the road code for future
        int display_turns2 = 45;
        for(int first_checkpoint = 0; first_checkpoint < 11; ++first_checkpoint){

          cout << "-----------------=====+=====-----------------" << endl;
          cout << setw(display_turns2) <<"        _____ " << endl;
          cout << setw(display_turns2) <<"@(==)~_(_____)" << endl;
          cout << setw(display_turns2) <<" ^  ^   *   * " << endl;
          cout << "---------------------------------------------" << endl;
          cout << "Date: January " << days << " 1848" << endl;
          cout << "Weather: Freezing casue it's still winter in January!" << endl;
          cout << "Health: " << P1.get_health() << endl;
          cout << "Food: " << P1.get_hunger() << endl;
          cout << "Miles: "<< miles << endl;
          P1.status_health(disease());
          P1.status_health(event());
          cout << "-----------------=====+=====-----------------" << endl;

          miles += 25;
          display_turns2 -= 3;
          days = days + 3;
          int rations = -1;
          P1.status_rations(rations);
          this_thread::sleep_for(chrono::milliseconds(1000));
          if(dead(P1.get_health(), miles, P1.get_name()) == 1){
            return 0;
          }
        }
        total_day = total_day + days;
        days = 1;
        

        secondcheckpoint();
        int checkpoint2 = -1;
        while(checkpoint2 == -1){
          cin >> checkpoint2;
          if(checkpoint2 == 1){
            P1.get_status();
            cout << "Enter anything to return" << endl;
            string anything;
            cin >> anything;
            firstcheckpoint();
            checkpoint2 = -1;
          }
          if(checkpoint2 == 2){
            cout << "Looking for food..." << endl;
            int new_food = 0;
            string findfood;
            int r;
            r = rand() % 6;
            if(r == 1){
              cout << "Lucky you, you found 10 rations of food!" << endl;
              cout << "Enter anything to continue" << endl;
              cin >> findfood;
              new_food = 10;
              P1.status_rations(new_food);
            }
            else if(r >=2 && r <= 4){
              cout << "You found nothing" << endl;
              cout << "Enter anything to continue" << endl;
              cin >> findfood;
            }
            else if(r == 5){
              cout << "You wasted 1 day finding nothing..." << endl;
              cout << "and you used up 10 rations in the process next time learn to shoot properly!" << endl;
              cout << "Enter anything to continue" << endl;
              cin >> findfood;
              new_food = -10;
              //days++;
              P1.status_rations(new_food);             
            }
            checkpoint2 = 3;
          }
          if(checkpoint2 == 3){
            cout << "How are you still alive! Whatever lucky ig... lets get move on..." << endl;
            break;
          }
          if(checkpoint1 != 1){
            cout << "Invaild input! Please Try Again" << endl;
            checkpoint1 = -1;
          }
          if(cin.fail()){
            string trash = " ";
            cin.clear();
            cin >> trash;
            cout << "Invaild input! Please Try Again" << endl;
            checkpoint1 = -1;
          }
        }

        int display_turns3 = 45;
        for(int second_checkpoint = 0; second_checkpoint < 10; ++second_checkpoint){

          cout << "-----------------=====+=====-----------------" << endl;
          cout << setw(display_turns3) <<"        _____ " << endl;
          cout << setw(display_turns3) <<"@(==)~_(_____)" << endl;
          cout << setw(display_turns3) <<" ^  ^   *   * " << endl;
          cout << "---------------------------------------------" << endl;
          cout << "Date: February " << days << " 1848" << endl;
          cout << "Weather: Freezing casue it's still winter in January!" << endl;
          cout << "Health: " << P1.get_health() << endl;
          cout << "Food: " << P1.get_hunger() << endl;
          cout << "Miles: "<< miles << endl;
          P1.status_health(disease());
          P1.status_health(event());
          cout << "-----------------=====+=====-----------------" << endl;

          miles += 25;
          display_turns3 -= 3;
          days = days + 3;
          int rations = -1;
          P1.status_rations(rations);
          this_thread::sleep_for(chrono::milliseconds(1000));
          if(dead(P1.get_health(), miles, P1.get_name()) == 1){
            return 0;
          }
        }
        total_day = total_day + days;
        days = 1;
      }

      finish();
      return 0;

    }

    if(choice == 2){  //About the Trail
      cout << "---------====+====---------" << endl;
      cout << endl;
      cout << "So it's like uhhhhhhh 1848 ish" << endl;
      cout << "and your life is really mid. " << endl;
      cout << "So your gonna go to like Oergon or wherever..." << endl; 
      cout << "Idk someplace cool ig" << endl;
      cout << "and well planes don't exist yet" << endl;
      cout << "so like good luck walking their!" << endl;
      cout << endl;
      cout << "P.S. dont die of Dysentery" << endl;
      cout << endl;
      cout << "---------====+====---------" << endl;
    }
    if(choice == 3){
      return 0;
    }
    //main_menu();
  }

}