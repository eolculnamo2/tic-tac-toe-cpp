#include <iostream>
#include "GameData.hpp"
using namespace std;

/*
    1 2 3
  A
  B
  C

  A1, B2, C3 = win; for example.
*/
string validSpaces[] = { "A1", "B1", "C1", "A2", "B2", "C2", "A3", "B3", "C3" };
int main() {
  GameData game;
  game.round();
  game.checkForWinner();
  return 0;
}

void log(string message) {
  cout << message << endl;
}

GameData::GameData() {
  player1sTurn = true;
  log("Enter player 1's name");
  cin >> player1;
  log("Enter player 2's name");
  cin >> player2;
};


GameData::~GameData() {
  log("Game over!");
};

void GameData::round() {
  string selectedSpace;

  if(player1sTurn) {
    log(player1 + ", select your next space.");
  } else {
    log(player2 + ", select your next space.");
  }

  while(validateSpace(selectedSpace) == false) {
    cin >> selectedSpace;
    if(validateSpace(selectedSpace) == false) {
      log("Input is invalid. Please entre again.");
    }
  }

  space selection;
  selection.player = player1sTurn ? player1 : player2;
  selection.space = selectedSpace;

  board.push_back(selection);
}

bool GameData::validateSpace(string space) {
  for(int i = 0; i < sizeof(validSpaces)/sizeof(string); i++) {
    if(space == validSpaces[i]) {
      return true;
    }
  }
  return false;
}

bool GameData::checkForWinner() {
  // winning conditions.. 3 of any letter or number for rows and columns
  // Diagonals hard coded;
  string diagonalWin1[] = {"A1, B2", "C3"};
  string diagonalWin2[] = {"A3", "B2", "C1"};

  // counts to check above conditions of three of any;
  struct playerCount {
    int a = 0;
    int b = 0;
    int c = 0;
    int one = 0;
    int two = 0;
    int three = 0;
  };

  playerCount p1;
  playerCount p2;


  for(int i = 0; i < board.size(); i++) {
    switch(board[i].space.at(0)) {
      case 'A':
        p1.a++;
        break;

    }
  }
  return true;
}