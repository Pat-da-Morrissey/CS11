#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main (){
//Income
  double taxes;
  double income;
  cout << "What is your income?" << endl;
  cin >> income;


 
// Income Bracket Types
  double A = 50000;
  double B = 25000;
  double C = 25000; 
  double D = 150000;
  double E = 250000;
  double F = 500000;

//Full Tax Payment for each income bracket
  double a = 500;
  double b = 500;
  double c = 750; 
  double d = 6000;
  double e = 12500;
  double f = 500000;


  double Tax_money;
  
  if(income < 50000){ // A Bracket
  taxes = income * 0.01; 
  }
  else if(income >= 50000 && income < 75000){ // B Bracket
  Tax_money = income - A;
  taxes = Tax_money * 0.02;
  taxes = taxes + a;
  }
  else if(income >= 75000 && income < 100000 ){ // C Bracket
  Tax_money = income - (A+B);
  taxes = Tax_money * 0.03;
  taxes = taxes + a + b; 
  }
  else if(income >= 100000 && income < 250000 ){ // D Bracket 
  Tax_money = income - (A+B+C);
  taxes = Tax_money * 0.04;
  taxes = taxes + (a + b + c); 
  }
  else if(income >= 250000 && income < 500000 ){ // E Bracket
  Tax_money = income - (A+B+C+D);
  taxes = Tax_money * 0.05;
  taxes = taxes + (a + b + c + d); 
  }
  else if(income >= 500000){ // F Bracket
  Tax_money = income - (A+B+C+D+E);
  taxes = Tax_money * 0.06;
  taxes = taxes + (a + b + c + d + e); 
  }

  cout << "Your owe $" <<fixed << setprecision(2) << taxes << " to the IRS";

  return 0;

}