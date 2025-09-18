#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  double gallon_of_gas;
  double miles_per_gallon;
  double miles_per_trip;

  cout << "What is the cost of a gallon of gas?" << endl; // Cost of gas
  cin >> gallon_of_gas;

  cout << "What is your cars mile per gallon?" << endl; // Miles per gallon
  cin >> miles_per_gallon;

  cout << "How long was you drive today?" << endl; // Miles per trip
  cin >> miles_per_trip;

  cout << "A gallon of gas cost: $" << fixed << setprecision(2) << setw(3) << gallon_of_gas << endl;  // Outputs
  cout << "Miles per gallon is: " << fixed << setprecision(2) << setw(6) << miles_per_gallon << endl;
  cout << "Your trip was " << miles_per_trip << " miles" << endl;
  cout << "Your trip costs $" << gallon_of_gas * (miles_per_trip / miles_per_gallon);

  return 0;
}

/* Code using a function

double price_of_trip(double price, double distance, double efficency){


  return price * (distance / efficency);
}


int main(){

  double gas_price;
  cin >> gas_price;

  double mpg;
  cin >> mpg;

  double distance;
  cin >> distance;

  double total_price = price_of_trip(gas_price, distance, mpg);
  cout << fixed << setprecision(2) << total_price;

 return 0;
}
*/