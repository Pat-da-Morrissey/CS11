// Starter code for Assignment #5, tictactoe.cpp
#include <iostream>

using namespace std;


/*
The purpose of this code is to run a game of tic tac toe played by two players alternating turns
*/

const char SIGIL[3]={'.', 'X', 'O'};

// Function Prototypes.
void drawBoard(int board[3][3]);
bool isMoveLegal(int board[3][3], int row, int column);
int winner(int board[3][3]);
bool isGameOver(int board[3][3]);



void drawBoard(int board[3][3]) {
  int Row = 3;
  int Column = 3;
  cout << endl << "  0 1 2" << endl;
  for(int i = 0; i < Row ; ++i){
    cout << i << " ";
    for(int j = 0; j < Column; ++j){
        cout << SIGIL[board[i][j]] << " ";
    }
    cout << endl;
  }
}


bool isMoveLegal(int board[3][3], int row, int column) {
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


int winner(int board[3][3]) {
  //Player 1
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

bool isGameOver(int board[3][3]) {
    if (winner(board) == 1 || winner(board) == 2)
        return true;

    for (int r = 0; r <= 2; r++)
        for (int c = 0; c <= 2; c++)
            if (board[r][c] == 0)
                return false;
  
    return true;
}


int main() {
    // Initialize board to all 0.
    // It will later be filled in with 1 or 2 for taken squares.
    int board[3][3]={{0}};
    int player = 1;
    int row, column, result;
    bool legalMove;

    // Start game.
    drawBoard(board);
    while (!isGameOver(board)) {
        cout << "Player " << player << "(" << SIGIL[player]
             << "), your move?";
        cin >> row >> column;

        legalMove = isMoveLegal(board, row, column);
        while (!legalMove) {
            cout << "Player " << player << "(" << SIGIL[player]
                 << "), your move?";
            cin >> row >> column;
            legalMove = isMoveLegal(board, row, column);
        }
        board[row][column] = player;
        drawBoard(board);
        player = 3 - player;
    }
    // Game over.
    result = winner(board);
    if (result == 0) {
        cout << "Tie Game" << endl;
    } else {
        cout << "Player " << result << "(" << SIGIL[result]
             << ") wins!" << endl;
    }

    return 0;
}

