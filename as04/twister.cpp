#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

/*
The purpose of this program is when ran to input in a word, words, or series of letters given by the user.
If the input has 4+ letter, the code will scramble two random letters around within in the middle and output the new word
*/


string scrambler(string cut_word){  //The new chopped input gets scrambled here

  int cutlength1 = cut_word.length();
  int picky1 = rand() % cutlength1;
  int cutlength2 = cut_word.length();
  int picky2 = rand() % cutlength2;

  //Makes sure the random letter chosen arent the same
  while(picky1 == picky2) {
      picky1 = rand() % cutlength1;
  }

  //The chopped word gets swapped here
  char temp = cut_word[picky1];
  cut_word[picky1] = cut_word[picky2];
  cut_word[picky2] = temp;

  return cut_word;
}

string twist(string word){  //The input loses it's frist and last letter, gets scrambled, and returns and adds the first and last letter 

  if(word.length() < 4) {
    return word; 
  }
  else{
    string middle_letters = word.substr(1, word.length() - 2);
    return word.substr(0, 1) + scrambler(middle_letters) + word.substr(word.length() - 1, 1);
  }

}

int main(){
  srand(time(0));
  string input;
  
  while (cin >> input){
    cout << twist(input) << endl;
  }
    
  return 0;
}