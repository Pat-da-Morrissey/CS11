#include <iostream>
#include <string>

using namespace std;


int main(){

  //Start
  string zipcode;
  cout << "Please Enter Your Zip Code" << endl;
  cin >> zipcode;


  //Check digit varibales
  double Digitchk1;
  double Digitchk2;
  double Digitchk3;
  double Digitchk4;
  double Digitchk5;

  //Digits
  string Digit1;
  string Digit2;
  string Digit3;
  string Digit4;
  string Digit5;
  string Digit6;


  //Variable for the conversion 
  string Converstion = "";
  double Check;

  //Barcode conversion from number to zip
  string Bar1 = ":::||";
  string Bar2 = "::|:|";
  string Bar3 = "::||:";
  string Bar4 = ":|::|";
  string Bar5 = ":|:|:";
  string Bar6 = ":||::";
  string Bar7 = "|:::|";
  string Bar8 = "|::|:";
  string Bar9 = "|:|::";
  string Bar0 = "||:::";


  for(int i = 0; i <= zipcode.length(); i++){ // Code for the converstion // 5
      // cout << i << endl;
    if(i == 1){  //Breaking up the code into seperate digit 
      Digit1 = Converstion;
      Digitchk1 = Check;
    }
    else if(i == 2){
      Digit2 = Converstion;
      Digitchk2 = Check;
    }
    else if(i == 3){
      Digit3 = Converstion;
      Digitchk3 = Check;
    }
    else if(i == 4){
      Digit4 = Converstion;
      Digitchk4 = Check;
    }
    else if(i == 5){
      Digit5 = Converstion;
      Digitchk5 = Check;
    }

    if(zipcode.substr(i,1) == "9"){  //Checking each digit
      Converstion = Bar9;
      Check = 9;
    }
    else if(zipcode.substr(i,1) == "8"){
      Converstion = Bar8;
      Check = 8;
    }
    else if(zipcode.substr(i,1) == "7"){
      Converstion = Bar7;
      Check = 7;
    }
    else if(zipcode.substr(i,1) == "6"){
      Converstion = Bar6;
      Check = 6;
    }
    else if(zipcode.substr(i,1) == "5"){
      Converstion = Bar5;
      Check = 5;
    }
    else if(zipcode.substr(i,1) == "4"){
      Converstion = Bar4;
      Check = 4;
    }
    else if(zipcode.substr(i,1) == "3"){
      Converstion = Bar3;
      Check = 3;
    }
    else if(zipcode.substr(i,1) == "2"){
      Converstion = Bar2;
      Check = 2;
    }
    else if(zipcode.substr(i,1) == "1"){
      Converstion = Bar1;
      Check = 1;
    }
    else if(zipcode.substr(i,1) == "0"){
      Converstion = Bar0;
      Check = 0;
    }

  }
  
  double Zipvalue = Digitchk1 + Digitchk2 + Digitchk3 + Digitchk4 + Digitchk5; //Check digit
  
  if(Zipvalue > 40){
    Zipvalue = 50 - Zipvalue;
  }
  else if(Zipvalue > 30){
    Zipvalue = 40 - Zipvalue;
  }
  else if(Zipvalue > 20){
  Zipvalue = 30 - Zipvalue;
  }
  else if(Zipvalue > 10){
  Zipvalue = 20 - Zipvalue;
  }

  // cout << Zipvalue << endl;

  if (Zipvalue == 0){
      Digit6 = Bar0;
  }
  else if(Zipvalue == 1){
      Digit6 = Bar1;
  }
  else if(Zipvalue == 2){
      Digit6 = Bar2;
  }
  else if(Zipvalue == 3){
      Digit6 = Bar3;
  }
  else if(Zipvalue == 4){
      Digit6 = Bar4;
  }
  else if(Zipvalue == 5){
      Digit6 = Bar5;
  }
  else if(Zipvalue == 6){
      Digit6 = Bar6;
  }
  else if(Zipvalue == 7){
      Digit6 = Bar7;
  }
  else if(Zipvalue == 8){
      Digit6 = Bar8;
  }
  else if(Zipvalue == 9){
      Digit6 = Bar9;
  }

  // cout << Digit6 << endl;

  cout << "|" << Digit1 + Digit2 + Digit3 + Digit4 + Digit5 + Digit6 << "|";  //Result
  // cout << "Digit 1 is: " << Digit1 << endl;
  // cout << "Digit 2 is: " << Digit2 << endl;
  // cout << "Digit 3 is: " << Digit3 << endl;
  // cout << "Digit 4 is: " << Digit4 << endl;
  // cout << "Digit 5 is: " << Digit5 << endl;
  // cout << "Digit 6 is: " << Digit6 << endl;


  return 0;
}