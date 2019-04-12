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

int main() {
  GameData game;
  game.round();
  return 0;
}

void log(string message) {
  cout << message << endl;
}

GameData::GameData() {
  log("Enter player 1's name");
  cin >> player1;
  log("Enter player 2's name");
  cin >> player2;

  player1sTurn = true;
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

  cin >> selectedSpace;

  space selection;
  selection.player = player1sTurn ? player1 : player2;
  selection.space = selectedSpace;

  board.push_back(selection);
  cout << board.size() << endl;
}