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
  while(game.checkForWinner() == false && game.board.size() != sizeof(validSpaces)/sizeof(string)) {
    game.round();
  };
  return 0;
}

void log(string message) {
  cout << message << endl;
}

void GameData::showBoard() {
  string row1;
  string row2;
  string row3;
  for(int i=0; i < board.size(); i++) {
    string val;
    if(board[i].player == player1) {
      val = "x";
    } else if (board[i].player == player2) {
      val = "o";
    } else {
      val = "_";
    }
    char s = board[i].space.at(0);
    if(s== 'A') {
      row1.append(val);
    } else if(s == 'B') {
      row2.append(val);
    } else {
      row3.append(val);
    }
  }
  log(row1);
  log(row2);
  log(row3);
}
GameData::GameData() {
  player1sTurn = true;
  log("Enter player 1's name");
  cin >> player1;
  log("Enter player 2's name");
  cin >> player2;
};


GameData::~GameData() {
  log("Game over! " + winner + " wins!!");
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
      log("Input is invalid. Please enter again.");
    }
  }

  space selection;
  selection.player = player1sTurn ? player1 : player2;
  selection.space = selectedSpace;

  if(player1sTurn) {
    player1sTurn = false;
  } else {
    player1sTurn = true;
  }

  board.push_back(selection);
  showBoard();
}

bool GameData::validateSpace(string space) {
  for(int i = 0; i < sizeof(validSpaces)/sizeof(string); i++) {
    if(space == validSpaces[i]) {
      for(int j = 0; j < board.size(); j++) {
        if(board[j].space == validSpaces[i]) {
          return false;
        }
      }
      return true;
    }
  }
  return false;
}

bool GameData::checkDiagnols(string player) {
  string diagonalWin1[] = {"A1, B2", "C3"};
  string diagonalWin2[] = {"A3", "B2", "C1"};
  int win1Count = 0;
  int win2Count = 0;
  for(int i=0; i<board.size(); i++) {
    if(board[i].player == player) {
      // checks if value exists in one of two diagnol win arrays;
      if(std::find(std::begin(diagonalWin1), std::end(diagonalWin1), board[i].space) != std::end(diagonalWin1) == true) {
        log("In here");
        win1Count++;
      }
      if(std::find(std::begin(diagonalWin2), std::end(diagonalWin2), board[i].space) != std::end(diagonalWin2) == true) {
        win2Count++;
      }
    }
    if(win1Count > 2 || win2Count > 2) {
      return true;
    }
  }

  return false;

}

bool GameData::checkForWinner() {
  // winning conditions.. 3 of any letter or number for rows and columns
  // Diagonals hard coded;

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
    bool isP1 = board[i].player == player1;

    switch(board[i].space.at(0)) {
      case 'A':
        isP1 ? p1.a++ : p2.a++;
        break;
      case 'B':
        isP1 ? p1.b++ : p2.b++;
        break;
      case 'C':
        isP1 ? p1.c++ : p2.c++;
        break;
    }

    switch(board[i].space.at(1)) {
      case '1':
        isP1 ? p1.one++ : p2.one++;
        break;
      case '2':
        isP1 ? p1.two++ : p2.two++;
        break;
      case '3':
        isP1 ? p1.three++ : p2.three++;
        break;
    }

    if(p1.a == 3 || p1.b == 3 || p1.c == 3 || p1.one == 3 || p1.two == 3 || p1.three == 3 || checkDiagnols(player1)) {

      winner = player1;
      return true;
    } else if(p2.a == 3 || p2.b == 3 || p2.c == 3 || p2.one == 3 || p2.two == 3 || p2.three == 3 || checkDiagnols(player2)) {
      winner = player2;
      return true;
    }
  }
  return false;
}