#include <iostream>
#include <string>

using namespace std;

int main(){
  int zip;
  cout << "Please enter you zip code: " << endl;
  cin >> zip;
  int sum = 0;

  //Barcode variables
  string Barcode = "";
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

  // Variables for the digits
  int digit1; 
  int digit2;
  int digit3;
  int digit4;
  int digit5;

  while (zip > 0){
    int digit = zip % 10;  //Splits up the zip code into individual digits
    sum += digit;          //Calculates the sum of all of the individual digits
    zip = zip / 10;

    if (digit == 0) {
      Barcode = Bar0 + Barcode;
    }
    else if (digit == 1){
    Barcode = Bar1 + Barcode;
    }
    else if (digit == 2){
      Barcode = Bar2 + Barcode;
    }
    else if (digit == 3){
      Barcode = Bar3 + Barcode;
    }
    else if (digit == 4){
      Barcode = Bar4 + Barcode;
    }
    else if (digit == 5){
      Barcode = Bar5 + Barcode;
    }
    else if (digit == 6){
      Barcode = Bar6 + Barcode;
    }
    else if (digit == 7){
      Barcode = Bar7 + Barcode;
    }
    else if (digit == 8){
      Barcode = Bar8 + Barcode;
    }
    else if (digit == 9){
      Barcode = Bar9 + Barcode;
    }
    else if (digit == 0){
      Barcode = Bar0 + Barcode;
    }
       
  }
  
  int check_digit = (10 - (sum % 10)) % 10;  //Check digit part it is calculated and substracted by 10 within the check digit variable

  if (check_digit == 1){
    Barcode = Barcode + Bar1;
  }
  else if (check_digit == 2){
    Barcode = Barcode + Bar2;
  }
  else if (check_digit == 3){
    Barcode = Barcode + Bar3;
   }
  else if (check_digit == 4){
    Barcode = Barcode + Bar4;
  }
  else if (check_digit == 5){
    Barcode = Barcode + Bar5;
  }
  else if (check_digit == 6){
    Barcode = Barcode + Bar6;
  }
  else if (check_digit == 7){
    Barcode = Barcode + Bar7;
  }
  else if (check_digit == 8){
    Barcode = Barcode + Bar8;
  }
  else if (check_digit == 9){
    Barcode = Barcode + Bar9;
  }
  else if (check_digit == 0){
    Barcode = Barcode + Bar0;
  }

  cout << "|" << Barcode << "|" << endl;

}