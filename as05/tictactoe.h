#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>

using namespace std;


class TicTacToe {
    public:
      TicTacToe();
      void play();

    private:
      char sigil[3] = {'.', 'X', 'O'};
      int board[3][3];

      void drawBoard();
      bool isMoveLegal(int row, int column);
      int winner(int board[3][3]);
      bool isGameOver(int board[3][3]);
};

#endif