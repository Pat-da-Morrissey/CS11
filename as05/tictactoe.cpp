#include <iostream>
#include "tictactoe.h"

using namespace std;


TicTacToe::TicTacToe(){
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j)
    board[i][j] = 0;
  }
}

void TicTacToe::play(){
  int board[3][3]={{0}};
  int player = 1;
  int row, column, result;
  bool legalMove;

  drawBoard();
  while (!isGameOver(board)) {
    cout << "Player " << player << "(" << sigil[player] << "), your move?";
    cin >> row >> column;

    legalMove = isMoveLegal(row, column);
    while (!legalMove) {
      cout << "Player " << player << "(" << sigil[player] << "), your move?";
      cin >> row >> column;
      legalMove = isMoveLegal(row, column);
    }
    board[row][column] = player;
    drawBoard();
    player = 3 - player;
  }
    // Game over.
    result = winner(board);
    if (result == 0) {
        cout << "Tie Game" << endl;
    } else {
        cout << "Player " << result << "(" << sigil[result]
             << ") wins!" << endl;
    }


}

void TicTacToe::drawBoard(){
  int Row = 3;
  int Column = 3;
  cout << endl << "  0 1 2" << endl;
  for(int i = 0; i < Row ; ++i){
    cout << i << " ";
    for(int j = 0; j < Column; ++j){
        cout << sigil[board[i][j]] << " ";
    }
    cout << endl;
  }
}

bool TicTacToe::isMoveLegal(int row, int column){
  if(row > 2  || row < 0 || column > 2 || column < 0){
    cout << "Error Out of Bounds! Please Try Again" << endl;
    return false;
  }
  
  if(board[row][column] != 0){
    cout << "Error Spot Already Taken! Please Try Again" << endl;
    return false;
  }

  if(cin.fail()){
    string trash = " ";
    cin.clear();
    cin >> trash;
    cout << "Invaild input! Please Try Again" << endl;
    return false;
  }

    return true;
}


int TicTacToe::winner(int board[3][3]){
  for (int i = 0; i < 3; ++i){  //Wins Horizontally
    if(board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1){
      return 1;
    }
  }
  for (int i = 0; i < 3; ++i){  //Wins Vertiacally
    if(board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1){
      return 1;
    }
  }
  if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1){  //Wins Diagonally
    return 1;
  }
  if(board[2][0] == 1 && board[1][1] == 1 && board[0][2] == 1){  //Wins Diagonally
    return 1;
  }

  //Player 2
  for (int i = 0; i < 3; ++i){  //Wins Horizontally
    if(board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2){
        return 2;
      }
    }
    for (int i = 0; i < 3; ++i){ //Wins Vertically 
      if(board[0][i] == 2 && board[1][i] == 2 && board[2][i] == 2){
        return 2;
      }
    }
    if(board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2){  
      return 2;
    }
    if(board[2][0] == 2 && board[1][1] == 2 && board[0][2] == 2){  //Wins Diagonally
      return 2;
    }
        
    return 0;

}

bool TicTacToe::isGameOver(int board[3][3]){
  
  if (winner(board) == 1 || winner(board) == 2)
      return true;

  for (int r = 0; r <= 2; r++){
    for (int c = 0; c <= 2; c++){
        if (board[r][c] == 0){
          return false;
        }
    }
  }
  
  return true;

} 


int main(){
  TicTacToe game;
  game.play();

  return 0;
}