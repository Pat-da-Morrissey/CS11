#include <iostream>


using namespace std;


int main(){

  int number;
  cin >> number;
  const double ZIPCODE = number;

// Variables for all of the digits in the zip code
  int digit1; 
  int digit2;
  int digit3;
  int digit4;
  int digit5;

//Variables for all of the bar weights

  int seven = 0;
  int four = 0;
  int two = 0;
  int one = 0;
  int zero = 0;

// remainder for math conversion during the bar weights
  double r1 = 0; 
  double r2 = 0; 
  double r3 = 0; 
  double r4 = 0;
  double r5 = 0; 

//Getting the first digit
  while(number >= 0){
      digit1 = number / 10000;
      number = -1;
  }
  while(number >= 0){
      digit1 = number / 10000;
      number = -1;
  }


    if(digit1 > 4){
        r2 = digit1 - 4;
        digit1 - 4;
    }
    if(digit1 > 2){
        r3 = digit1 - 2;
        digit1 - 2;
    }
    if(digit1 > 1){
        r4 = digit1 - 1;
        digit1 - 1;
    }





  cout << digit1 << endl << ZIPCODE << endl;

  while(digit1 > 0){
    if(digit1 > 7){
        r1 = digit1 - 7;
        digit1 - 7;    
    }
    digit1 = -1;
  }
  
  cout << r1 << r2 << r3 << r4;


  if(cin.fail()){  // In case of a failure
    cout << "Enter a real number!" << endl;
    cin.clear();

    string garbage;  // Clears the buffer
    cin >> garbage;

  }




  return 0;
}